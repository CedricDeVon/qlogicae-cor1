#include "pch.hpp"

#include "../includes/mutex_manager.hpp"

using namespace QLogicaeCppCore;

namespace QLogicaeCppCoreTest
{
    class MutexManagerTest : public ::testing::Test
    {
    protected:
        MutexManager& mutex_manager_instance;

        MutexManagerTest()
            : mutex_manager_instance(MutexManager::singleton)
        {
        }

        void SetUp() override
        {
            ASSERT_TRUE(mutex_manager_instance.construct());
        }

        void TearDown() override
        {
            ASSERT_TRUE(mutex_manager_instance.destruct());
        }
    };

    struct MutexManagerParameterizedTestData
    {
        bool construct_first;
    };

    class MutexManagerParameterizedTest :
        public MutexManagerTest,
        public ::testing::WithParamInterface<MutexManagerParameterizedTestData>
    {
    };

    struct MutexLockCombinationTestData
    {
        std::string mutex_type_name;
        bool construct_first;
    };

    class MutexManagerLockMutexTest :
        public ::testing::Test,
        public ::testing::WithParamInterface<MutexLockCombinationTestData>
    {
    protected:
        MutexManager& mutex_manager_instance;

        void* test_pointer;

        MutexManagerLockMutexTest()
            : mutex_manager_instance(MutexManager::singleton),
            test_pointer(this)
        {
        }

        void SetUp() override
        {
            ASSERT_TRUE(mutex_manager_instance.construct());
        }

        void TearDown() override
        {
            ASSERT_TRUE(mutex_manager_instance.destruct());
        }
    };

    struct FailingMutex
    {
        FailingMutex() { throw std::runtime_error("Constructor failure"); }
        void lock() {}
        void unlock() {}
    };

    class MutexManagerBoostTest : public ::testing::Test
    {
    protected:
        MutexManager& manager = MutexManager::singleton;
        void* test_ptr = reinterpret_cast<void*>(uintptr_t(0xDEADBEEF));
    };

    class MutexManagerMicroSpinTest : public ::testing::Test
    {
    protected:
        QLogicaeCppCore::MutexManager& manager = QLogicaeCppCore::MutexManager::singleton;
    };

    TEST_F(MutexManagerTest, Should_ConstructSuccessfully_When_Called)
    {
        ASSERT_TRUE(mutex_manager_instance.construct());
    }

    TEST_F(MutexManagerTest, Should_DestructSuccessfully_When_Called)
    {
        ASSERT_TRUE(mutex_manager_instance.destruct());
    }

    TEST_F(MutexManagerTest, Should_HandleMultipleConstructDestructCalls_When_CalledRepeatedly)
    {
        for (std::size_t iteration_index = 0; iteration_index < 10; ++iteration_index)
        {
            ASSERT_TRUE(mutex_manager_instance.construct());
            ASSERT_TRUE(mutex_manager_instance.destruct());
        }
    }

    TEST_F(MutexManagerTest, Should_HandleEmptyConfiguration_When_DefaultValuesUsed)
    {
        MutexManagerConfigurations empty_configuration;
        ASSERT_EQ(empty_configuration.name, MutexManagerConfigurations::default_name);
        ASSERT_EQ(empty_configuration.name, MutexManagerConfigurations::default_name);
    }

    TEST_F(MutexManagerTest, Should_BeExceptionSafe_When_ConstructThrows)
    {
        try
        {
            mutex_manager_instance._handle_construct();
        }
        catch (...)
        {
            FAIL();
        }
    }

    TEST_F(MutexManagerTest, Should_BeExceptionSafe_When_DestructThrows)
    {
        try
        {
            mutex_manager_instance._handle_destruct();
        }
        catch (...)
        {
            FAIL();
        }
    }

