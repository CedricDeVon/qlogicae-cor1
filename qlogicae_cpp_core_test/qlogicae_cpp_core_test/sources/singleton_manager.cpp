#include "pch.hpp"

#include "../includes/singleton_manager.hpp"

using namespace QLogicaeCppCore;

namespace QLogicaeCppCoreTest
{
    struct TestPlainStruct
    {
        int value;
    };

    class TestPlainClass
    {
    public:
        TestPlainClass() = default;

        int value;
    };

    enum class TestPlainEnum
    {
        ZERO = 0,
        ONE = 1,
        MAXIMUM = 2
    };

    class SingletonManagerTest : public ::testing::Test
    {
    public:
        SingletonManagerTest() = default;

        ~SingletonManagerTest() override = default;
    };

    class SingletonManagerTypeParameterizedTest :
        public ::testing::TestWithParam<int>
    {
    public:
        SingletonManagerTypeParameterizedTest() = default;

        ~SingletonManagerTypeParameterizedTest() override = default;
    };

    class SingletonManagerStructParameterizedTest :
        public ::testing::TestWithParam<int>
    {
    public:
        SingletonManagerStructParameterizedTest() = default;

        ~SingletonManagerStructParameterizedTest() override = default;
    };

    class SingletonManagerClassParameterizedTest :
        public ::testing::TestWithParam<int>
    {
    public:
        SingletonManagerClassParameterizedTest() = default;

        ~SingletonManagerClassParameterizedTest() override = default;
    };

    class SingletonManagerEnumParameterizedTest :
        public ::testing::TestWithParam<TestPlainEnum>
    {
    public:
        SingletonManagerEnumParameterizedTest() = default;

        ~SingletonManagerEnumParameterizedTest() override = default;
    };

    class SingletonManagerMixedTypeParameterizedTest :
        public ::testing::TestWithParam<int>
    {
    public:
        SingletonManagerMixedTypeParameterizedTest() = default;

        ~SingletonManagerMixedTypeParameterizedTest() override = default;
    };

	struct DestructionTracker
	{
		inline static std::atomic<int> destruction_count{ 0 };

		~DestructionTracker()
		{
			++destruction_count;
		}
	};

    TEST(
        SingletonManagerTest,
        Should_ReturnSameReference_Expect_SameAddress_When_GetSingletonManager
    )
    {
        SingletonManager& first_reference =
            SingletonManager::get_this_singleton();

        SingletonManager& second_reference =
            SingletonManager::get_this_singleton();

        ASSERT_EQ(
            static_cast<void*>(&first_reference),
            static_cast<void*>(&second_reference)
        );
    }

    TEST(
        SingletonManagerTest,
        Should_ReturnTrue_Expect_Success_When_ConstructCalled
    )
    {
        SingletonManager& instance_manager =
            SingletonManager::get_this_singleton();

        bool result = instance_manager.construct();

        ASSERT_TRUE(result);
    }

    TEST(
        SingletonManagerTest,
        Should_ReturnTrue_Expect_Success_When_DestructCalled
    )
    {
        SingletonManager& instance_manager =
            SingletonManager::get_this_singleton();

        bool result = instance_manager.destruct();

        ASSERT_TRUE(result);
    }

    TEST(
        SingletonManagerTest,
        Should_ReturnSameTypedInstance_Expect_SameAddress_When_GetInstanceCalled
    )
    {
        SingletonManager& instance_manager =
            SingletonManager::get_this_singleton();

        int& first_instance =
            SingletonManager::get_singleton<int>();

        int& second_instance =
            SingletonManager::get_singleton<int>();

        ASSERT_EQ(
            static_cast<void*>(&first_instance),
            static_cast<void*>(&second_instance)
        );
    }

    TEST(
        SingletonManagerTest,
        Should_ReturnDifferentTypedInstances_Expect_DifferentAddresses_When_GetInstanceCalled
    )
    {
        SingletonManager& instance_manager =
            SingletonManager::get_this_singleton();

        int& integer_instance =
            SingletonManager::get_singleton<int>();

        double& double_instance =
            SingletonManager::get_singleton<double>();

        ASSERT_NE(
            static_cast<void*>(&integer_instance),
            static_cast<void*>(&double_instance)
        );
    }

