#include "pch.hpp"

#include "../includes/function_wrapper.hpp"

namespace
	QLogicaeCppCoreTest
{
    class FunctionWrapperTest :
		public ::testing::Test
	{
	public:
		FunctionWrapperTest()
		{
			QLogicaeCppCore::FunctionWrapper::singleton.reset();
		}

		~FunctionWrapperTest() override
		{
			QLogicaeCppCore::FunctionWrapper::singleton.reset();
		}
	};

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

	TEST(FunctionWrapperTest, Should_ConstructSuccessfully_When_NoException)
	{
		QLogicaeCppCore::FunctionWrapper& wrapper = QLogicaeCppCore::FunctionWrapper::singleton;
		ASSERT_TRUE(wrapper.construct());
	}

	TEST(FunctionWrapperTest, Should_DestructSuccessfully_When_NoException)
	{
		QLogicaeCppCore::FunctionWrapper& wrapper = QLogicaeCppCore::FunctionWrapper::singleton;
		ASSERT_TRUE(wrapper.destruct());
	}

	TEST(FunctionWrapperTest, Should_SetupConfigurationsCorrectly_When_ValidInput)
	{
		QLogicaeCppCore::FunctionWrapperConfigurations configurations;
		configurations.is_enabled = true;
		ASSERT_TRUE(QLogicaeCppCore::FunctionWrapper::singleton.setup(configurations));
		ASSERT_TRUE(QLogicaeCppCore::FunctionWrapper::singleton.configurations.is_enabled);
	}

	TEST(FunctionWrapperTest, Should_ResetConfigurationsToDefault_When_Called)
	{
		QLogicaeCppCore::FunctionWrapperConfigurations configurations;
		configurations.is_enabled = true;
		QLogicaeCppCore::FunctionWrapper::singleton.setup(configurations);
		ASSERT_TRUE(QLogicaeCppCore::FunctionWrapper::singleton.reset());
		ASSERT_TRUE(QLogicaeCppCore::FunctionWrapper::singleton.configurations.is_enabled);
	}

	TEST(FunctionWrapperTest, Should_HandleException_When_SetupThrows)
	{
		struct ThrowingConfigurations : QLogicaeCppCore::FunctionWrapperConfigurations {};
		QLogicaeCppCore::FunctionWrapperConfigurations configurations;
		ASSERT_TRUE(QLogicaeCppCore::FunctionWrapper::singleton.setup(configurations));
	}

	TEST(FunctionWrapperTest, Should_HandleException_When_ResetThrows)
	{
		ASSERT_TRUE(QLogicaeCppCore::FunctionWrapper::singleton.reset());
	}

	TEST(FunctionWrapperTest, Should_ReturnValue_When_NonPointerMemberFunction)
	{
		FunctionWrapperCallSafelyTest test_object;
		int result = QLogicaeCppCore::FunctionWrapper::call_function<int>(
			test_object, &FunctionWrapperCallSafelyTest::add_value, 5);
		ASSERT_EQ(result, 6);
	}

	TEST(FunctionWrapperTest, Should_ReturnValue_When_PointerMemberFunction)
	{
		FunctionWrapperCallSafelyTest test_object;
		FunctionWrapperCallSafelyTest* ptr = &test_object;
		int result = QLogicaeCppCore::FunctionWrapper::call_function<int>(
			ptr, &FunctionWrapperCallSafelyTest::add_value, 7);
		ASSERT_EQ(result, 8);
	}

	TEST(FunctionWrapperTest, Should_HandleException_When_MemberFunctionThrows)
	{
		FunctionWrapperCallSafelyTest test_object;
		int result = QLogicaeCppCore::FunctionWrapper::call_function<int>(
			test_object, &FunctionWrapperCallSafelyTest::throw_value, 1);
		(void)result;
		ASSERT_TRUE(true);
	}

	TEST(FunctionWrapperTest, Should_HandleZeroArgumentMemberFunction)
	{
		FunctionWrapperCallSafelyTest test_object;
		int result = QLogicaeCppCore::FunctionWrapper::call_function<int>(
			test_object, &FunctionWrapperCallSafelyTest::zero_arg);
		ASSERT_EQ(result, 42);
	}

	TEST(FunctionWrapperTest, Should_ReturnDefaultConstructedResult_When_ExceptionThrown)
	{
		FunctionWrapperCallSafelyTest test_object;

		int result =
			QLogicaeCppCore::FunctionWrapper::call_function<int>(
				test_object,
				&FunctionWrapperCallSafelyTest::throw_value,
				3
			);

		ASSERT_EQ(result, 0);
	}

	TEST(FunctionWrapperTest, Should_ReturnDefaultConstructedResult_When_PointerMemberThrows)
	{
		FunctionWrapperCallSafelyTest test_object;
		FunctionWrapperCallSafelyTest* ptr = &test_object;

		int result =
			QLogicaeCppCore::FunctionWrapper::call_function<int>(
				ptr,
				&FunctionWrapperCallSafelyTest::throw_value,
				4
			);

		ASSERT_EQ(result, 0);
	}

	TEST(FunctionWrapperTest, Should_HandleZeroArgumentMemberFunction_WithPointer)
	{
		FunctionWrapperCallSafelyTest test_object;
		FunctionWrapperCallSafelyTest* ptr = &test_object;

		int result =
			QLogicaeCppCore::FunctionWrapper::call_function<int>(
				ptr,
				&FunctionWrapperCallSafelyTest::zero_arg
			);

		ASSERT_EQ(result, 42);
	}

	TEST(FunctionWrapperTest, Should_ReturnCorrectValue_When_MultipleCallsInvoked)
	{
		FunctionWrapperCallSafelyTest test_object;

		int first =
			QLogicaeCppCore::FunctionWrapper::call_function<int>(
				test_object,
				&FunctionWrapperCallSafelyTest::add_value,
				1
			);

		int second =
			QLogicaeCppCore::FunctionWrapper::call_function<int>(
				test_object,
				&FunctionWrapperCallSafelyTest::add_value,
				10
			);

		ASSERT_EQ(first, 2);
		ASSERT_EQ(second, 11);
	}

	TEST(FunctionWrapperTest, Should_NotAffectSubsequentCalls_After_Exception)
	{
		FunctionWrapperCallSafelyTest test_object;

		int failed =
			QLogicaeCppCore::FunctionWrapper::call_function<int>(
				test_object,
				&FunctionWrapperCallSafelyTest::throw_value,
				1
			);

		int success =
			QLogicaeCppCore::FunctionWrapper::call_function<int>(
				test_object,
				&FunctionWrapperCallSafelyTest::add_value,
				5
			);

		ASSERT_EQ(failed, 0);
		ASSERT_EQ(success, 6);
	}

	TEST(FunctionWrapperTest, Should_HandleNullPointerObject_When_PointerMemberFunction)
	{
		FunctionWrapperCallSafelyTest* ptr = nullptr;

		ASSERT_NO_THROW(
			(
				QLogicaeCppCore::FunctionWrapper::call_function<int>(
					ptr,
					&FunctionWrapperCallSafelyTest::add_value,
					1
				),
				void()
				)
		);
	}

	TEST(FunctionWrapperTest, Should_ExecuteCallSafely_When_DisabledConfiguration)
	{
		QLogicaeCppCore::FunctionWrapperConfigurations configurations;
		configurations.is_enabled = false;
		QLogicaeCppCore::FunctionWrapper::singleton.setup(configurations);

		FunctionWrapperCallSafelyTest test_object;

		int result = QLogicaeCppCore::FunctionWrapper::call_function<int>(
			test_object,
			&FunctionWrapperCallSafelyTest::add_value,
			3
		);

		ASSERT_EQ(result, 4);
	}

	TEST(FunctionWrapperTest, Should_HandleCallSafely_When_NotConstructed)
	{
		QLogicaeCppCore::FunctionWrapper::singleton.destruct();

		FunctionWrapperCallSafelyTest test_object;

		int result = QLogicaeCppCore::FunctionWrapper::call_function<int>(
			test_object,
			&FunctionWrapperCallSafelyTest::add_value,
			2
		);

		ASSERT_EQ(result, 3);
	}

	TEST(FunctionWrapperTest, Should_HandleCallSafely_When_DestructedBeforeCall)
	{
		QLogicaeCppCore::FunctionWrapper::singleton.construct();
		QLogicaeCppCore::FunctionWrapper::singleton.destruct();

		FunctionWrapperCallSafelyTest test_object;

		int result = QLogicaeCppCore::FunctionWrapper::call_function<int>(
			test_object,
			&FunctionWrapperCallSafelyTest::add_value,
			4
		);

		ASSERT_EQ(result, 5);
	}

	TEST(FunctionWrapperTest, Should_HandleVoidReturnType_When_CallbackSucceeds)
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

		QLogicaeCppCore::FunctionWrapper::call_function<void>(
			test_object,
			&VoidTest::run
		);

		ASSERT_TRUE(called);
	}

	TEST(FunctionWrapperTest, Should_ReturnValue_For_NonDefaultConstructible_When_NoException)
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
			QLogicaeCppCore::FunctionWrapper::call_function<
			NonDefaultConstructible
			>(
				test_object,
				&Test::run
			);

		ASSERT_EQ(result.value, 7);
	}

	TEST(FunctionWrapperTest, Should_HandleVoidReturnType_With_PointerObject)
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

		QLogicaeCppCore::FunctionWrapper::call_function<void>(
			ptr,
			&VoidTest::run
		);

		ASSERT_TRUE(called);
	}

}