    TEST_F(MutexManagerTest, Should_HandleConcurrentAsyncAccess_When_UsingFutures)
    {
        std::future<bool> future_1 = std::async(std::launch::async, [&]()
            {
                return mutex_manager_instance.construct();
            });

        std::future<bool> future_2 = std::async(std::launch::async, [&]()
            {
                return mutex_manager_instance.destruct();
            });

        ASSERT_TRUE(future_1.get());
        ASSERT_TRUE(future_2.get());
    }

    TEST_F(MutexManagerTest, Should_HandleConcurrentThreadAccess_When_UsingThreads)
    {
        std::atomic<int> success_counter = 0;

        auto thread_function = [&](bool construct_call)
            {
                if (construct_call)
                {
                    if (mutex_manager_instance.construct())
                    {
                        success_counter.fetch_add(1);
                    }
                }
                else
                {
                    if (mutex_manager_instance.destruct())
                    {
                        success_counter.fetch_add(1);
                    }
                }
            };

        std::vector<std::thread> thread_collection;
        for (std::size_t iteration_index = 0; iteration_index < 10; ++iteration_index)
        {
            thread_collection.emplace_back(thread_function, true);
            thread_collection.emplace_back(thread_function, false);
        }

        for (auto& active_thread : thread_collection)
        {
            active_thread.join();
        }

        ASSERT_EQ(success_counter.load(), 20);
    }

    TEST_F(MutexManagerTest, Should_PerformStressTest_When_CalledMultipleTimesRapidly)
    {
        auto start_time = std::chrono::steady_clock::now();

        for (std::size_t iteration_index = 0; iteration_index < 1000; ++iteration_index)
        {
            ASSERT_TRUE(mutex_manager_instance.construct());
            ASSERT_TRUE(mutex_manager_instance.destruct());
        }

        auto end_time = std::chrono::steady_clock::now();
        auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

        ASSERT_LT(duration_ms, 2000);
    }

    TEST_P(MutexManagerParameterizedTest, Should_HandleParameterizedBehavior_When_ConstructOrDestructCalled)
    {
        auto test_data = GetParam();

        if (test_data.construct_first)
        {
            ASSERT_TRUE(mutex_manager_instance.construct());
            ASSERT_TRUE(mutex_manager_instance.destruct());
        }
        else
        {
            ASSERT_TRUE(mutex_manager_instance.destruct());
            ASSERT_TRUE(mutex_manager_instance.construct());
        }
    }

    INSTANTIATE_TEST_CASE_P(
        MutexManagerParameterizedInstantiation,
        MutexManagerParameterizedTest,
        ::testing::Values(
            MutexManagerParameterizedTestData{ true },
            MutexManagerParameterizedTestData{ false }
        )
    );

    TEST_P(MutexManagerLockMutexTest, Should_LockMutexSuccessfully_When_Called)
    {
        auto test_data = GetParam();

        bool lock_result = false;

        if (test_data.mutex_type_name == "std::mutex")
        {
            lock_result = mutex_manager_instance.lock_mutex<
                std::unique_lock<std::mutex>, std::mutex>(test_pointer);
        }
        else if (test_data.mutex_type_name == "std::timed_mutex")
        {
            lock_result = mutex_manager_instance.lock_mutex<
                std::unique_lock<std::timed_mutex>, std::timed_mutex>(test_pointer);
        }
        else if (test_data.mutex_type_name == "std::recursive_mutex")
        {
            lock_result = mutex_manager_instance.lock_mutex<
                std::unique_lock<std::recursive_mutex>, std::recursive_mutex>(test_pointer);
        }
        else if (test_data.mutex_type_name == "std::recursive_timed_mutex")
        {
            lock_result = mutex_manager_instance.lock_mutex<
                std::unique_lock<std::recursive_timed_mutex>, std::recursive_timed_mutex>(test_pointer);
        }
        else if (test_data.mutex_type_name == "std::shared_mutex")
        {
            lock_result = mutex_manager_instance.lock_mutex<
                std::shared_lock<std::shared_mutex>, std::shared_mutex>(test_pointer);
        }

        ASSERT_TRUE(lock_result);
    }