    TEST(
        SingletonManagerTest,
        Should_CompleteSuccessfully_Expect_NoException_When_CalledAsynchronously
    )
    {
        std::future<SingletonManager*> async_result =
            std::async(
                std::launch::async,
                []
                {
                    SingletonManager& instance_manager =
                        SingletonManager::get_this_singleton();

                    instance_manager.construct();

                    return static_cast<SingletonManager*>(&instance_manager);
                }
            );

        SingletonManager* result_pointer = async_result.get();

        ASSERT_NE(result_pointer, nullptr);
    }

    TEST(
        SingletonManagerTest,
        Should_ExecuteConcurrently_Expect_NoDataRace_When_MultipleThreadsCallGetInstance
    )
    {
        std::atomic<bool> execution_completed{ true };

        std::vector<std::thread> worker_threads;

        std::size_t const THREAD_COUNT = static_cast<std::size_t>(16);

        for (std::size_t index = 0; index < THREAD_COUNT; ++index)
        {
            worker_threads.emplace_back(
                [&execution_completed]
                {
                    SingletonManager& instance_manager =
                        SingletonManager::get_this_singleton();

                    int& instance_value =
                        SingletonManager::get_singleton<int>();

                    instance_value = static_cast<int>(1);

                    execution_completed.store(
                        execution_completed.load(std::memory_order_acquire),
                        std::memory_order_release
                    );
                }
            );
        }

        for (std::thread& worker_thread : worker_threads)
        {
            worker_thread.join();
        }

        ASSERT_TRUE(execution_completed.load());
    }

    TEST(
        SingletonManagerTest,
        Should_CompleteUnderLoad_Expect_NoFailure_When_StressTested
    )
    {
        SingletonManager& instance_manager =
            SingletonManager::get_this_singleton();

        std::size_t const ITERATION_COUNT =
            static_cast<std::size_t>(1'000'000);

        bool is_successful = false;

        for (std::size_t index = 0; index < ITERATION_COUNT; ++index)
        {
            is_successful = instance_manager.construct();
            is_successful = instance_manager.destruct();
        }

        ASSERT_TRUE(is_successful);
    }

    TEST(
        SingletonManagerTest,
        Should_NotThrow_Expect_NoException_When_RepeatedCallsMade
    )
    {
        SingletonManager& instance_manager =
            SingletonManager::get_this_singleton();

        ASSERT_NO_THROW(
            {
                for (std::size_t index = 0;
                     index < static_cast<std::size_t>(1000);
                     ++index)
                {
                    SingletonManager::get_singleton<int>();
                    SingletonManager::get_singleton<double>();
                }
            }
        );
    }
	    TEST_P(
        SingletonManagerStructParameterizedTest,
        Should_PersistAssignedValue_Expect_SameValue_When_Reaccessed
    )
    {
        TestPlainStruct& instance =
            SingletonManager::get_singleton<TestPlainStruct>();

        instance.value = GetParam();

        TestPlainStruct& reaccessed =
            SingletonManager::get_singleton<TestPlainStruct>();

        ASSERT_EQ(
            instance.value,
            reaccessed.value
        );
    }

    TEST_P(
        SingletonManagerStructParameterizedTest,
        Should_RemainStableAcrossMultipleWrites_Expect_SameAddress
    )
    {
        TestPlainStruct& first =
            SingletonManager::get_singleton<TestPlainStruct>();

        first.value = GetParam();

        TestPlainStruct& second =
            SingletonManager::get_singleton<TestPlainStruct>();

        second.value = GetParam() + 1;

        ASSERT_EQ(
            static_cast<void*>(&first),
            static_cast<void*>(&second)
        );
    }

    TEST_P(
        SingletonManagerClassParameterizedTest,
        Should_PersistAssignedValue_Expect_SameValue_When_Reaccessed
    )
    {
        TestPlainClass& instance =
            SingletonManager::get_singleton<TestPlainClass>();

        instance.value = GetParam();

        TestPlainClass& reaccessed =
            SingletonManager::get_singleton<TestPlainClass>();

        ASSERT_EQ(
            instance.value,
            reaccessed.value
        );
    }

    TEST_P(
        SingletonManagerClassParameterizedTest,
        Should_RemainStableAcrossMultipleWrites_Expect_SameAddress
    )
    {
        TestPlainClass& first =
            SingletonManager::get_singleton<TestPlainClass>();

        first.value = GetParam();

        TestPlainClass& second =
            SingletonManager::get_singleton<TestPlainClass>();

        second.value = GetParam() * 2;

        ASSERT_EQ(
            static_cast<void*>(&first),
            static_cast<void*>(&second)
        );
    }

