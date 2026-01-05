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
        SingletonManagerTypeParameterizedTest,
        Should_ReturnStableInstance_Expect_SameAddress_When_ParameterizedTypeUsed
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

    INSTANTIATE_TEST_CASE_P(
        ValidTypeInstantiation,
        SingletonManagerTypeParameterizedTest,
        ::testing::Values(
            static_cast<int>(0),
            static_cast<int>(1),
            static_cast<int>(42)
        )
    );

    TEST_P(
        SingletonManagerStructParameterizedTest,
        Should_ReturnSameInstance_Expect_SameAddress_When_StructTypeUsed
    )
    {
        SingletonManager& instance_manager =
            SingletonManager::get_this_singleton();

        TestPlainStruct& first_instance =
            SingletonManager::get_singleton<TestPlainStruct>();

        TestPlainStruct& second_instance =
            SingletonManager::get_singleton<TestPlainStruct>();

        first_instance.value = GetParam();

        ASSERT_EQ(
            static_cast<void*>(&first_instance),
            static_cast<void*>(&second_instance)
        );
    }

    INSTANTIATE_TEST_CASE_P(
        StructTypeInstantiation,
        SingletonManagerStructParameterizedTest,
        ::testing::Values(
            static_cast<int>(0),
            static_cast<int>(1),
            static_cast<int>(100)
        )
    );

    TEST_P(
        SingletonManagerClassParameterizedTest,
        Should_ReturnSameInstance_Expect_SameAddress_When_ClassTypeUsed
    )
    {
        SingletonManager& instance_manager =
            SingletonManager::get_this_singleton();

        TestPlainClass& first_instance =
            SingletonManager::get_singleton<TestPlainClass>();

        TestPlainClass& second_instance =
            SingletonManager::get_singleton<TestPlainClass>();

        first_instance.value = GetParam();

        ASSERT_EQ(
            static_cast<void*>(&first_instance),
            static_cast<void*>(&second_instance)
        );
    }

    INSTANTIATE_TEST_CASE_P(
        ClassTypeInstantiation,
        SingletonManagerClassParameterizedTest,
        ::testing::Values(
            static_cast<int>(-1),
            static_cast<int>(0),
            static_cast<int>(1)
        )
    );

    TEST_P(
        SingletonManagerEnumParameterizedTest,
        Should_ReturnSameInstance_Expect_SameAddress_When_EnumTypeUsed
    )
    {
        SingletonManager& instance_manager =
            SingletonManager::get_this_singleton();

        TestPlainEnum& first_instance =
            SingletonManager::get_singleton<TestPlainEnum>();

        TestPlainEnum& second_instance =
            SingletonManager::get_singleton<TestPlainEnum>();

        first_instance = GetParam();

        ASSERT_EQ(
            static_cast<void*>(&first_instance),
            static_cast<void*>(&second_instance)
        );
    }

    INSTANTIATE_TEST_CASE_P(
        EnumTypeInstantiation,
        SingletonManagerEnumParameterizedTest,
        ::testing::Values(
            TestPlainEnum::ZERO,
            TestPlainEnum::ONE,
            TestPlainEnum::MAXIMUM
        )
    );

    TEST_P(
        SingletonManagerMixedTypeParameterizedTest,
        Should_ReturnDifferentInstances_Expect_DifferentAddresses_When_MixedTypesUsed
    )
    {
        SingletonManager& instance_manager =
            SingletonManager::get_this_singleton();

        TestPlainStruct& struct_instance =
            SingletonManager::get_singleton<TestPlainStruct>();

        TestPlainClass& class_instance =
            SingletonManager::get_singleton<TestPlainClass>();

        TestPlainEnum& enum_instance =
            SingletonManager::get_singleton<TestPlainEnum>();

        struct_instance.value = GetParam();
        class_instance.value = GetParam();
        enum_instance = TestPlainEnum::ONE;

        ASSERT_NE(
            static_cast<void*>(&struct_instance),
            static_cast<void*>(&class_instance)
        );

        ASSERT_NE(
            static_cast<void*>(&struct_instance),
            static_cast<void*>(&enum_instance)
        );

        ASSERT_NE(
            static_cast<void*>(&class_instance),
            static_cast<void*>(&enum_instance)
        );
    }

    INSTANTIATE_TEST_CASE_P(
        MixedTypeInstantiation,
        SingletonManagerMixedTypeParameterizedTest,
        ::testing::Values(
            static_cast<int>(0),
            static_cast<int>(5)
        )
    );
}