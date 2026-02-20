#include "pch.hpp"

#include "../includes/aes256_signature_cryptography_manager.hpp"

using namespace QLogicaeCppCore;

namespace
	QLogicaeCppCoreTest
{
	class
		Aes256SignatureCryptographyManagerTest :
			public ::testing::Test
	{
	public:
		Aes256SignatureCryptographyManagerTest() = default;

		Aes256SignatureCryptographyManager&
			manager =
				Aes256SignatureCryptographyManager::singleton;
	};

	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_ReturnEmptyString_When_SigningWithEmptyText)
	{
		std::string
			private_key = "01234567890123456789012345678901";
		std::string
			public_key = "01234567890123456789012345678901";

		std::string
			result =
				manager.sign_text("", public_key, private_key);

		ASSERT_EQ(result, "");
	}

	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_ReturnEmptyString_When_VerifyingEmptyText)
	{
		std::string
			public_key = "01234567890123456789012345678901";

		std::string
			result = manager.verify_text("", public_key);

		ASSERT_EQ(result, "");
	}

	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_SignAndVerifySuccessfully_When_ValidKeysAndText)
	{
		std::string
			text = "TestMessage";
		std::string
			private_key = "01234567890123456789012345678901";
		std::string
			public_key = "01234567890123456789012345678901";

		std::string
			signature =
				manager.sign_text(text, public_key, private_key);

		ASSERT_FALSE(signature.empty());

		std::string
			verified_text =
				manager.verify_text(text, public_key);

		ASSERT_EQ(verified_text, text);
	}

	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_ReturnEmptyString_When_VerifyingWithInvalidSignature)
	{
		std::string
			text = "TestMessage";
		std::string
			public_key = "01234567890123456789012345678901";

		std::string
			invalid_signature = "InvalidBase64Signature";

		std::string
			result =
				manager.verify_text(invalid_signature, public_key);

		ASSERT_EQ(result, "");
	}

	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_HandleThreadSafety_When_SigningInMultipleThreads)
	{
		std::string
			text = "ThreadSafetyTest";
		std::string
			private_key = "01234567890123456789012345678901";
		std::string
			public_key = "01234567890123456789012345678901";

		std::vector<std::thread>
			threads;

		std::atomic<size_t>
			success_count(0);

		for (size_t i = 0; i < 16; ++i)
		{
			threads.emplace_back([&]()
			{
				std::string
					signature =
						manager.sign_text(text, public_key, private_key);
				if (!signature.empty())
				{
					++success_count;
				}
			});
		}

		for (auto& thread : threads)
		{
			thread.join();
		}

		ASSERT_EQ(success_count.load(), 16);
	}

	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_HandleAsyncSigning_When_UsingFutures)
	{
		std::string
			text = "AsyncTestMessage";
		std::string
			private_key = "01234567890123456789012345678901";
		std::string
			public_key = "01234567890123456789012345678901";

		std::vector<std::future<std::string>>
			futures;

		for (size_t i = 0; i < 16; ++i)
		{
			futures.emplace_back(
				std::async(std::launch::async, [&]()
				{
					return manager.sign_text(text, public_key, private_key);
				})
			);
		}

		for (auto& future : futures)
		{
			std::string
				result = future.get();
			ASSERT_FALSE(result.empty());
		}
	}

	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_ResetConfigurationsProperly_When_ResetCalled)
	{
		ASSERT_TRUE(manager.reset());
	}

	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_SetupConfigurationsProperly_When_NewConfigProvided)
	{
		Aes256SignatureCryptographyManagerConfigurations
			new_config;

		new_config.is_feature_handling_enabled = false;
		new_config.is_error_handling_enabled = false;

		ASSERT_TRUE(manager.setup(new_config));
	}

	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_HandleExceptionSafety_When_InvalidKeysProvided)
	{
		std::string
			text = "ExceptionSafetyTest";
		std::string
			private_key = "Short";
		std::string
			public_key = "Short";

		std::string
			signature =
				manager.sign_text(text, public_key, private_key);

		ASSERT_EQ(signature, "");
	}

	class
		Aes256SignatureCryptographyManagerParameterizedTest :
			public Aes256SignatureCryptographyManagerTest,
			public ::testing::WithParamInterface<std::string>
	{
	};

	INSTANTIATE_TEST_CASE_P(
		ValidAndInvalidKeys,
		Aes256SignatureCryptographyManagerParameterizedTest,
		::testing::Values(
			"",
			"ShortKey",
			"01234567890123456789012345678901"
		)
	);

	TEST_P(Aes256SignatureCryptographyManagerParameterizedTest,
		Should_HandleEdgeCases_When_DifferentKeyLengths)
	{
		std::string
			key = GetParam();
		std::string
			text = "ParameterizedTest";

		std::string
			signature =
				manager.sign_text(text, key, key);

		if (key.size() == 32)
		{
			ASSERT_FALSE(signature.empty());
		}
		else
		{
			ASSERT_EQ(signature, "");
		}
	}

	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_HandleStress_When_HighLoadSigning)
	{
		std::string
			text = "StressTestMessage";
		std::string
			private_key = "01234567890123456789012345678901";
		std::string
			public_key = "01234567890123456789012345678901";

		std::atomic<size_t>
			success_count(0);

		for (size_t i = 0; i < 1000; ++i)
		{
			std::string
				signature =
					manager.sign_text(text, public_key, private_key);
			if (!signature.empty())
			{
				++success_count;
			}
		}

		ASSERT_EQ(success_count.load(), 1000);
	}

	
	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_HandleConcurrentSignAndVerify_When_MultipleThreads)
	{
		std::string
			text = "ConcurrentTestMessage";
		std::string
			private_key = "01234567890123456789012345678901";
		std::string
			public_key = "01234567890123456789012345678901";

		std::vector<std::thread>
			threads;

		std::atomic<size_t>
			sign_success_count(0),
			verify_success_count(0);

		for (size_t i = 0; i < 16; ++i)
		{
			threads.emplace_back([&]()
			{
				std::string
					signature =
						manager.sign_text(text, public_key, private_key);
				if (!signature.empty())
				{
					++sign_success_count;
				}

				std::string
					verified_text =
						manager.verify_text(text, public_key);
				if (!verified_text.empty())
				{
					++verify_success_count;
				}
			});
		}

		for (auto& thread : threads)
		{
			thread.join();
		}

		ASSERT_EQ(sign_success_count.load(), 16);
		ASSERT_EQ(verify_success_count.load(), 16);
	}

	class
		Aes256SignatureCryptographyManagerParameterizedTextTest :
			public Aes256SignatureCryptographyManagerTest,
			public ::testing::WithParamInterface<std::string>
	{
	};

	INSTANTIATE_TEST_CASE_P(
		LongAndUnicodeTexts,
		Aes256SignatureCryptographyManagerParameterizedTextTest,
		::testing::Values(
			"",
			"ShortText",
			std::string(10000, 'A')
		)
	);

	TEST_P(Aes256SignatureCryptographyManagerParameterizedTextTest,
		Should_HandleLongAndUnicodeTexts_When_SigningAndVerifying)
	{
		std::string
			text = GetParam();
		std::string
			private_key = "01234567890123456789012345678901";
		std::string
			public_key = "01234567890123456789012345678901";

		std::string
			signature =
				manager.sign_text(text, public_key, private_key);

		if (text.empty())
		{
			ASSERT_EQ(signature, "");
		}
		else
		{
			ASSERT_FALSE(signature.empty());
			std::string
				verified_text =
					manager.verify_text(text, public_key);
			ASSERT_EQ(verified_text, text);
		}
	}

	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_HandleHighContention_When_StressSignVerify)
	{
		std::string
			text = "HighContentionStressMessage";
		std::string
			private_key = "01234567890123456789012345678901";
		std::string
			public_key = "01234567890123456789012345678901";

		std::atomic<size_t>
			sign_success_count(0),
			verify_success_count(0);

		std::vector<std::thread>
			threads;

		for (size_t i = 0; i < 64; ++i)
		{
			threads.emplace_back([&]()
			{
				for (size_t j = 0; j < 50; ++j)
				{
					std::string
						signature =
							manager.sign_text(text, public_key, private_key);
					if (!signature.empty())
					{
						++sign_success_count;
					}
					std::string
						verified_text =
							manager.verify_text(text, public_key);
					if (!verified_text.empty())
					{
						++verify_success_count;
					}
				}
			});
		}

		for (auto& thread : threads)
		{
			thread.join();
		}

		ASSERT_EQ(sign_success_count.load(), 64 * 50);
		ASSERT_EQ(verify_success_count.load(), 64 * 50);
	}

	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_ConstructAndDestructSafely_When_ThreadSafetyEnabledOrDisabled)
	{
		Aes256SignatureCryptographyManagerConfigurations
			new_config = manager.configurations;

		new_config.is_utility_handling_thread_safety_enabled = true;
		new_config.is_feature_handling_thread_safety_enabled = true;
		new_config.is_error_handling_thread_safety_enabled = true;
		manager.setup(new_config);
		ASSERT_TRUE(manager.construct());
		ASSERT_TRUE(manager.destruct());

		new_config.is_utility_handling_thread_safety_enabled = false;
		new_config.is_feature_handling_thread_safety_enabled = false;
		new_config.is_error_handling_thread_safety_enabled = false;
		manager.setup(new_config);
		ASSERT_TRUE(manager.construct());
		ASSERT_TRUE(manager.destruct());
	}

	TEST_F(Aes256SignatureCryptographyManagerTest,
		Should_HandleExceptionPaths_When_SigningOrVerifyingInvalidKeys)
	{
		std::string
			text = "ExceptionPathTest";
		std::string
			private_key = "Short";
		std::string
			public_key = "Short";

		std::string
			signature =
				manager.sign_text(text, public_key, private_key);
		ASSERT_EQ(signature, "");

		std::string
			verified_text =
				manager.verify_text(signature, public_key);
		ASSERT_EQ(verified_text, "");
	}
}