    TEST_P(
        SingletonManagerEnumParameterizedTest,
        Should_PersistAssignedEnum_Expect_SameValue_When_Reaccessed
    )
    {
        TestPlainEnum& instance =
            SingletonManager::get_singleton<TestPlainEnum>();

        instance = GetParam();

        TestPlainEnum& reaccessed =
            SingletonManager::get_singleton<TestPlainEnum>();

        ASSERT_EQ(
            instance,
            reaccessed
        );
    }

    TEST_P(
        SingletonManagerEnumParameterizedTest,
        Should_OverwriteEnumValue_Expect_LastAssignment
    )
    {
        TestPlainEnum& instance =
            SingletonManager::get_singleton<TestPlainEnum>();

        instance = TestPlainEnum::ZERO;
        instance = GetParam();

        TestPlainEnum& reaccessed =
            SingletonManager::get_singleton<TestPlainEnum>();

        ASSERT_EQ(
            reaccessed,
            GetParam()
        );
    }

    TEST_P(
        SingletonManagerMixedTypeParameterizedTest,
        Should_PreserveIsolationBetweenTypes_Expect_IndependentValues
    )
    {
        TestPlainStruct& struct_instance =
            SingletonManager::get_singleton<TestPlainStruct>();

        TestPlainClass& class_instance =
            SingletonManager::get_singleton<TestPlainClass>();

        struct_instance.value = GetParam();
        class_instance.value = GetParam() + 10;

        ASSERT_NE(
            struct_instance.value,
            class_instance.value
        );
    }

    TEST_P(
        SingletonManagerMixedTypeParameterizedTest,
        Should_MaintainAddressStability_AcrossRepeatedAccess
    )
    {
        TestPlainStruct& struct_first =
            SingletonManager::get_singleton<TestPlainStruct>();

        TestPlainStruct& struct_second =
            SingletonManager::get_singleton<TestPlainStruct>();

        TestPlainClass& class_first =
            SingletonManager::get_singleton<TestPlainClass>();

        TestPlainClass& class_second =
            SingletonManager::get_singleton<TestPlainClass>();

        ASSERT_EQ(
            static_cast<void*>(&struct_first),
            static_cast<void*>(&struct_second)
        );

        ASSERT_EQ(
            static_cast<void*>(&class_first),
            static_cast<void*>(&class_second)
        );
    }

    INSTANTIATE_TEST_CASE_P(
        ExtendedStructTypeInstantiation,
        SingletonManagerStructParameterizedTest,
        ::testing::Values(
            static_cast<int>(-100),
            static_cast<int>(0),
            static_cast<int>(999)
        )
    );

    INSTANTIATE_TEST_CASE_P(
        ExtendedClassTypeInstantiation,
        SingletonManagerClassParameterizedTest,
        ::testing::Values(
            static_cast<int>(-10),
            static_cast<int>(10),
            static_cast<int>(1000)
        )
    );

    INSTANTIATE_TEST_CASE_P(
        ExtendedEnumTypeInstantiation,
        SingletonManagerEnumParameterizedTest,
        ::testing::Values(
            TestPlainEnum::ZERO,
            TestPlainEnum::ONE
        )
    );

    INSTANTIATE_TEST_CASE_P(
        ExtendedMixedTypeInstantiation,
        SingletonManagerMixedTypeParameterizedTest,
        ::testing::Values(
            static_cast<int>(1),
            static_cast<int>(42),
            static_cast<int>(256)
        )
    );

    TEST(
        SingletonManagerLifecycleTest,
        Should_AllowGetSingletonBeforeConstruct_Expect_StableInstance
    )
    {
        int& first =
            SingletonManager::get_singleton<int>();

        int& second =
            SingletonManager::get_singleton<int>();

        ASSERT_EQ(
            static_cast<void*>(&first),
            static_cast<void*>(&second)
        );
    }

    TEST(
        SingletonManagerLifecycleTest,
        Should_ReturnTrue_When_ConstructCalledMultipleTimes
    )
    {
        SingletonManager& manager =
            SingletonManager::get_this_singleton();

        ASSERT_TRUE(manager.construct());
        ASSERT_TRUE(manager.construct());
    }

    TEST(
        SingletonManagerLifecycleTest,
        Should_ReturnTrue_When_DestructCalledWithoutConstruct
    )
    {
        SingletonManager& manager =
            SingletonManager::get_this_singleton();

        ASSERT_TRUE(manager.destruct());
    }

    TEST(
        SingletonManagerLifecycleTest,
        Should_ResetStateSuccessfully_When_ResetCalledRepeatedly
    )
    {
        SingletonManager& manager =
            SingletonManager::get_this_singleton();

        ASSERT_TRUE(manager.reset());
        ASSERT_TRUE(manager.reset());
    }

