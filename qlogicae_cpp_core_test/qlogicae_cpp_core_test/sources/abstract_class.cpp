#include "pch.hpp"

#include "../includes/abstract_class.hpp"

using namespace QLogicaeCppCore;

namespace
	QLogicaeCppCoreTest
{
	struct TestConfigurations :
		public AbstractConfigurations<TestConfigurations>
	{
	public:
		static TestConfigurations
			default_configurations;
	};

	TestConfigurations
		TestConfigurations
			::default_configurations;

	class TestClass :
		public AbstractClass<TestConfigurations>
	{
	public:
		TestClass()
		{
		}

		bool
			throwing_method()
		{
			throw std::runtime_error(
				std::string("exception")
			);
		}
	};

	class AbstractConfigurationsTest :
		public ::testing::Test
	{
	public:
		TestConfigurations
			configurations;
	};

	class AbstractConfigurationsParameterizedTest :
		public ::testing::TestWithParam<bool>
	{
	public:
		TestConfigurations
			configurations;
	};

	class AbstractClassTest :
		public ::testing::Test
	{
	public:
		TestClass
			instance;
	};

	class FailingTestClass :
		public AbstractClass<TestConfigurations>
	{
	public:
		bool
			handle_error_outputs(
				const std::exception&
			)
		{
			return
				false;
		}
	};

	TEST_F(
		AbstractConfigurationsTest,
		Should_EnableUtilityThreadSafety_When_OverrideDisabled
	)
	{
		ASSERT_TRUE(
			configurations
				.is_thread_safety_enabled_for_utility_handling()
		);
	}

	TEST_F(
		AbstractConfigurationsTest,
		Should_EnableFeatureThreadSafety_When_OverrideDisabled
	)
	{
		ASSERT_FALSE(
			configurations
				.is_thread_safety_enabled_for_feature_handling()
		);
	}

	TEST_F(
		AbstractConfigurationsTest,
		Should_EnableErrorThreadSafety_When_OverrideDisabled
	)
	{
		ASSERT_TRUE(
			configurations
				.is_thread_safety_enabled_for_error_handling()
		);
	}

	TEST_P(
		AbstractConfigurationsParameterizedTest,
		Should_OverrideAllThreadSafety_When_OverrideEnabled
	)
	{
		configurations
			.is_thread_safety_override_enabled =
				GetParam();

		ASSERT_EQ(
			configurations
				.is_thread_safety_enabled_for_utility_handling(),
			GetParam() ||
			configurations
				.is_utility_handling_thread_safety_enabled
		);

		ASSERT_EQ(
			configurations
				.is_thread_safety_enabled_for_feature_handling(),
			GetParam() ||
			configurations
				.is_feature_handling_thread_safety_enabled
		);

		ASSERT_EQ(
			configurations
				.is_thread_safety_enabled_for_error_handling(),
			GetParam() ||
			configurations
				.is_error_handling_thread_safety_enabled
		);
	}

	INSTANTIATE_TEST_CASE_P(
		OverrideValues,
		AbstractConfigurationsParameterizedTest,
		::testing::Values(
			false,
			true
		)
	);

	TEST_F(
		AbstractClassTest,
		Should_ConstructSuccessfully_When_DefaultConfiguration
	)
	{
		ASSERT_TRUE(
			instance.construct()
		);
	}

	TEST_F(
		AbstractClassTest,
		Should_DestructSuccessfully_When_DefaultConfiguration
	)
	{
		ASSERT_TRUE(
			instance.destruct()
		);
	}

	TEST_F(
		AbstractClassTest,
		Should_ResetConfigurations_When_ResetCalled
	)
	{
		ASSERT_TRUE(
			instance.reset()
		);
	}

	TEST_F(
		AbstractClassTest,
		Should_SetupConfigurations_When_NewConfigurationProvided
	)
	{
		TestConfigurations
			new_configurations;

		new_configurations
			.is_thread_safety_override_enabled =
				true;

		ASSERT_TRUE(
			instance.setup(
				new_configurations
			)
		);
	}

	TEST_F(
		AbstractClassTest,
		Should_HandleException_When_ExceptionThrown
	)
	{
		try
		{
			instance.throwing_method();
		}
		catch
		(
			const std::exception&
		)
		{
			ASSERT_FALSE(
				instance.handle_error_outputs(
					std::string("error")
				)
			);
		}
	}

	TEST_F(
		AbstractClassTest,
		Should_SupportAsynchronousConstruction_When_UsedWithAsync
	)
	{
		auto
			start_time =
				std::chrono::steady_clock::now();

		auto
			future_result =
				std::async(
					std::launch::async,
					[this]()
					{
						return
							instance.construct();
					}
				);

		ASSERT_TRUE(
			future_result.get()
		);

		auto
			end_time =
				std::chrono::steady_clock::now();

		ASSERT_LT(
			std::chrono::duration_cast
			<
				std::chrono::milliseconds
			>(
				end_time - start_time
			).count(),
			2000
		);
	}

	TEST_F(
		AbstractClassTest,
		Should_HandleMultithreadedAccess_When_StressTested
	)
	{
		std::atomic<bool>
			is_successful =
				true;

		std::vector<std::thread>
			threads;

		for
		(
			std::size_t
				thread_index =
					0;
			thread_index <
				8;
			thread_index++
		)
		{
			threads.emplace_back(
				[this, &is_successful]()
				{
					for
					(
						std::size_t
							iteration_index =
								0;
						iteration_index <
							1000;
						iteration_index++
					)
					{
						if
						(
							!instance.construct()
						)
						{
							is_successful =
								false;
						}
					}
				}
			);
		}

		for
		(
			auto&
				thread_instance :
					threads
		)
		{
			thread_instance.join();
		}

		ASSERT_TRUE(
			is_successful.load()
		);
	}

	TEST_F(
		AbstractClassTest,
		Should_CompleteStressTestWithinTimeLimit_When_UnderLoad
	)
	{
		auto
			start_time =
				std::chrono::steady_clock::now();

		for
		(
			std::size_t
				iteration_index =
					0;
			iteration_index <
				50000;
			iteration_index++
		)
		{
			ASSERT_TRUE(
				instance.construct()
			);
		}

		auto
			end_time =
				std::chrono::steady_clock::now();

		ASSERT_LT(
			std::chrono::duration_cast
			<
				std::chrono::milliseconds
			>(
				end_time - start_time
			).count(),
			2000
		);
	}

	TEST(
		AbstractClassAsyncTest,
		Should_SynchronizeUsingPromise_When_AsynchronouslyConstructed
	)
	{
		std::promise<bool>
			promise_value;

		std::future<bool>
			future_value =
				promise_value.get_future();

		std::thread
			worker_thread(
				[&promise_value]()
				{
					TestClass
						instance;

					promise_value.set_value(
						instance.construct()
					);
				}
			);

		ASSERT_TRUE(
			future_value.get()
		);

		worker_thread.join();
	}

	TEST(
		AbstractClassThreadingTest,
		Should_CoordinateThreadsUsingConditionVariable_When_Contended
	)
	{
		std::mutex
			synchronization_mutex;

		std::condition_variable
			condition_variable_instance;

		bool
			is_ready =
				false;

		TestClass
			instance;

		std::thread
			waiting_thread(
				[&]()
				{
					std::unique_lock<std::mutex>
						lock(
							synchronization_mutex
						);

					condition_variable_instance.wait(
						lock,
						[&]()
						{
							return
								is_ready;
						}
					);

					instance.construct();
				}
			);

		{
			std::lock_guard<std::mutex>
				lock(
					synchronization_mutex
				);

			is_ready =
				true;
		}

		condition_variable_instance.notify_one();

		waiting_thread.join();

		ASSERT_TRUE(
			instance.destruct()
		);
	}

	TEST(
		AbstractConfigurationsEdgeCaseTest,
		Should_DisableAllThreadSafety_When_AllFlagsFalse
	)
	{
		TestConfigurations
			configurations;

		configurations
			.is_thread_safety_override_enabled =
				false;

		configurations
			.is_utility_handling_thread_safety_enabled =
				false;

		configurations
			.is_feature_handling_thread_safety_enabled =
				false;

		configurations
			.is_error_handling_thread_safety_enabled =
				false;

		ASSERT_FALSE(
			configurations
				.is_thread_safety_enabled_for_utility_handling()
		);

		ASSERT_FALSE(
			configurations
				.is_thread_safety_enabled_for_feature_handling()
		);

		ASSERT_FALSE(
			configurations
				.is_thread_safety_enabled_for_error_handling()
		);
	}
}

