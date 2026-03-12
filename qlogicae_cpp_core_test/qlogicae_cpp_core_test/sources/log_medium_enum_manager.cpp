#include "pch.hpp"

#include "../includes/log_medium_enum_manager.hpp"

namespace
	QLogicae::Cor::V1::Tests
{
	class LogMediumEnumManagerTest :
		public ::testing::Test
	{
	public:
		LogMediumEnumManager manager;

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

	TEST_F(LogMediumEnumManagerTest, Should_ReturnNone_When_InvalidString)
	{
		std::string invalid_string = "INVALID_VALUE";
		LogMedium result = manager.convert_string_to_enum(invalid_string);
		EXPECT_EQ(result, LogMedium::NONE);
	}

	TEST_F(LogMediumEnumManagerTest, Should_ReturnNoneString_When_RuntimeExecutionDisabled)
	{
		LogMediumEnumManagerConfigurations configurations;
		configurations.is_feature_runtime_execution_handling_enabled = false;
		manager.setup(configurations);
		std::string converted = manager.convert_enum_to_string(LogMedium::FILE);
		EXPECT_EQ(converted, "NONE");
	}

	TEST_F(LogMediumEnumManagerTest, Should_ReturnNoneEnum_When_RuntimeExecutionDisabled)
	{
		LogMediumEnumManagerConfigurations configurations;
		configurations.is_feature_runtime_execution_handling_enabled = false;
		manager.setup(configurations);
		LogMedium result = manager.convert_string_to_enum("FILE");
		EXPECT_EQ(result, LogMedium::NONE);
	}

	TEST_F(LogMediumEnumManagerTest, Should_HandleThreadSafetyDisabled)
	{
		LogMediumEnumManagerConfigurations configurations;
		configurations.is_thread_safety_handling_enabled = false;
		manager.setup(configurations);

		std::string converted = manager.convert_enum_to_string(LogMedium::CONSOLE);
		EXPECT_EQ(converted, "CONSOLE");

		LogMedium result = manager.convert_string_to_enum("CONSOLE");
		EXPECT_EQ(result, LogMedium::CONSOLE);
	}

	TEST_F(LogMediumEnumManagerTest, Should_HandleExceptionsGracefully)
	{
		class ExceptionThrower : public LogMediumEnumManager
		{
		public:
			std::string convert_enum_to_string(const LogMedium&)
			{
				throw std::runtime_error("forced exception");
			}
		};

		ExceptionThrower test_manager;
		EXPECT_THROW(test_manager.convert_enum_to_string(LogMedium::ALL), std::runtime_error);
	}

	TEST_F(LogMediumEnumManagerTest, Should_HandleAsyncConversionWithDifferentConfigurations)
	{
		LogMediumEnumManagerConfigurations configurations;
		configurations.type = LogMedium::FILE;
		manager.setup(configurations);

		auto future_result = std::async(std::launch::async, [&]()
		{
			return manager.convert_enum_to_string(LogMedium::FILE);
		});

		EXPECT_EQ(future_result.get(), "FILE");
	}

	TEST_F(LogMediumEnumManagerTest, Should_SupportHighConcurrencyStressTest)
	{
		constexpr int num_threads = 16;
		constexpr int iterations = 10000;

		std::vector<std::thread> threads;
		std::atomic<int> success_count{ 0 };

		for (int i = 0; i < num_threads; ++i)
		{
			threads.emplace_back([&]()
			{
				for (int j = 0; j < iterations; ++j)
				{
					std::string converted = manager.convert_enum_to_string(LogMedium::CONSOLE);
					LogMedium result = manager.convert_string_to_enum(converted);
					if (result == LogMedium::CONSOLE)
					{
						success_count++;
					}
				}
			});
		}

		for (auto& thread : threads)
		{
			thread.join();
		}

		EXPECT_EQ(success_count.load(), num_threads * iterations);
	}

	TEST_F(LogMediumEnumManagerTest, Should_ReturnSingletonInstanceConsistently)
	{
		LogMediumEnumManager& first_instance = SingletonManager::get_singleton<LogMediumEnumManager>();
		LogMediumEnumManager& second_instance = SingletonManager::get_singleton<LogMediumEnumManager>();
		EXPECT_EQ(&first_instance, &second_instance);
	}

	class LogMediumEnumManagerParameterizedTest :
		public LogMediumEnumManagerTest,
		public ::testing::WithParamInterface<std::pair<std::string, LogMedium>>
	{
	};

	INSTANTIATE_TEST_CASE_P(
		StringToEnumConversions,
		LogMediumEnumManagerParameterizedTest,
		::testing::Values(
			std::make_pair("ALL", LogMedium::ALL),
			std::make_pair("CONSOLE", LogMedium::CONSOLE),
			std::make_pair("FILE", LogMedium::FILE),
			std::make_pair("NONE", LogMedium::NONE),
			std::make_pair("", LogMedium::NONE),
			std::make_pair("INVALID", LogMedium::NONE)
		)
	);

	TEST_P(LogMediumEnumManagerParameterizedTest, Should_ConvertStringToEnumCorrectly)
	{
		auto param = GetParam();
		std::string input = param.first;
		LogMedium expected = param.second;

		LogMedium result = manager.convert_string_to_enum(input);
		EXPECT_EQ(result, expected);
	}

	class LogMediumEnumManagerEnumToStringParameterizedTest :
		public LogMediumEnumManagerTest,
		public ::testing::WithParamInterface<LogMedium>
	{
	};

	INSTANTIATE_TEST_CASE_P(
		EnumToStringConversions,
		LogMediumEnumManagerEnumToStringParameterizedTest,
		::testing::Values(
			LogMedium::ALL,
			LogMedium::CONSOLE,
			LogMedium::FILE,
			LogMedium::NONE
		)
	);

	TEST_P(LogMediumEnumManagerEnumToStringParameterizedTest, Should_ConvertEnumToStringCorrectly)
	{
		LogMedium input = GetParam();
		std::string result = manager.convert_enum_to_string(input);

		switch (input)
		{
			case LogMedium::ALL: EXPECT_EQ(result, "ALL"); break;
			case LogMedium::CONSOLE: EXPECT_EQ(result, "CONSOLE"); break;
			case LogMedium::FILE: EXPECT_EQ(result, "FILE"); break;
			case LogMedium::NONE: EXPECT_EQ(result, "NONE"); break;
		}
	}
}