    TEST(
        SingletonManagerLifecycleTest,
        Should_PreserveSingletonIdentity_Across_ConstructDestructCycles
    )
    {
        SingletonManager& manager =
            SingletonManager::get_this_singleton();

        int& first =
            SingletonManager::get_singleton<int>();

        manager.construct();
        manager.destruct();
        manager.construct();

        int& second =
            SingletonManager::get_singleton<int>();

        ASSERT_EQ(
            static_cast<void*>(&first),
            static_cast<void*>(&second)
        );
    }

    TEST(
        SingletonManagerLifecycleTest,
        Should_InvokeDestructor_OnProgramTermination
    )
    {
        {
            DestructionTracker& instance =
                SingletonManager::get_singleton<DestructionTracker>();

            static_cast<void>(instance);
        }

        ASSERT_GE(
            DestructionTracker::destruction_count.load(),
            0
        );
    }

    TEST(
        SingletonManagerLifecycleTest,
        Should_MaintainOrdering_When_ConstructThen_DestructCalled
    )
    {
        SingletonManager& manager =
            SingletonManager::get_this_singleton();

        ASSERT_TRUE(manager.construct());
        ASSERT_TRUE(manager.destruct());
    }

    TEST(
        SingletonManagerLifecycleTest,
        Should_MaintainOrdering_When_DestructThen_ConstructCalled
    )
    {
        SingletonManager& manager =
            SingletonManager::get_this_singleton();

        ASSERT_TRUE(manager.destruct());
        ASSERT_TRUE(manager.construct());
    }

    TEST(
        SingletonManagerLifecycleTest,
        Should_HandleResetBetweenConstructAndDestruct
    )
    {
        SingletonManager& manager =
            SingletonManager::get_this_singleton();

        ASSERT_TRUE(manager.construct());
        ASSERT_TRUE(manager.reset());
        ASSERT_TRUE(manager.destruct());
    }

    TEST(
        SingletonManagerLifecycleTest,
        Should_NotThrow_When_ResetCalledWithoutPriorOperations
    )
    {
        SingletonManager& manager =
            SingletonManager::get_this_singleton();

        ASSERT_NO_THROW(
            {
                manager.reset();
            }
        );
    }

	TEST(
		SingletonManagerConfigurationTest,
		Should_EnableThreadSafety_When_Configured
	)
	{
		SingletonManagerConfigurations config;
		config.is_thread_safety_enabled = true;

		SingletonManager::get_this_singleton().setup(config);

		ASSERT_TRUE(
			SingletonManagerConfigurations::cache_is_thread_safety_enabled
		);
	}

	TEST(
		SingletonManagerConfigurationTest,
		Should_DisableThreadSafety_When_Configured
	)
	{
		SingletonManagerConfigurations config;
		config.is_thread_safety_enabled = false;

		SingletonManager::get_this_singleton().setup(config);

		ASSERT_FALSE(
			SingletonManagerConfigurations::cache_is_thread_safety_enabled
		);
	}

	TEST(
		SingletonManagerConfigurationTest,
		Should_ResetToInitialDefaults_When_ResetCalled
	)
	{
		SingletonManagerConfigurations config;
		config.is_enabled = true;
		config.is_thread_safety_enabled = true;

		SingletonManager::get_this_singleton().setup(config);
		SingletonManager::get_this_singleton().reset();

		ASSERT_EQ(
			SingletonManagerConfigurations::cache_is_enabled,
			SingletonManagerConfigurations::initial_is_enabled
		);

		ASSERT_EQ(
			SingletonManagerConfigurations::cache_is_thread_safety_enabled,
			SingletonManagerConfigurations::initial_is_thread_safety_enabled
		);
	}

	TEST(
		SingletonManagerConfigurationTest,
		Should_PersistDefaults_When_SetupDefaultsCalled
	)
	{
		SingletonManagerConfigurations config;
		config.is_enabled = true;
		config.is_thread_safety_enabled = true;

		SingletonManagerConfigurations::setup_defaults(config);

		ASSERT_TRUE(
			SingletonManagerConfigurations::default_is_enabled
		);

		ASSERT_TRUE(
			SingletonManagerConfigurations::default_is_thread_safety_enabled
		);
	}

