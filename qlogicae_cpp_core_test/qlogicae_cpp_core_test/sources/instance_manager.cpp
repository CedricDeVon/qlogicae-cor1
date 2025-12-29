#include "pch.hpp"

#include "../includes/instance_manager.hpp"

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

    class InstanceManagerTest : public ::testing::Test
    {
    public:
        InstanceManagerTest() = default;

        ~InstanceManagerTest() override = default;
    };

    class InstanceManagerTypeParameterizedTest :
        public ::testing::TestWithParam<int>
    {
    public:
        InstanceManagerTypeParameterizedTest() = default;

        ~InstanceManagerTypeParameterizedTest() override = default;
    };

    class InstanceManagerStructParameterizedTest :
        public ::testing::TestWithParam<int>
    {
    public:
        InstanceManagerStructParameterizedTest() = default;

        ~InstanceManagerStructParameterizedTest() override = default;
    };

    class InstanceManagerClassParameterizedTest :
        public ::testing::TestWithParam<int>
    {
    public:
        InstanceManagerClassParameterizedTest() = default;

        ~InstanceManagerClassParameterizedTest() override = default;
    };

    class InstanceManagerEnumParameterizedTest :
        public ::testing::TestWithParam<TestPlainEnum>
    {
    public:
        InstanceManagerEnumParameterizedTest() = default;

        ~InstanceManagerEnumParameterizedTest() override = default;
    };

    class InstanceManagerMixedTypeParameterizedTest :
        public ::testing::TestWithParam<int>
    {
    public:
        InstanceManagerMixedTypeParameterizedTest() = default;

        ~InstanceManagerMixedTypeParameterizedTest() override = default;
    };


    TEST(
        InstanceManagerTest,
        Should_ReturnSameReference_Expect_SameAddress_When_GetInstanceManager
    )
    {
        InstanceManager& first_reference =
            InstanceManager::get_instance_manager();

        InstanceManager& second_reference =
            InstanceManager::get_instance_manager();

        ASSERT_EQ(
            static_cast<void*>(&first_reference),
            static_cast<void*>(&second_reference)
        );
    }

    TEST(
        InstanceManagerTest,
        Should_ReturnTrue_Expect_Success_When_ConstructCalled
    )
    {
        InstanceManager& instance_manager =
            InstanceManager::get_instance_manager();

        bool result = instance_manager.construct();

        ASSERT_TRUE(result);
    }

    TEST(
        InstanceManagerTest,
        Should_ReturnTrue_Expect_Success_When_DestructCalled
    )
    {
        InstanceManager& instance_manager =
            InstanceManager::get_instance_manager();

        bool result = instance_manager.destruct();

        ASSERT_TRUE(result);
    }

    TEST(
        InstanceManagerTest,
        Should_ReturnSameTypedInstance_Expect_SameAddress_When_GetInstanceCalled
    )
    {
        InstanceManager& instance_manager =
            InstanceManager::get_instance_manager();

        int& first_instance =
            instance_manager.get_instance<int>();

        int& second_instance =
            instance_manager.get_instance<int>();

        ASSERT_EQ(
            static_cast<void*>(&first_instance),
            static_cast<void*>(&second_instance)
        );
    }

    TEST(
        InstanceManagerTest,
        Should_ReturnDifferentTypedInstances_Expect_DifferentAddresses_When_GetInstanceCalled
    )
    {
        InstanceManager& instance_manager =
            InstanceManager::get_instance_manager();

        int& integer_instance =
            instance_manager.get_instance<int>();

        double& double_instance =
            instance_manager.get_instance<double>();

        ASSERT_NE(
            static_cast<void*>(&integer_instance),
            static_cast<void*>(&double_instance)
        );
    }

    TEST(
        InstanceManagerTest,
        Should_CompleteSuccessfully_Expect_NoException_When_CalledAsynchronously
    )
    {
        std::future<InstanceManager*> async_result =
            std::async(
                std::launch::async,
                []
                {
                    InstanceManager& instance_manager =
                        InstanceManager::get_instance_manager();

                    instance_manager.construct();

                    return static_cast<InstanceManager*>(&instance_manager);
                }
            );

        InstanceManager* result_pointer = async_result.get();

        ASSERT_NE(result_pointer, nullptr);
    }

    TEST(
        InstanceManagerTest,
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
                    InstanceManager& instance_manager =
                        InstanceManager::get_instance_manager();

                    int& instance_value =
                        instance_manager.get_instance<int>();

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
        InstanceManagerTest,
        Should_CompleteUnderLoad_Expect_NoFailure_When_StressTested
    )
    {
        InstanceManager& instance_manager =
            InstanceManager::get_instance_manager();

        std::size_t const ITERATION_COUNT =
            static_cast<std::size_t>(1'000'000);

        for (std::size_t index = 0; index < ITERATION_COUNT; ++index)
        {
            instance_manager.construct();
            instance_manager.destruct();
        }

        ASSERT_TRUE(ValueCache::boolean_1);
    }

    TEST(
        InstanceManagerTest,
        Should_NotThrow_Expect_NoException_When_RepeatedCallsMade
    )
    {
        InstanceManager& instance_manager =
            InstanceManager::get_instance_manager();

        ASSERT_NO_THROW(
            {
                for (std::size_t index = 0;
                     index < static_cast<std::size_t>(1000);
                     ++index)
                {
                    instance_manager.get_instance<int>();
                    instance_manager.get_instance<double>();
                }
            }
        );
    }

    TEST_P(
        InstanceManagerTypeParameterizedTest,
        Should_ReturnStableInstance_Expect_SameAddress_When_ParameterizedTypeUsed
    )
    {
        InstanceManager& instance_manager =
            InstanceManager::get_instance_manager();

        int& first_instance =
            instance_manager.get_instance<int>();

        int& second_instance =
            instance_manager.get_instance<int>();

        ASSERT_EQ(
            static_cast<void*>(&first_instance),
            static_cast<void*>(&second_instance)
        );
    }

    INSTANTIATE_TEST_CASE_P(
        ValidTypeInstantiation,
        InstanceManagerTypeParameterizedTest,
        ::testing::Values(
            static_cast<int>(0),
            static_cast<int>(1),
            static_cast<int>(42)
        )
    );

    TEST_P(
        InstanceManagerStructParameterizedTest,
        Should_ReturnSameInstance_Expect_SameAddress_When_StructTypeUsed
    )
    {
        InstanceManager& instance_manager =
            InstanceManager::get_instance_manager();

        TestPlainStruct& first_instance =
            instance_manager.get_instance<TestPlainStruct>();

        TestPlainStruct& second_instance =
            instance_manager.get_instance<TestPlainStruct>();

        first_instance.value = GetParam();

        ASSERT_EQ(
            static_cast<void*>(&first_instance),
            static_cast<void*>(&second_instance)
        );
    }

    INSTANTIATE_TEST_CASE_P(
        StructTypeInstantiation,
        InstanceManagerStructParameterizedTest,
        ::testing::Values(
            static_cast<int>(0),
            static_cast<int>(1),
            static_cast<int>(100)
        )
    );

    TEST_P(
        InstanceManagerClassParameterizedTest,
        Should_ReturnSameInstance_Expect_SameAddress_When_ClassTypeUsed
    )
    {
        InstanceManager& instance_manager =
            InstanceManager::get_instance_manager();

        TestPlainClass& first_instance =
            instance_manager.get_instance<TestPlainClass>();

        TestPlainClass& second_instance =
            instance_manager.get_instance<TestPlainClass>();

        first_instance.value = GetParam();

        ASSERT_EQ(
            static_cast<void*>(&first_instance),
            static_cast<void*>(&second_instance)
        );
    }

    INSTANTIATE_TEST_CASE_P(
        ClassTypeInstantiation,
        InstanceManagerClassParameterizedTest,
        ::testing::Values(
            static_cast<int>(-1),
            static_cast<int>(0),
            static_cast<int>(1)
        )
    );

    TEST_P(
        InstanceManagerEnumParameterizedTest,
        Should_ReturnSameInstance_Expect_SameAddress_When_EnumTypeUsed
    )
    {
        InstanceManager& instance_manager =
            InstanceManager::get_instance_manager();

        TestPlainEnum& first_instance =
            instance_manager.get_instance<TestPlainEnum>();

        TestPlainEnum& second_instance =
            instance_manager.get_instance<TestPlainEnum>();

        first_instance = GetParam();

        ASSERT_EQ(
            static_cast<void*>(&first_instance),
            static_cast<void*>(&second_instance)
        );
    }

    INSTANTIATE_TEST_CASE_P(
        EnumTypeInstantiation,
        InstanceManagerEnumParameterizedTest,
        ::testing::Values(
            TestPlainEnum::ZERO,
            TestPlainEnum::ONE,
            TestPlainEnum::MAXIMUM
        )
    );

    TEST_P(
        InstanceManagerMixedTypeParameterizedTest,
        Should_ReturnDifferentInstances_Expect_DifferentAddresses_When_MixedTypesUsed
    )
    {
        InstanceManager& instance_manager =
            InstanceManager::get_instance_manager();

        TestPlainStruct& struct_instance =
            instance_manager.get_instance<TestPlainStruct>();

        TestPlainClass& class_instance =
            instance_manager.get_instance<TestPlainClass>();

        TestPlainEnum& enum_instance =
            instance_manager.get_instance<TestPlainEnum>();

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
        InstanceManagerMixedTypeParameterizedTest,
        ::testing::Values(
            static_cast<int>(0),
            static_cast<int>(5)
        )
    );
}