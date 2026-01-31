#include "pch.hpp"

#include "../includes/function_wrapper.hpp"

namespace
	QLogicaeCppCoreTest
{
	struct NonDefaultConstructible
	{
		explicit NonDefaultConstructible(int value) : value(value) {}
		int value;
	};

	struct NonDefaultReturnTest
	{
		NonDefaultConstructible run()
		{
			throw std::runtime_error("fail");
		}
	};

	struct FunctionWrapperCallSafelyTest
	{
		int add_value(int value)
		{
			return value + 1;
		}

		int throw_value(int value)
		{
			throw std::runtime_error("fail");
			return value;
		}

		int zero_arg()
		{
			return 42;
		}
	};

    class FunctionWrapperTest :
		public ::testing::Test
	{
	public:
		QLogicaeCppCore::FunctionWrapper
			manager;

		void
			SetUp() override
		{
			manager.construct();
			manager.reset();
		}

		void
			TearDown() override
		{
			manager.destruct();
			manager.reset();
		}
	};

	TEST_F(FunctionWrapperTest, Should_ConstructSuccessfully_When_NoException)
	{
		QLogicaeCppCore::FunctionWrapper& wrapper = manager;
		ASSERT_TRUE(wrapper.construct());
	}

	TEST_F(FunctionWrapperTest, Should_DestructSuccessfully_When_NoException)
	{
		QLogicaeCppCore::FunctionWrapper& wrapper = manager;
		ASSERT_TRUE(wrapper.destruct());
	}

	TEST_F(FunctionWrapperTest, Should_SetupConfigurationsCorrectly_When_ValidInput)
	{
		QLogicaeCppCore::FunctionWrapperConfigurations configurations;
		configurations.is_feature_runtime_execution_handling_enabled = true;
		ASSERT_TRUE(manager.setup(configurations));
		ASSERT_TRUE(manager.configurations.is_feature_runtime_execution_handling_enabled);
	}

	TEST_F(FunctionWrapperTest, Should_ResetConfigurationsToDefault_When_Called)
	{
		QLogicaeCppCore::FunctionWrapperConfigurations configurations;
		configurations.is_feature_runtime_execution_handling_enabled = true;
		manager.setup(configurations);
		ASSERT_TRUE(manager.reset());
		ASSERT_TRUE(manager.configurations.is_feature_runtime_execution_handling_enabled);
	}

	TEST_F(FunctionWrapperTest, Should_HandleException_When_SetupThrows)
	{
		struct ThrowingConfigurations : QLogicaeCppCore::FunctionWrapperConfigurations {};
		QLogicaeCppCore::FunctionWrapperConfigurations configurations;
		ASSERT_TRUE(manager.setup(configurations));
	}

	TEST_F(FunctionWrapperTest, Should_HandleException_When_ResetThrows)
	{
		ASSERT_TRUE(manager.reset());
	}

	TEST_F(FunctionWrapperTest, Should_ReturnValue_When_NonPointerMemberFunction)
	{
		FunctionWrapperCallSafelyTest test_object;
		int result = manager.call_function<int>(
			test_object, &FunctionWrapperCallSafelyTest::add_value, 5);
		ASSERT_EQ(result, 6);
	}

	TEST_F(FunctionWrapperTest, Should_ReturnValue_When_PointerMemberFunction)
	{
		FunctionWrapperCallSafelyTest test_object;
		FunctionWrapperCallSafelyTest* ptr = &test_object;
		int result = manager.call_function<int>(
			ptr, &FunctionWrapperCallSafelyTest::add_value, 7);
		ASSERT_EQ(result, 8);
	}

	TEST_F(FunctionWrapperTest, Should_HandleException_When_MemberFunctionThrows)
	{
		FunctionWrapperCallSafelyTest test_object;
		ASSERT_THROW(
			manager.call_function<int>(
				test_object, &FunctionWrapperCallSafelyTest::throw_value, 1),
			std::runtime_error
		);
	}

	TEST_F(FunctionWrapperTest, Should_HandleZeroArgumentMemberFunction)
	{
		FunctionWrapperCallSafelyTest test_object;
		int result = manager.call_function<int>(
			test_object, &FunctionWrapperCallSafelyTest::zero_arg);
		ASSERT_EQ(result, 42);
	}

	TEST_F(FunctionWrapperTest, Should_ReturnDefaultConstructedResult_When_ExceptionThrown)
	{
		FunctionWrapperCallSafelyTest test_object;

		ASSERT_THROW(
			manager.call_function<int>(
				test_object, &FunctionWrapperCallSafelyTest::throw_value, 3),
			std::runtime_error
		);
	}

	TEST_F(FunctionWrapperTest, Should_ReturnDefaultConstructedResult_When_PointerMemberThrows)
	{
		FunctionWrapperCallSafelyTest test_object;
		FunctionWrapperCallSafelyTest* ptr = &test_object;

		ASSERT_THROW(
			manager.call_function<int>(
				ptr,
				&FunctionWrapperCallSafelyTest::throw_value,
				4
			),
			std::runtime_error
		);
	}

	TEST_F(FunctionWrapperTest, Should_HandleZeroArgumentMemberFunction_WithPointer)
	{
		FunctionWrapperCallSafelyTest test_object;
		FunctionWrapperCallSafelyTest* ptr = &test_object;

		int result =
			manager.call_function<int>(
				ptr,
				&FunctionWrapperCallSafelyTest::zero_arg
			);

		ASSERT_EQ(result, 42);
	}

	TEST_F(FunctionWrapperTest, Should_ReturnCorrectValue_When_MultipleCallsInvoked)
	{
		FunctionWrapperCallSafelyTest test_object;

		int first =
			manager.call_function<int>(
				test_object,
				&FunctionWrapperCallSafelyTest::add_value,
				1
			);

		int second =
			manager.call_function<int>(
				test_object,
				&FunctionWrapperCallSafelyTest::add_value,
				10
			);

		ASSERT_EQ(first, 2);
		ASSERT_EQ(second, 11);
	}

	TEST_F(FunctionWrapperTest, Should_NotAffectSubsequentCalls_After_Exception)
	{
		FunctionWrapperCallSafelyTest test_object;

		ASSERT_THROW(
			manager.call_function<int>(
				test_object, &FunctionWrapperCallSafelyTest::throw_value, 1),
			std::runtime_error
		);

		int success =
			manager.call_function<int>(
				test_object,
				&FunctionWrapperCallSafelyTest::add_value,
				5
			);

		ASSERT_EQ(success, 6);
	}

	TEST_F(FunctionWrapperTest, Should_HandleNullPointerObject_When_PointerMemberFunction)
	{
		FunctionWrapperCallSafelyTest* ptr = nullptr;

		ASSERT_NO_THROW(
			(
				manager.call_function<int>(
					ptr,
					&FunctionWrapperCallSafelyTest::add_value,
					1
				),
				void()
				)
		);
	}

	TEST_F(FunctionWrapperTest, Should_ExecuteCallSafely_When_DisabledConfiguration)
	{
		QLogicaeCppCore::FunctionWrapperConfigurations configurations;
		configurations.is_feature_runtime_execution_handling_enabled = false;
		manager.setup(configurations);

		FunctionWrapperCallSafelyTest test_object;

		int result = manager.call_function<int>(
			test_object,
			&FunctionWrapperCallSafelyTest::add_value,
			3
		);

		ASSERT_EQ(result, 4);
	}

	TEST_F(FunctionWrapperTest, Should_HandleCallSafely_When_NotConstructed)
	{
		manager.destruct();

		FunctionWrapperCallSafelyTest test_object;

		int result = manager.call_function<int>(
			test_object,
			&FunctionWrapperCallSafelyTest::add_value,
			2
		);

		ASSERT_EQ(result, 3);
	}

	TEST_F(FunctionWrapperTest, Should_HandleCallSafely_When_DestructedBeforeCall)
	{
		manager.construct();
		manager.destruct();

		FunctionWrapperCallSafelyTest test_object;

		int result = manager.call_function<int>(
			test_object,
			&FunctionWrapperCallSafelyTest::add_value,
			4
		);

		ASSERT_EQ(result, 5);
	}

	TEST_F(FunctionWrapperTest, Should_HandleVoidReturnType_When_CallbackSucceeds)
	{
		struct VoidTest
		{
			bool* flag;

			void run()
			{
				*flag = true;
			}
		};

		bool called = false;
		VoidTest test_object{ &called };

		manager.call_function<void>(
			test_object,
			&VoidTest::run
		);

		ASSERT_TRUE(called);
	}

	TEST_F(FunctionWrapperTest, Should_ReturnValue_For_NonDefaultConstructible_When_NoException)
	{
		struct NonDefaultConstructible
		{
			explicit NonDefaultConstructible(int value) : value(value) {}
			int value;
		};

		struct Test
		{
			NonDefaultConstructible run()
			{
				return NonDefaultConstructible(7);
			}
		};

		Test test_object;

		NonDefaultConstructible result =
			manager.call_function<
			NonDefaultConstructible
			>(
				test_object,
				&Test::run
			);

		ASSERT_EQ(result.value, 7);
	}

	TEST_F(FunctionWrapperTest, Should_HandleVoidReturnType_With_PointerObject)
	{
		struct VoidTest
		{
			bool* flag;

			void run()
			{
				*flag = true;
			}
		};

		bool called = false;
		VoidTest test_object{ &called };
		VoidTest* ptr = &test_object;

		manager.call_function<void>(
			ptr,
			&VoidTest::run
		);

		ASSERT_TRUE(called);
	}

}