	TEST(
		SingletonManagerConcurrencyTest,
		Should_NotDeadlock_When_MultipleThreadsConstructAndDestruct
	)
	{
		std::vector<std::thread> threads;

		for (int i = 0; i < 32; ++i)
		{
			threads.emplace_back(
				[]
				{
					SingletonManager& manager =
						SingletonManager::get_this_singleton();

					manager.construct();
					manager.reset();
					manager.destruct();
				}
			);
		}

		for (auto& thread : threads)
		{
			thread.join();
		}

		SUCCEED();
	}

	TEST(
		SingletonManagerConcurrencyTest,
		Should_PreserveSingletonIdentity_UnderConcurrentLifecycleCalls
	)
	{
		int* first_address = nullptr;

		std::thread t1(
			[&first_address]
			{
				first_address =
					&SingletonManager::get_singleton<int>();
			}
		);

		std::thread t2(
			[]
			{
				SingletonManager::get_this_singleton().construct();
				SingletonManager::get_this_singleton().destruct();
			}
		);

		t1.join();
		t2.join();

		int* second_address =
			&SingletonManager::get_singleton<int>();

		ASSERT_EQ(
			static_cast<void*>(first_address),
			static_cast<void*>(second_address)
		);
	}

	struct NonDefaultConstructible
	{
		explicit NonDefaultConstructible(int) {}
	};

	TEST(
		SingletonManagerEdgeCaseTest,
		Should_FailToCompile_For_NonDefaultConstructibleType
	)
	{
		SUCCEED();
	}

	struct ThrowingConstructor
	{
		ThrowingConstructor()
		{
			throw std::runtime_error("error");
		}
	};

	TEST(
		SingletonManagerExceptionTest,
		Should_PropagateException_When_TypeConstructorThrows
	)
	{
		ASSERT_THROW(
			{
				SingletonManager::get_singleton<ThrowingConstructor>();
			},
			std::runtime_error
		);
	}

	TEST(
		SingletonManagerExceptionTest,
		Should_RemainUsable_After_ExceptionDuringInstantiation
	)
	{
		try
		{
			SingletonManager::get_singleton<ThrowingConstructor>();
		}
		catch (...)
		{
		}

		int& instance =
			SingletonManager::get_singleton<int>();

		instance = 42;

		ASSERT_EQ(instance, 42);
	}

	TEST(
		SingletonManagerOrderingTest,
		Should_MaintainCorrectOrdering_UnderInterleavedCalls
	)
	{
		SingletonManager& manager =
			SingletonManager::get_this_singleton();

		ASSERT_TRUE(manager.construct());
		ASSERT_TRUE(manager.reset());
		ASSERT_TRUE(manager.construct());
		ASSERT_TRUE(manager.destruct());
	}

	TEST(
		SingletonManagerStateTest,
		Should_ResetCachedConfigurationState
	)
	{
		SingletonManagerConfigurations config;
		config.is_enabled = true;

		SingletonManager::get_this_singleton().setup(config);
		SingletonManager::get_this_singleton().reset();

		ASSERT_EQ(
			SingletonManagerConfigurations::cache_is_enabled,
			SingletonManagerConfigurations::initial_is_enabled
		);
	}

	TEST(
		SingletonManagerStateTest,
		Should_AllowReconfiguration_AfterReset
	)
	{
		SingletonManagerConfigurations config;
		config.is_enabled = true;

		SingletonManager::get_this_singleton().reset();
		SingletonManager::get_this_singleton().setup(config);

		ASSERT_TRUE(
			SingletonManagerConfigurations::cache_is_enabled
		);
	}

	TEST(
		SingletonManagerConcurrencyTest,
		Should_AllowConcurrentTypeInstantiation
	)
	{
		std::thread t1(
			[]
			{
				SingletonManager::get_singleton<int>() = 1;
			}
		);

		std::thread t2(
			[]
			{
				SingletonManager::get_singleton<double>() = 2.0;
			}
		);

		t1.join();
		t2.join();

		ASSERT_EQ(
			SingletonManager::get_singleton<int>(),
			1
		);

		ASSERT_EQ(
			SingletonManager::get_singleton<double>(),
			2.0
		);
	}

	TEST(
		SingletonManagerLifecycleTest,
		Should_NotInvalidateInstances_OnReset
	)
	{
		int& first =
			SingletonManager::get_singleton<int>();

		first = 7;

		SingletonManager::get_this_singleton().reset();

		int& second =
			SingletonManager::get_singleton<int>();

		ASSERT_EQ(
			static_cast<void*>(&first),
			static_cast<void*>(&second)
		);

		ASSERT_EQ(second, 7);
	}

}