    TEST_P(MutexManagerLockMutexTest, Should_HandleConcurrentAsyncLock_When_Called)
    {
        auto test_data = GetParam();

        auto async_task_1 = std::async(std::launch::async, [&]()
            {
                bool lock_result_inner = false;

                if (test_data.mutex_type_name == "std::mutex")
                {
                    lock_result_inner = mutex_manager_instance.lock_mutex<
                        std::unique_lock<std::mutex>, std::mutex>(test_pointer);
                }
                else if (test_data.mutex_type_name == "std::timed_mutex")
                {
                    lock_result_inner = mutex_manager_instance.lock_mutex<
                        std::unique_lock<std::timed_mutex>, std::timed_mutex>(test_pointer);
                }
                else if (test_data.mutex_type_name == "std::recursive_mutex")
                {
                    lock_result_inner = mutex_manager_instance.lock_mutex<
                        std::unique_lock<std::recursive_mutex>, std::recursive_mutex>(test_pointer);
                }
                else if (test_data.mutex_type_name == "std::recursive_timed_mutex")
                {
                    lock_result_inner = mutex_manager_instance.lock_mutex<
                        std::unique_lock<std::recursive_timed_mutex>, std::recursive_timed_mutex>(test_pointer);
                }
                else if (test_data.mutex_type_name == "std::shared_mutex")
                {
                    lock_result_inner = mutex_manager_instance.lock_mutex<
                        std::shared_lock<std::shared_mutex>, std::shared_mutex>(test_pointer);
                }

                return lock_result_inner;
            });

        auto async_task_2 = std::async(std::launch::async, [&]()
            {
                bool lock_result_inner = false;

                if (test_data.mutex_type_name == "std::mutex")
                {
                    lock_result_inner = mutex_manager_instance.lock_mutex<
                        std::unique_lock<std::mutex>, std::mutex>(test_pointer);
                }
                else if (test_data.mutex_type_name == "std::timed_mutex")
                {
                    lock_result_inner = mutex_manager_instance.lock_mutex<
                        std::unique_lock<std::timed_mutex>, std::timed_mutex>(test_pointer);
                }
                else if (test_data.mutex_type_name == "std::recursive_mutex")
                {
                    lock_result_inner = mutex_manager_instance.lock_mutex<
                        std::unique_lock<std::recursive_mutex>, std::recursive_mutex>(test_pointer);
                }
                else if (test_data.mutex_type_name == "std::recursive_timed_mutex")
                {
                    lock_result_inner = mutex_manager_instance.lock_mutex<
                        std::unique_lock<std::recursive_timed_mutex>, std::recursive_timed_mutex>(test_pointer);
                }
                else if (test_data.mutex_type_name == "std::shared_mutex")
                {
                    lock_result_inner = mutex_manager_instance.lock_mutex<
                        std::shared_lock<std::shared_mutex>, std::shared_mutex>(test_pointer);
                }

                return lock_result_inner;
            });

        ASSERT_TRUE(async_task_1.get());
        ASSERT_TRUE(async_task_2.get());
    }

    TEST_P(MutexManagerLockMutexTest, Should_PerformStressLock_When_CalledMultipleTimes)
    {
        auto test_data = GetParam();

        auto start_time = std::chrono::steady_clock::now();

        for (std::size_t iteration_index = 0; iteration_index < 1000; ++iteration_index)
        {
            bool lock_result = false;

            if (test_data.mutex_type_name == "std::mutex")
            {
                lock_result = mutex_manager_instance.lock_mutex<
                    std::unique_lock<std::mutex>, std::mutex>(test_pointer);
            }
            else if (test_data.mutex_type_name == "std::timed_mutex")
            {
                lock_result = mutex_manager_instance.lock_mutex<
                    std::unique_lock<std::timed_mutex>, std::timed_mutex>(test_pointer);
            }
            else if (test_data.mutex_type_name == "std::recursive_mutex")
            {
                lock_result = mutex_manager_instance.lock_mutex<
                    std::unique_lock<std::recursive_mutex>, std::recursive_mutex>(test_pointer);
            }
            else if (test_data.mutex_type_name == "std::recursive_timed_mutex")
            {
                lock_result = mutex_manager_instance.lock_mutex<
                    std::unique_lock<std::recursive_timed_mutex>, std::recursive_timed_mutex>(test_pointer);
            }
            else if (test_data.mutex_type_name == "std::shared_mutex")
            {
                lock_result = mutex_manager_instance.lock_mutex<
                    std::shared_lock<std::shared_mutex>, std::shared_mutex>(test_pointer);
            }

            ASSERT_TRUE(lock_result);
        }

        auto end_time = std::chrono::steady_clock::now();
        auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            end_time - start_time
        ).count();

