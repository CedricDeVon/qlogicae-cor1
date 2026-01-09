#include "pch.hpp"

#include "../includes/asynchronous_manager.hpp"

namespace QLogicaeCppCoreTest
{
    class AsynchronousManagerTest :
        public ::testing::Test
    {
    public:
        AsynchronousManagerTest()
        {
            QLogicaeCppCore::AsynchronousManagerUtilities::singleton
                .reset();

            QLogicaeCppCore::AsynchronousManager::singleton
                .reset();
        }

        ~AsynchronousManagerTest() override
        {
            QLogicaeCppCore::AsynchronousManagerUtilities::singleton
                .reset();

            QLogicaeCppCore::AsynchronousManager::singleton
                .reset();
        }
    };

    class AsynchronousManagerConfigurationTest :
        public ::testing::TestWithParam<bool>
    {
    };

    TEST(
        AsynchronousManagerTest,
        Should_ConstructSuccessfully_When_Initialized
    )
    {
        bool result =
            QLogicaeCppCore::AsynchronousManager::singleton
            .construct();

        ASSERT_TRUE(result);
    }

    TEST(
        AsynchronousManagerTest,
        Should_ResetToInitialState_When_ResetCalled
    )
    {
        QLogicaeCppCore::AsynchronousManagerConfigurations
            configurations;

        configurations.is_enabled =
            false;

        QLogicaeCppCore::AsynchronousManager::singleton
            .setup(configurations);

        bool reset_result =
            QLogicaeCppCore::AsynchronousManager::singleton
            .reset();

        ASSERT_TRUE(reset_result);

        ASSERT_TRUE(
            QLogicaeCppCore::AsynchronousManagerConfigurations::cache_is_enabled
        );
    }

    TEST(
        AsynchronousManagerTest,
        Should_NotDispatchTask_When_Disabled
    )
    {
        QLogicaeCppCore::AsynchronousManagerConfigurations
            configurations;

        configurations.is_enabled =
            false;

        QLogicaeCppCore::AsynchronousManager::singleton
            .setup(configurations);

        std::atomic<bool>
            executed(false);

        bool begin_result =
            QLogicaeCppCore::AsynchronousManager::singleton
            .begin_one_thread(
                [&executed]()
                {
                    executed.store(true);
                }
            );

        ASSERT_FALSE(begin_result);
        ASSERT_FALSE(executed.load());
    }

    TEST(
        AsynchronousManagerTest,
        Should_DispatchTask_When_Enabled
    )
    {
        QLogicaeCppCore::AsynchronousManagerConfigurations
            configurations;

        configurations.is_enabled =
            true;

        QLogicaeCppCore::AsynchronousManager::singleton
            .setup(configurations);

        std::promise<void>
            completion_promise;

        std::future<void>
            completion_future =
            completion_promise.get_future();

        bool begin_result =
            QLogicaeCppCore::AsynchronousManager::singleton
            .begin_one_thread(
                [&completion_promise]()
                {
                    completion_promise.set_value();
                }
            );

        ASSERT_TRUE(begin_result);

        auto wait_status =
            completion_future.wait_for(
                std::chrono::seconds(2)
            );

        ASSERT_EQ(
            wait_status,
            std::future_status::ready
        );
    }

    TEST(
        AsynchronousManagerTest,
        Should_HandleMultipleThreads_When_HighConcurrency
    )
    {
        QLogicaeCppCore::AsynchronousManagerConfigurations
            configurations;

        configurations.is_enabled =
            true;

        QLogicaeCppCore::AsynchronousManager::singleton
            .setup(configurations);

        std::atomic<int>
            execution_count(0);

        int const TASK_COUNT =
            1000;

        for (int index = 0;
            index < TASK_COUNT;
            index++)
        {
            QLogicaeCppCore::AsynchronousManager::singleton
                .begin_one_thread(
                    [&execution_count]()
                    {
                        execution_count.fetch_add(1);
                    }
                );
        }

        QLogicaeCppCore::AsynchronousManagerUtilities::singleton
            .complete_all_threads();

        ASSERT_EQ(
            execution_count.load(),
            TASK_COUNT
        );
    }

    TEST(
        AsynchronousManagerTest,
        Should_BeThreadSafe_When_CalledFromMultipleThreads
    )
    {
        QLogicaeCppCore::AsynchronousManagerConfigurations
            configurations;

        configurations.is_enabled =
            true;

        QLogicaeCppCore::AsynchronousManager::singleton
            .setup(configurations);

        std::atomic<int>
            execution_count(0);

        std::vector<std::thread>
            threads;

        for (int index = 0;
            index < 8;
            index++)
        {
            threads.emplace_back(
                [&execution_count]()
                {
                    for (int inner_index = 0;
                        inner_index < 100;
                        inner_index++)
                    {
                        QLogicaeCppCore::AsynchronousManager::singleton
                            .begin_one_thread(
                                [&execution_count]()
                                {
                                    execution_count.fetch_add(1);
                                }
                            );
                    }
                }
            );
        }

        for (auto& thread_instance : threads)
        {
            thread_instance.join();
        }

        QLogicaeCppCore::AsynchronousManagerUtilities::singleton
            .complete_all_threads();

        ASSERT_EQ(
            execution_count.load(),
            800
        );
    }

