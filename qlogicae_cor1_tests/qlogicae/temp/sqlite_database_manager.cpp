#include "pch.hpp"

#include "../includes/sqlite_database_manager.hpp"

namespace
	QLogicae::Cor::V1::Tests
{
    class SQLiteDatabaseManagerTest :
        public ::testing::Test
    {
    public:
        SQLiteDatabaseManagerTest()
        {
            test_file_path =
                std::filesystem::temp_directory_path()
                / "sqlite_database_manager_test.db";

			std::filesystem::create_directories(test_file_path.parent_path());

            manager =
                std::make_unique<SQLiteDatabaseManager>();

			manager->configurations.file_path =
				test_file_path.string();
        }

        ~SQLiteDatabaseManagerTest()
        {
            manager.reset();
            std::filesystem::remove(test_file_path);
        }

        std::unique_ptr<SQLiteDatabaseManager>
            manager;

        std::filesystem::path
            test_file_path;
    };

    TEST_F(SQLiteDatabaseManagerTest,
        Should_ConstructAndDestructSuccessfully_When_Called)
    {
        EXPECT_TRUE(manager->construct());
        EXPECT_TRUE(manager->destruct());
    }

    TEST_F(SQLiteDatabaseManagerTest,
        Should_SetupStatementSuccessfully_When_ValidSQL)
    {
        auto statement =
            manager->setup_statement("CREATE TABLE IF NOT EXISTS test(id INTEGER PRIMARY KEY);");
        EXPECT_TRUE(statement.is_valid());
    }

    TEST_F(SQLiteDatabaseManagerTest,
        Should_ThrowSQLiteException_When_InvalidSQL)
    {
        EXPECT_THROW(
            manager->setup_statement("INVALID SQL;"),
            SQLiteException
        );
    }

    TEST_F(SQLiteDatabaseManagerTest,
        Should_InsertAndReturnLastRowId_When_RowInserted)
    {
        auto create_table =
            manager->setup_statement("CREATE TABLE IF NOT EXISTS test(id INTEGER PRIMARY KEY);");
        create_table.step();

        auto insert_statement =
            manager->setup_statement("INSERT INTO test DEFAULT VALUES;");
        insert_statement.step();

        int64_t last_id =
            manager->last_insert_rowid();

        EXPECT_GT(last_id, 0);
    }

    TEST_F(SQLiteDatabaseManagerTest,
        Should_BindParametersSuccessfully_When_UsingSQLiteStatement)
    {
        auto create_table =
            manager->setup_statement("CREATE TABLE IF NOT EXISTS test_param(id INTEGER PRIMARY KEY, value TEXT);");
        create_table.step();

        auto insert_statement =
            manager->setup_statement("INSERT INTO test_param(value) VALUES(?1);");
        insert_statement.bind(1, std::string("test_value"));
        EXPECT_TRUE(insert_statement.step());
    }

    TEST_F(SQLiteDatabaseManagerTest,
        Should_HandleAsyncExecution_When_MultipleInserts)
    {
        auto create_table =
            manager->setup_statement("CREATE TABLE IF NOT EXISTS test_async(id INTEGER PRIMARY KEY, value TEXT);");
        create_table.step();

        std::vector<std::future<void>> futures;

        for (int i = 0; i < 10; ++i)
        {
            futures.push_back(std::async(
                std::launch::async,
                [this, i]()
                {
                    auto statement =
                        manager->setup_statement("INSERT INTO test_async(value) VALUES(?1);");
                    statement.bind(1, "value_" + std::to_string(i));
                    statement.step();
                }
            ));
        }

        for (auto& future : futures)
        {
            future.get();
        }

        auto count_statement =
            manager->setup_statement("SELECT COUNT(*) FROM test_async;");
        count_statement.step();
        auto row = count_statement.row().value();
        EXPECT_EQ(row.get<int>(0), 10);
    }

    TEST_F(SQLiteDatabaseManagerTest,
        Should_HandleMultithreadedInserts_When_UsingThreads)
    {
        auto create_table =
            manager->setup_statement("CREATE TABLE IF NOT EXISTS test_thread(id INTEGER PRIMARY KEY, value TEXT);");
        create_table.step();

        std::vector<std::thread> threads;

        for (int i = 0; i < 10; ++i)
        {
            threads.emplace_back(
                [this, i]()
                {
                    auto statement =
                        manager->setup_statement("INSERT INTO test_thread(value) VALUES(?1);");
                    statement.bind(1, "thread_" + std::to_string(i));
                    statement.step();
                }
            );
        }

        for (auto& thread : threads)
        {
            thread.join();
        }

        auto count_statement =
            manager->setup_statement("SELECT COUNT(*) FROM test_thread;");
        count_statement.step();
        auto row = count_statement.row().value();
        EXPECT_EQ(row.get<int>(0), 10);
    }

    TEST_F(SQLiteDatabaseManagerTest,
        Should_RollbackTransaction_When_NotCommitted)
    {
        auto create_table =
            manager->setup_statement("CREATE TABLE IF NOT EXISTS test_tx(id INTEGER PRIMARY KEY);");
        create_table.step();

        {
            SQLiteTransaction transaction(*manager);
            auto insert_statement =
                manager->setup_statement("INSERT INTO test_tx DEFAULT VALUES;");
            insert_statement.step();
        }

        auto count_statement =
            manager->setup_statement("SELECT COUNT(*) FROM test_tx;");
        count_statement.step();
        auto row = count_statement.row().value();
        EXPECT_EQ(row.get<int>(0), 0);
    }

    TEST_F(SQLiteDatabaseManagerTest,
        Should_CommitTransaction_When_Called)
    {
        auto create_table =
            manager->setup_statement("CREATE TABLE IF NOT EXISTS test_tx_commit(id INTEGER PRIMARY KEY);");
        create_table.step();

        {
            SQLiteTransaction transaction(*manager);
            auto insert_statement =
                manager->setup_statement("INSERT INTO test_tx_commit DEFAULT VALUES;");
            insert_statement.step();
            EXPECT_TRUE(transaction.commit());
        }

        auto count_statement =
            manager->setup_statement("SELECT COUNT(*) FROM test_tx_commit;");
        count_statement.step();
        auto row = count_statement.row().value();
        EXPECT_EQ(row.get<int>(0), 1);
    }

    class SQLiteDatabaseManagerParameterizedTest :
        public SQLiteDatabaseManagerTest,
        public ::testing::WithParamInterface<std::string>
    {
    };

    INSTANTIATE_TEST_CASE_P(
        ParameterizedSQLTests,
        SQLiteDatabaseManagerParameterizedTest,
        ::testing::Values(
            "CREATE TABLE IF NOT EXISTS test_param1(id INTEGER);",
            "CREATE TABLE IF NOT EXISTS test_param2(id INTEGER, value TEXT);",
            ""
        )
    );

    TEST_P(SQLiteDatabaseManagerParameterizedTest,
        Should_HandleParameterizedSQL_When_ValidAndEmptySQL)
    {
        auto sql_text = GetParam();

        if (sql_text.empty())
        {
            EXPECT_THROW(
                manager->setup_statement(sql_text),
                SQLiteException
            );
        }
        else
        {
            auto statement = manager->setup_statement(sql_text);
            EXPECT_TRUE(statement.is_valid());
        }
    }

    TEST_F(SQLiteDatabaseManagerTest,
        Should_CompleteStressTestUnderConcurrency_When_100Iterations)
    {
        auto create_table =
            manager->setup_statement("CREATE TABLE IF NOT EXISTS test_stress(id INTEGER PRIMARY KEY, value TEXT);");
        create_table.step();

        std::atomic<int> completed_count = 0;
        auto start_time = std::chrono::steady_clock::now();

        std::vector<std::thread> threads;

        for (int i = 0; i < 100; ++i)
        {
            threads.emplace_back(
                [this, &completed_count, i]()
                {
                    auto statement =
                        manager->setup_statement("INSERT INTO test_stress(value) VALUES(?1);");
                    statement.bind(1, "stress_" + std::to_string(i));
                    statement.step();
                    ++completed_count;
                }
            );
        }

        for (auto& thread : threads)
        {
            thread.join();
        }

        auto end_time = std::chrono::steady_clock::now();
        auto duration_ms =
            std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time)
            .count();

        EXPECT_EQ(completed_count, 100);
        EXPECT_LT(duration_ms, 2000);
    }
}