        ASSERT_LT(duration_ms, 2000);
    }

    INSTANTIATE_TEST_CASE_P(
        MutexManagerLockMutexParameterizedInstantiation,
        MutexManagerLockMutexTest,
        ::testing::Values(
            MutexLockCombinationTestData{ "std::mutex", true },
            MutexLockCombinationTestData{ "std::mutex", false },
            MutexLockCombinationTestData{ "std::timed_mutex", true },
            MutexLockCombinationTestData{ "std::timed_mutex", false },
            MutexLockCombinationTestData{ "std::recursive_mutex", true },
            MutexLockCombinationTestData{ "std::recursive_mutex", false },
            MutexLockCombinationTestData{ "std::recursive_timed_mutex", true },
            MutexLockCombinationTestData{ "std::recursive_timed_mutex", false },
            MutexLockCombinationTestData{ "std::shared_mutex", true },
            MutexLockCombinationTestData{ "std::shared_mutex", false }
        )
    );

    TEST_F(MutexManagerLockMutexTest, Should_ReturnFalse_When_PointerIsNull)
    {
        bool lock_result = mutex_manager_instance.lock_mutex<
            std::unique_lock<std::mutex>, std::mutex>(nullptr);
        ASSERT_FALSE(lock_result);
    }

    TEST_F(MutexManagerLockMutexTest, Should_HandleEmptyName_When_Called)
    {
        bool lock_result = mutex_manager_instance.lock_mutex<
            std::unique_lock<std::mutex>, std::mutex>(test_pointer, "");
        ASSERT_TRUE(lock_result);
    }

    TEST_F(MutexManagerLockMutexTest, Should_HandleSharedMutexConcurrentRead)
    {
        std::atomic<int> success_count = 0;
        auto task = [&]()
            {
                if (mutex_manager_instance.lock_mutex<
                    std::shared_lock<std::shared_mutex>, std::shared_mutex>(test_pointer))
                {
                    success_count.fetch_add(1);
                }
            };

        std::vector<std::thread> threads(5);
        for (auto& t : threads) t = std::thread(task);
        for (auto& t : threads) t.join();

        ASSERT_EQ(success_count.load(), 5);
    }

    TEST_P(MutexManagerLockMutexTest, Should_PerformStressLock_AllMutexTypes)
    {
        auto test_data = GetParam();
        auto start_time = std::chrono::steady_clock::now();

        for (std::size_t i = 0; i < 1000; ++i)
        {
            bool lock_result = false;

            if (test_data.mutex_type_name == "std::mutex")
            {
                lock_result = mutex_manager_instance.lock_mutex<
                    std::unique_lock<std::mutex>, std::mutex>(test_pointer);
            }
            else if (test_data.mutex_type_name == "std::timed_mutex")
            {
                lock_result = mutex_manager_instance.lock_mutex<
                    std::unique_lock<std::timed_mutex>, std::timed_mutex>(test_pointer);
            }
            else if (test_data.mutex_type_name == "std::recursive_mutex")
            {
                lock_result = mutex_manager_instance.lock_mutex<
                    std::unique_lock<std::recursive_mutex>, std::recursive_mutex>(test_pointer);
            }
            else if (test_data.mutex_type_name == "std::recursive_timed_mutex")
            {
                lock_result = mutex_manager_instance.lock_mutex<
                    std::unique_lock<std::recursive_timed_mutex>, std::recursive_timed_mutex>(test_pointer);
            }
            else if (test_data.mutex_type_name == "std::shared_mutex")
            {
                lock_result = mutex_manager_instance.lock_mutex<
                    std::shared_lock<std::shared_mutex>, std::shared_mutex>(test_pointer);
            }

            ASSERT_TRUE(lock_result);
        }

        auto end_time = std::chrono::steady_clock::now();
        auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            end_time - start_time
        ).count();

        ASSERT_LT(duration_ms, 2000);
    }

    TEST_F(MutexManagerTest, Should_ReturnFalse_When_LockMutexCalledWithNullptr)
    {
        bool lock_result = mutex_manager_instance.lock_mutex<std::unique_lock<std::mutex>, std::mutex>(nullptr);
        ASSERT_FALSE(lock_result);
    }

    TEST_F(MutexManagerTest, Should_HandleEmptyBaseName_When_ConstructCalled)
    {
        MutexManagerConfigurations config;
        config.name = "";
        config.name = "";
        ASSERT_TRUE(mutex_manager_instance.construct());
        ASSERT_TRUE(mutex_manager_instance.destruct());
    }

    TEST_P(MutexManagerLockMutexTest, Should_AllowRecursiveLock_When_UsingRecursiveMutex)
    {
        auto test_data = GetParam();
        if (test_data.mutex_type_name == "std::recursive_mutex" ||
            test_data.mutex_type_name == "std::recursive_timed_mutex")
        {
            bool first_lock = false;
            bool second_lock = false;
            if (test_data.mutex_type_name == "std::recursive_mutex")
            {
                first_lock = mutex_manager_instance.lock_mutex<std::unique_lock<std::recursive_mutex>, std::recursive_mutex>(test_pointer);
                second_lock = mutex_manager_instance.lock_mutex<std::unique_lock<std::recursive_mutex>, std::recursive_mutex>(test_pointer);
            }
            else
            {
                first_lock = mutex_manager_instance.lock_mutex<std::unique_lock<std::recursive_timed_mutex>, std::recursive_timed_mutex>(test_pointer);
                second_lock = mutex_manager_instance.lock_mutex<std::unique_lock<std::recursive_timed_mutex>, std::recursive_timed_mutex>(test_pointer);
            }
            ASSERT_TRUE(first_lock);
            ASSERT_TRUE(second_lock);
        }
    }

    TEST_P(MutexManagerLockMutexTest, Should_AllowMultipleSharedLocksConcurrently)
    {
        auto test_data = GetParam();
        if (test_data.mutex_type_name == "std::shared_mutex")
        {
            auto shared_lock_task_1 = std::async(std::launch::async, [&]()
                {
                    return mutex_manager_instance.lock_mutex<std::shared_lock<std::shared_mutex>, std::shared_mutex>(test_pointer);
                });
            auto shared_lock_task_2 = std::async(std::launch::async, [&]()
                {
                    return mutex_manager_instance.lock_mutex<std::shared_lock<std::shared_mutex>, std::shared_mutex>(test_pointer);
                });
            ASSERT_TRUE(shared_lock_task_1.get());
            ASSERT_TRUE(shared_lock_task_2.get());
        }
    }

    TEST_P(MutexManagerLockMutexTest, Should_HandleTimedMutexTimeout)
    {
        auto test_data = GetParam();

        if (test_data.mutex_type_name == "std::timed_mutex")
        {
            std::timed_mutex timed_mutex_instance;
            std::unique_lock<std::timed_mutex> lock(timed_mutex_instance, std::defer_lock);
            bool lock_result = mutex_manager_instance.lock_mutex<std::unique_lock<std::timed_mutex>, std::timed_mutex>(test_pointer);
            ASSERT_TRUE(lock_result);
        }
        else if (test_data.mutex_type_name == "std::recursive_timed_mutex")
        {
            std::recursive_timed_mutex recursive_timed_mutex_instance;
            std::unique_lock<std::recursive_timed_mutex> lock(recursive_timed_mutex_instance, std::defer_lock);
            bool lock_result = mutex_manager_instance.lock_mutex<std::unique_lock<std::recursive_timed_mutex>, std::recursive_timed_mutex>(test_pointer);
            ASSERT_TRUE(lock_result);
        }
        else if (test_data.mutex_type_name == "std::recursive_mutex")
        {
            std::recursive_mutex recursive_mutex_instance;
            std::unique_lock<std::recursive_mutex> lock(recursive_mutex_instance, std::defer_lock);
            bool lock_result = mutex_manager_instance.lock_mutex<std::unique_lock<std::recursive_mutex>, std::recursive_mutex>(test_pointer);
            ASSERT_TRUE(lock_result);
        }
    }

    TEST_F(MutexManagerTest, Should_BeExceptionSafe_When_MutexConstructorThrows)
    {
        try
        {
            FailingMutex failing_mutex_instance;
            std::unique_lock<FailingMutex> lock(failing_mutex_instance);
            FAIL();
        }
        catch (...)
        {
        }
    }

    TEST_F(MutexManagerBoostTest, BoostMutexLockWithoutName)
    {
        bool locked = manager.lock_mutex<boost::unique_lock<boost::mutex>, boost::mutex>(test_ptr);
        EXPECT_TRUE(locked);
    }

    TEST_F(MutexManagerBoostTest, BoostMutexLockWithName)
    {
        bool locked = manager.lock_mutex<boost::unique_lock<boost::mutex>, boost::mutex>(test_ptr, "test_mutex");
        EXPECT_TRUE(locked);
    }

    TEST_F(MutexManagerBoostTest, BoostTimedMutexLockWithoutName)
    {
        bool locked = manager.lock_mutex<boost::unique_lock<boost::timed_mutex>, boost::timed_mutex>(test_ptr);
        EXPECT_TRUE(locked);
    }

    TEST_F(MutexManagerBoostTest, BoostTimedMutexLockWithName)
    {
        bool locked = manager.lock_mutex<boost::unique_lock<boost::timed_mutex>, boost::timed_mutex>(test_ptr, "test_timed_mutex");
        EXPECT_TRUE(locked);
    }

    TEST_F(MutexManagerBoostTest, BoostRecursiveMutexReentrancy)
    {
        bool first_lock = manager.lock_mutex<boost::unique_lock<boost::recursive_mutex>, boost::recursive_mutex>(test_ptr);
        bool second_lock = manager.lock_mutex<boost::unique_lock<boost::recursive_mutex>, boost::recursive_mutex>(test_ptr);
        EXPECT_TRUE(first_lock);
        EXPECT_TRUE(second_lock);
    }

    TEST_F(MutexManagerBoostTest, BoostRecursiveTimedMutexReentrancy)
    {
        bool first_lock = manager.lock_mutex<boost::unique_lock<boost::recursive_timed_mutex>, boost::recursive_timed_mutex>(test_ptr);
        bool second_lock = manager.lock_mutex<boost::unique_lock<boost::recursive_timed_mutex>, boost::recursive_timed_mutex>(test_ptr);
        EXPECT_TRUE(first_lock);
        EXPECT_TRUE(second_lock);
    }

    TEST_F(MutexManagerBoostTest, BoostSharedMutexMultipleReaders)
    {
        bool reader1 = manager.lock_mutex<boost::shared_lock<boost::shared_mutex>, boost::shared_mutex>(test_ptr);
        bool reader2 = manager.lock_mutex<boost::shared_lock<boost::shared_mutex>, boost::shared_mutex>(test_ptr);
        EXPECT_TRUE(reader1);
        EXPECT_TRUE(reader2);
    }

    TEST_F(MutexManagerBoostTest, NullPointerReturnsFalse)
    {
        bool locked = manager.lock_mutex<boost::unique_lock<boost::mutex>, boost::mutex>(nullptr);
        EXPECT_FALSE(locked);
    }

    TEST_F(MutexManagerBoostTest, NullPointerWithNameReturnsFalse)
    {
        bool locked = manager.lock_mutex<boost::unique_lock<boost::mutex>, boost::mutex>(nullptr, "null_mutex");
        EXPECT_FALSE(locked);
    }

    TEST_F(MutexManagerBoostTest, EmptyNameStringLock)
    {
        bool locked = manager.lock_mutex<boost::unique_lock<boost::mutex>, boost::mutex>(test_ptr, "");
        EXPECT_TRUE(locked);
    }

    TEST_F(MutexManagerBoostTest, MultiThreadedBoostMutex)
    {
        bool result1 = false, result2 = false;
        std::thread t1([&]() { result1 = manager.lock_mutex<boost::unique_lock<boost::mutex>, boost::mutex>(test_ptr, "thread_mutex"); });
        std::thread t2([&]() { result2 = manager.lock_mutex<boost::unique_lock<boost::mutex>, boost::mutex>(test_ptr, "thread_mutex"); });
        t1.join();
        t2.join();
        EXPECT_TRUE(result1);
        EXPECT_TRUE(result2);
    }

    TEST_F(MutexManagerBoostTest, MultiThreadedBoostSharedMutex)
    {
        bool result1 = false, result2 = false;
        std::thread t1([&]() { result1 = manager.lock_mutex<boost::shared_lock<boost::shared_mutex>, boost::shared_mutex>(test_ptr, "shared_mutex"); });
        std::thread t2([&]() { result2 = manager.lock_mutex<boost::shared_lock<boost::shared_mutex>, boost::shared_mutex>(test_ptr, "shared_mutex"); });
        t1.join();
        t2.join();
        EXPECT_TRUE(result1);
        EXPECT_TRUE(result2);
    }

    TEST_F(MutexManagerMicroSpinTest, LockMicroSpinMutex)
    {
        bool locked = manager.lock_micro_mutex();
        bool unlocked = manager.unlock_micro_mutex();
        EXPECT_TRUE(locked);
    }

    TEST_F(MutexManagerMicroSpinTest, UnlockMicroSpinMutex)
    {
        manager.lock_micro_mutex();
        bool unlocked = manager.unlock_micro_mutex();
        EXPECT_TRUE(unlocked);
    }

    TEST_F(MutexManagerMicroSpinTest, LockUnlockSequence)
    {
        bool lock1 = manager.lock_micro_mutex();
        bool unlock1 = manager.unlock_micro_mutex();
        bool lock2 = manager.lock_micro_mutex();
        bool unlock2 = manager.unlock_micro_mutex();

        EXPECT_TRUE(lock1);
        EXPECT_TRUE(unlock1);
        EXPECT_TRUE(lock2);
        EXPECT_TRUE(unlock2);
    }

    TEST_F(MutexManagerMicroSpinTest, MultiThreadedMicroSpinLock)
    {
        bool result1 = false, result2 = false;

        std::thread t1([&]() { result1 = manager.lock_micro_mutex(); manager.unlock_micro_mutex(); });
        std::thread t2([&]() { result2 = manager.lock_micro_mutex(); manager.unlock_micro_mutex(); });

        t1.join();
        t2.join();

        EXPECT_TRUE(result1);
        EXPECT_TRUE(result2);
    }

    TEST_F(MutexManagerMicroSpinTest, MultipleSequentialLocks)
    {
        bool results[5] = {};

        for (int i = 0; i < 5; ++i)
        {
            results[i] = manager.lock_micro_mutex();
            manager.unlock_micro_mutex();
        }

        for (int i = 0; i < 5; ++i)
            EXPECT_TRUE(results[i]);
    }
}
