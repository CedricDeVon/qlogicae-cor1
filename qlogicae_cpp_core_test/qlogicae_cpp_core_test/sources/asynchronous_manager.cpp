#include "pch.hpp"

#include "../includes/asynchronous_manager.hpp"

namespace
	QLogicaeCppCoreTest
{
    class AsynchronousManagerTest :
        public ::testing::Test
    {
    public:
        AsynchronousManagerTest()
        {
            QLogicaeCppCore::AsynchronousManager::singleton
                .reset();
        }

        ~AsynchronousManagerTest() override
        {
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

        configurations.is_feature_handling_enabled =
			false;

		QLogicaeCppCore::AsynchronousManager::singleton
			.setup(configurations);

		bool reset_result =
			QLogicaeCppCore::AsynchronousManager::singleton
			.reset();

		ASSERT_TRUE(reset_result);

		ASSERT_TRUE(
			QLogicaeCppCore::AsynchronousManager::singleton.configurations.is_feature_handling_enabled
		);
	}

	TEST(
		AsynchronousManagerTest,
		Should_DispatchTask_When_Enabled
	)
	{
		QLogicaeCppCore::AsynchronousManagerConfigurations
			configurations;

		configurations.is_feature_handling_enabled =
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

		configurations.is_feature_handling_enabled =
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

		QLogicaeCppCore::AsynchronousManager::singleton
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

		configurations.is_feature_handling_enabled =
			true;

		QLogicaeCppCore::AsynchronousManager::singleton
			.setup(configurations);

		std::atomic<int>
			execution_count(0);

		std::vector<std::thread>
			threads;

		for (int index = 0;
			index < 10;
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

		QLogicaeCppCore::AsynchronousManager::singleton
			.complete_all_threads();

		ASSERT_GE(
			execution_count.load(),
			995
		);
	}

	TEST_P(
		AsynchronousManagerConfigurationTest,
		Should_RespectConfigurationValue_When_SetupCalled
	)
	{
		QLogicaeCppCore::AsynchronousManagerConfigurations
			configurations;

		configurations.is_feature_handling_enabled =
			GetParam();

		QLogicaeCppCore::AsynchronousManager::singleton
			.setup(configurations);

		ASSERT_EQ(
			QLogicaeCppCore::AsynchronousManager::singleton.configurations.is_feature_handling_enabled,
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

		configurations.is_feature_handling_enabled =
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

		QLogicaeCppCore::AsynchronousManager::singleton
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

		configurations.is_feature_handling_enabled =
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

		QLogicaeCppCore::AsynchronousManager::singleton
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

						configurations.is_feature_handling_enabled =
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
			QLogicaeCppCore::AsynchronousManager::singleton.configurations.is_feature_handling_enabled ==
			true ||
			QLogicaeCppCore::AsynchronousManager::singleton.configurations.is_feature_handling_enabled ==
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

			configurations.is_feature_handling_enabled =
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
			QLogicaeCppCore::AsynchronousManagerConfigurations::initial_configurations.is_feature_handling_enabled,
			true
		);

		ASSERT_EQ(
			QLogicaeCppCore::AsynchronousManagerConfigurations::default_configurations.is_feature_handling_enabled,
			QLogicaeCppCore::AsynchronousManagerConfigurations::initial_configurations.is_feature_handling_enabled
		);

		ASSERT_EQ(
			QLogicaeCppCore::AsynchronousManager::singleton.configurations.is_feature_handling_enabled,
			QLogicaeCppCore::AsynchronousManagerConfigurations::initial_configurations.is_feature_handling_enabled
		);
	}

	TEST(
		AsynchronousManagerTest,
		Should_Post_Thread_Await_Return_Value
	)
	{
		QLogicaeCppCore::AsynchronousManager&
			manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations
			configurations;

		configurations.is_feature_handling_enabled = true;

		manager.setup(
			configurations
		);

		auto future =
			manager.post_thread_await<int>(
				[]()
				{
					return 42;
				}
			);

		EXPECT_EQ(
			future.get(),
			42
		);
	}

	TEST(
		AsynchronousManagerTest,
		Should_Post_Thread_Async_With_Result_Callback
	)
	{
		QLogicaeCppCore::AsynchronousManager&
			manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations
			configurations;

		configurations.is_feature_handling_enabled = true;

		manager.setup(
			configurations
		);

		std::atomic<int>
			result{ 0 };

		EXPECT_TRUE(
			manager.post_thread_async<int>(
				[]()
				{
					return 7;
				},
				[&](const int& value)
				{
					result.store(value);
				}
			)
		);

		manager.complete_all_threads();

		EXPECT_EQ(
			result.load(),
			7
		);
	}

	TEST(
		AsynchronousManagerTest,
		Should_Post_Thread_Async_With_Void_Callback
	)
	{
		QLogicaeCppCore::AsynchronousManager&
			manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations
			configurations;

		configurations.is_feature_handling_enabled = true;

		manager.setup(
			configurations
		);

		std::atomic<bool>
			called{ false };

		EXPECT_TRUE(
			manager.post_thread_async<int>(
				[]()
				{
					return 1;
				},
				[&]()
				{
					called.store(true);
				}
			)
		);

		manager.complete_all_threads();

		EXPECT_TRUE(
			called.load()
		);
	}

	TEST(
		AsynchronousManagerTest,
		Should_Dispatch_Thread_Async_Void
	)
	{
		QLogicaeCppCore::AsynchronousManager&
			manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations
			configurations;

		configurations.is_feature_handling_enabled = true;

		manager.setup(
			configurations
		);

		std::atomic<bool>
			called{ false };

		EXPECT_TRUE(
			manager.dispatch_thread_async(
				[&]()
				{
					called.store(true);
				}
			)
		);

		manager.complete_all_threads();

		EXPECT_TRUE(
			called.load()
		);
	}

	TEST(
		AsynchronousManagerTest,
		Should_Dispatch_Thread_Await_Return_Value
	)
	{
		QLogicaeCppCore::AsynchronousManager&
			manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations
			configurations;

		configurations.is_feature_handling_enabled = true;

		manager.setup(
			configurations
		);

		auto future =
			manager.dispatch_thread_await<int>(
				[]()
				{
					return 9;
				}
			);

		EXPECT_EQ(
			future.get(),
			9
		);
	}

	TEST(
		AsynchronousManagerTest,
		Should_Dispatch_Thread_Async_With_Result_Callback
	)
	{
		QLogicaeCppCore::AsynchronousManager&
			manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations
			configurations;

		configurations.is_feature_handling_enabled = true;

		manager.setup(
			configurations
		);

		std::atomic<int>
			result{ 0 };

		EXPECT_TRUE(
			manager.dispatch_thread_async<int>(
				[]()
				{
					return 11;
				},
				[&](const int& value)
				{
					result.store(value);
				}
			)
		);

		manager.complete_all_threads();

		EXPECT_EQ(
			result.load(),
			11
		);
	}

	TEST(
		AsynchronousManagerTest,
		Should_Dispatch_Thread_Async_With_Void_Callback
	)
	{
		QLogicaeCppCore::AsynchronousManager&
			manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations
			configurations;

		configurations.is_feature_handling_enabled = true;

		manager.setup(
			configurations
		);

		std::atomic<bool>
			called{ false };

		EXPECT_TRUE(
			manager.dispatch_thread_async<int>(
				[]()
				{
					return 3;
				},
				[&]()
				{
					called.store(true);
				}
			)
		);

		manager.complete_all_threads();

		EXPECT_TRUE(
			called.load()
		);
	}

	TEST(
		AsynchronousManagerTest,
		Should_CoSpawn_Strand_Await_Return_Value
	)
	{
		QLogicaeCppCore::AsynchronousManager&
			manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations
			configurations;

		configurations.is_feature_handling_enabled = true;

		manager.setup(
			configurations
		);

		ASSERT_TRUE(
			manager.begin_io_workers()
		);

		auto future =
			manager.co_spawn_strand_await<int>(
				[]()
				{
					return 21;
				}
			);

		EXPECT_EQ(
			future.get(),
			21
		);

		EXPECT_TRUE(
			manager.complete_io_workers()
		);
	}

	TEST(
		AsynchronousManagerTest,
		Should_CoSpawn_Strand_Async_Void
	)
	{
		QLogicaeCppCore::AsynchronousManager&
			manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations
			configurations;

		configurations.is_feature_handling_enabled = true;

		manager.setup(configurations);

		ASSERT_TRUE(manager.begin_io_workers());

		std::atomic<bool> called{ false };

		EXPECT_TRUE(
			manager.co_spawn_strand_async(
				[&]()
				{
					called.store(true);
				}
			)
		);

		EXPECT_TRUE(manager.complete_io_workers());

		EXPECT_TRUE(called.load());
	}

	TEST(
		AsynchronousManagerTest,
		Should_CoSpawn_Strand_Async_With_Result_Callback
	)
	{
		QLogicaeCppCore::AsynchronousManager&
			manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations
			configurations;

		configurations.is_feature_handling_enabled = true;

		manager.setup(configurations);

		ASSERT_TRUE(manager.begin_io_workers());

		std::atomic<int> result{ 0 };

		EXPECT_TRUE(
			manager.co_spawn_strand_async<int>(
				[]()
				{
					return 5;
				},
				[&](const int& value)
				{
					result.store(value);
				}
			)
		);

		EXPECT_TRUE(manager.complete_io_workers());

		EXPECT_EQ(result.load(), 5);
	}

	TEST(
		AsynchronousManagerTest,
		Should_Begin_And_Complete_IO_Workers
	)
	{
		QLogicaeCppCore::AsynchronousManager&
			manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations
			configurations;

		configurations.is_feature_handling_enabled = true;

		manager.setup(
			configurations
		);

		EXPECT_TRUE(
			manager.begin_io_workers()
		);

		EXPECT_TRUE(
			manager.complete_io_workers()
		);
	}

	TEST(
		AsynchronousManagerTest,
		Should_CoSpawn_Strand_Async_With_ReturnType_And_Void_Callback
	)
	{
		QLogicaeCppCore::AsynchronousManager& manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations configurations;
		configurations.is_feature_handling_enabled = true;

		manager.setup(configurations);

		ASSERT_TRUE(manager.begin_io_workers());

		std::atomic<bool> called{ false };

		EXPECT_TRUE(
			manager.co_spawn_strand_async<int>(
				[]() { return 99; },
				[&]() { called.store(true); }
			)
		);

		EXPECT_TRUE(manager.complete_io_workers());

		EXPECT_TRUE(called.load());
	}

	TEST(
		AsynchronousManagerTest,
		Should_Handle_Exception_In_CoSpawn_Strand_Await
	)
	{
		QLogicaeCppCore::AsynchronousManager& manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations configurations;
		configurations.is_feature_handling_enabled = true;

		manager.setup(configurations);

		ASSERT_TRUE(manager.begin_io_workers());

		auto future =
			manager.co_spawn_strand_await<int>(
				[]() -> int { throw std::runtime_error("fail"); return 0; }
			);

		EXPECT_NO_THROW(future.get());

		EXPECT_TRUE(manager.complete_io_workers());
	}

	TEST(
		AsynchronousManagerTest,
		Should_Not_Call_Callback_When_CoSpawn_Strand_Async_Throws
	)
	{
		QLogicaeCppCore::AsynchronousManager& manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations configurations;
		configurations.is_feature_handling_enabled = true;

		manager.setup(configurations);

		ASSERT_TRUE(manager.begin_io_workers());

		std::atomic<bool> called{ false };

		EXPECT_TRUE(
			manager.co_spawn_strand_async<int>(
				[]() { throw std::runtime_error("fail"); return 0; },
				[&]() { called.store(true); }
			)
		);

		EXPECT_TRUE(manager.complete_io_workers());

		EXPECT_FALSE(called.load());
	}

	TEST(
		AsynchronousManagerTest,
		Should_Handle_Exception_In_CoSpawn_Strand_Async_With_Result_Callback
	)
	{
		QLogicaeCppCore::AsynchronousManager& manager =
			QLogicaeCppCore::AsynchronousManager::singleton;

		QLogicaeCppCore::AsynchronousManagerConfigurations configurations;
		configurations.is_feature_handling_enabled = true;

		manager.setup(configurations);

		ASSERT_TRUE(manager.begin_io_workers());

		std::atomic<int> result{ 0 };

		EXPECT_TRUE(
			manager.co_spawn_strand_async<int>(
				[]() -> int { throw std::runtime_error("fail"); return 0; },
				[&](const int& value) { result.store(value); }
			)
		);

		EXPECT_TRUE(manager.complete_io_workers());

		EXPECT_EQ(result.load(), 0);
	}

}
