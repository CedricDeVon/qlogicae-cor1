#include "pch.hpp"

#include "../includes/jsonwebtoken_cryptography_manager.hpp"

using namespace QLogicaeCppCore;

namespace
	QLogicaeCppCoreTest
{
	class JsonWebTokenCryptographyManagerTest :
		public ::testing::Test
	{
	public:
		JsonWebTokenCryptographyManagerTest() = default;

		JsonWebTokenCryptographyManager&
			manager =
				JsonWebTokenCryptographyManager::singleton;
	};

	TEST_F(JsonWebTokenCryptographyManagerTest, Should_Construct_And_Destruct_Without_Exception)
	{
		EXPECT_TRUE(manager.construct());
		EXPECT_TRUE(manager.destruct());
	}

	TEST_F(JsonWebTokenCryptographyManagerTest, Should_Sign_And_Verify_Short_Text)
	{
		std::string text = "HelloWorld";
		std::string token = manager.sign_text(text, "public", "private");
		EXPECT_FALSE(token.empty());
		std::string verified = manager.verify_text(token, "public");
		EXPECT_EQ(verified, text);
	}

	TEST_F(JsonWebTokenCryptographyManagerTest, Should_Return_Empty_When_Verify_Invalid_PublicKey)
	{
		std::string text = "HelloWorld";
		std::string token = manager.sign_text(text, "public", "private");
		std::string verified = manager.verify_text(token, "wrong_public");
		EXPECT_TRUE(verified.empty());
	}

	TEST_F(JsonWebTokenCryptographyManagerTest, Should_Handle_Empty_Text)
	{
		std::string token = manager.sign_text("", "public", "private");
		EXPECT_FALSE(token.empty());
		std::string verified = manager.verify_text(token, "public");
		EXPECT_EQ(verified, "");
	}

	TEST_F(JsonWebTokenCryptographyManagerTest, Should_Handle_Long_Text)
	{
		std::string text(5000, 'x');
		std::string token = manager.sign_text(text, "public", "private");
		EXPECT_FALSE(token.empty());
		std::string verified = manager.verify_text(token, "public");
		EXPECT_EQ(verified, text);
	}

	TEST_F(JsonWebTokenCryptographyManagerTest, Should_Throw_And_Handle_Exception_When_Signing_Invalid_PrivateKey)
	{
		std::string text = "ExceptionTest";
		std::string token = manager.sign_text(text, "public", "");
		EXPECT_TRUE(token.empty());
	}

	TEST_F(JsonWebTokenCryptographyManagerTest, Should_Throw_And_Handle_Exception_When_Verifying_Invalid_Text)
	{
		std::string verified = manager.verify_text("InvalidToken", "public");
		EXPECT_TRUE(verified.empty());
	}

	TEST_F(JsonWebTokenCryptographyManagerTest, Should_Perform_Concurrent_Sign_And_Verify)
	{
		std::atomic<bool> success(true);
		auto thread_func = [&]()
		{
			std::string text = "ThreadedText";
			std::string token = manager.sign_text(text, "public", "private");
			std::string verified = manager.verify_text(token, "public");
			if (verified != text)
				success = false;
		};

		std::vector<std::thread> threads;
		for (size_t i = 0; i < 16; ++i)
			threads.emplace_back(thread_func);

		for (auto& t : threads)
			t.join();

		EXPECT_TRUE(success);
	}

	TEST_F(JsonWebTokenCryptographyManagerTest, Should_Perform_Async_Sign_And_Verify)
	{
		auto future = std::async(std::launch::async, [&]()
		{
			std::string text = "AsyncText";
			std::string token = manager.sign_text(text, "public", "private");
			return manager.verify_text(token, "public");
		});

		EXPECT_EQ(future.get(), "AsyncText");
	}

	TEST_F(JsonWebTokenCryptographyManagerTest, Should_Pass_High_Contention_Stress_Test)
	{
		std::atomic<int> failures(0);
		auto stress_func = [&]()
		{
			for (int i = 0; i < 500; ++i)
			{
				std::string text = "StressText" + std::to_string(i);
				std::string token = manager.sign_text(text, "public", "private");
				std::string verified = manager.verify_text(token, "public");
				if (verified != text)
					failures++;
			}
		};

		std::vector<std::thread> threads;
		for (size_t i = 0; i < 8; ++i)
			threads.emplace_back(stress_func);

		for (auto& t : threads)
			t.join();

		EXPECT_EQ(failures.load(), 0);
	}

	class JsonWebTokenParameterizedTest :
		public JsonWebTokenCryptographyManagerTest,
		public ::testing::WithParamInterface<std::string>
	{};

	INSTANTIATE_TEST_CASE_P(
		TextVariants,
		JsonWebTokenParameterizedTest,
		::testing::Values(
			"",
			"ShortText",
			std::string(10000, 'x')
		)
	);

	TEST_P(JsonWebTokenParameterizedTest, Should_Sign_And_Verify_Parameterized_Text)
	{
		std::string text = GetParam();
		std::string token = manager.sign_text(text, "public", "private");
		EXPECT_FALSE(token.empty());
		std::string verified = manager.verify_text(token, "public");
		EXPECT_EQ(verified, text);
	}
}