    TEST_P(
        AsynchronousManagerConfigurationTest,
        Should_RespectConfigurationValue_When_SetupCalled
    )
    {
        QLogicaeCppCore::AsynchronousManagerConfigurations
            configurations;

        configurations.is_enabled =
            GetParam();

        QLogicaeCppCore::AsynchronousManager::singleton
            .setup(configurations);

        ASSERT_EQ(
            QLogicaeCppCore::AsynchronousManagerConfigurations::cache_is_enabled,
            GetParam()
        );
    }

    INSTANTIATE_TEST_CASE_P(
        ConfigurationValues,
        AsynchronousManagerConfigurationTest,
        ::testing::Values(
            true,
            false
        )
    );

    TEST(
        AsynchronousManagerTest,
        Should_CompleteWithinTimeLimit_When_UnderLoad
    )
    {
        auto start_time =
            std::chrono::steady_clock::now();

        QLogicaeCppCore::AsynchronousManagerConfigurations
            configurations;

        configurations.is_enabled =
            true;

        QLogicaeCppCore::AsynchronousManager::singleton
            .setup(configurations);

        for (int index = 0;
            index < 5000;
            index++)
        {
            QLogicaeCppCore::AsynchronousManager::singleton
                .begin_one_thread(
                    []()
                    {
                    }
                );
        }

        QLogicaeCppCore::AsynchronousManagerUtilities::singleton
            .complete_all_threads();

        auto end_time =
            std::chrono::steady_clock::now();

        auto duration =
            std::chrono::duration_cast<
            std::chrono::milliseconds
            >(end_time - start_time);

        ASSERT_LT(
            duration.count(),
            2000
        );
    }

    TEST(
        AsynchronousManagerTest,
        Should_CallSetupDefaultOverload_When_NoArgumentsProvided
    )
    {
        bool result =
            QLogicaeCppCore::AsynchronousManager::singleton
            .setup();

        ASSERT_TRUE(result);
    }

    TEST(
        AsynchronousManagerTest,
        Should_CallDestructSuccessfully_When_InvokedExplicitly
    )
    {
        bool result =
            QLogicaeCppCore::AsynchronousManager::singleton
            .destruct();

        ASSERT_TRUE(result);
    }

    TEST(
        AsynchronousManagerTest,
        Should_CatchException_When_CallbackThrows
    )
    {
        QLogicaeCppCore::AsynchronousManagerConfigurations
            configurations;

        configurations.is_enabled =
            true;

        QLogicaeCppCore::AsynchronousManager::singleton
            .setup(configurations);

        bool result =
            QLogicaeCppCore::AsynchronousManager::singleton
            .begin_one_thread(
                []()
                {
                    throw std::runtime_error(
                        "forced_exception"
                    );
                }
            );

        ASSERT_TRUE(result);

        QLogicaeCppCore::AsynchronousManagerUtilities::singleton
            .complete_all_threads();
    }

    TEST(
        AsynchronousManagerTest,
        Should_HandleConcurrentResetAndSetup_When_MutatedSimultaneously
    )
    {
        std::atomic<bool>
            stop_flag(false);

        std::thread
            setup_thread(
                [&stop_flag]()
                {
                    while (!stop_flag.load())
                    {
                        QLogicaeCppCore::AsynchronousManagerConfigurations
                            configurations;

                        configurations.is_enabled =
                            true;

                        QLogicaeCppCore::AsynchronousManager::singleton
                            .setup(configurations);
                    }
                }
            );

        std::thread
            reset_thread(
                [&stop_flag]()
                {
                    while (!stop_flag.load())
                    {
                        QLogicaeCppCore::AsynchronousManager::singleton
                            .reset();
                    }
                }
            );

        std::this_thread::sleep_for(
            std::chrono::milliseconds(200)
        );

        stop_flag.store(true);

        setup_thread.join();
        reset_thread.join();

        ASSERT_TRUE(
            QLogicaeCppCore::AsynchronousManagerConfigurations::cache_is_enabled ==
            true ||
            QLogicaeCppCore::AsynchronousManagerConfigurations::cache_is_enabled ==
            false
        );
    }

    TEST(
        AsynchronousManagerTest,
        Should_RemainStable_When_ResetAndSetupRepeated
    )
    {
        for (int index = 0;
            index < 100;
            index++)
        {
            QLogicaeCppCore::AsynchronousManagerConfigurations
                configurations;

            configurations.is_enabled =
                static_cast<bool>(index % 2);

            ASSERT_TRUE(
                QLogicaeCppCore::AsynchronousManager::singleton
                .setup(configurations)
            );

            ASSERT_TRUE(
                QLogicaeCppCore::AsynchronousManager::singleton
                .reset()
            );
        }
    }

    TEST(
        AsynchronousManagerTest,
        Should_InitializeStaticConfigurationCorrectly_When_FirstAccessed
    )
    {
        ASSERT_EQ(
            QLogicaeCppCore::AsynchronousManagerConfigurations::initial_is_enabled,
            true
        );

        ASSERT_EQ(
            QLogicaeCppCore::AsynchronousManagerConfigurations::default_is_enabled,
            QLogicaeCppCore::AsynchronousManagerConfigurations::initial_is_enabled
        );

        ASSERT_EQ(
            QLogicaeCppCore::AsynchronousManagerConfigurations::cache_is_enabled,
            QLogicaeCppCore::AsynchronousManagerConfigurations::initial_is_enabled
        );
    }
}
