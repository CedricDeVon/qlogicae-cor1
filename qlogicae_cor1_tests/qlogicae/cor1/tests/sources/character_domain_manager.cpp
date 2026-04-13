#include "pch.hpp"

#include "../includes/character_domain_manager.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_TESTS_NAMESPACE_NAME
{
	class CharacterDomainManagerTest : public ::testing::Test
	{
	public:
		CharacterDomainManager manager;

		std::string get_value_thread_safe(const CharacterDomain& domain)
		{
			return manager.get_value(domain);
		}
	};

	struct CharacterDomainParam
	{
		CharacterDomain domain;
		std::string expected_string;
	};

	class CharacterDomainManagerParameterizedTest :
		public CharacterDomainManagerTest,
		public ::testing::WithParamInterface<CharacterDomainParam>
	{
	};

	const CharacterDomainParam character_domain_params[] =
	{
		{ CharacterDomain::BINARY, "01" },
		{ CharacterDomain::OCTAL, "01234567" },
		{ CharacterDomain::NUMERIC, "0123456789" },
		{ CharacterDomain::LOWERCASE_ALPHABETIC, "abcdefghijklmnopqrstuvwxyz" },
		{ CharacterDomain::UPPERCASE_ALPHABETIC, "ABCDEFGHIJKLMNOPQRSTUVWXYZ" },
		{ CharacterDomain::ALPHABETIC, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" },
		{ CharacterDomain::ALPHANUMERIC, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" },
		{ CharacterDomain::ALPHANUMERIC_LOWERCASE, "abcdefghijklmnopqrstuvwxyz0123456789" },
		{ CharacterDomain::ALPHANUMERIC_UPPERCASE, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" },
		{ CharacterDomain::ALPHANUMERIC_UNDERSCORE, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_" },
		{ CharacterDomain::HEX_LOWERCASE, "0123456789abcdef" },
		{ CharacterDomain::HEX_UPPERCASE, "0123456789ABCDEF" },
		{ CharacterDomain::BASE32_RFC4648, "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567" },
		{ CharacterDomain::BASE32_CROCKFORD, "0123456789ABCDEFGHJKMNPQRSTVWXYZ" },
		{ CharacterDomain::BASE58_BITCOIN, "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz" },
		{ CharacterDomain::BASE62, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" },
		{ CharacterDomain::BASE64_RFC4648, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/" },
		{ CharacterDomain::BASE64_URL, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_" },
		{ CharacterDomain::ASCII, "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F"
								 "\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1A\x1B\x1C\x1D\x1E\x1F"
								 " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\x7F" },
		{ CharacterDomain::ASCII_PRINTABLE, " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" },
		{ CharacterDomain::ASCII_VISIBLE, "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" },
		{ CharacterDomain::ASCII_NON_WHITESPACE_PRINTABLE, "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" },
		{ CharacterDomain::PUNCTUATION, "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~" },
		{ CharacterDomain::SYMBOLS, "$%&*+-/<=>^_`|~" },
		{ CharacterDomain::WHITESPACE, " \t\n\r\v\f" },
		{ CharacterDomain::CONTROL, "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F"
								   "\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1A\x1B\x1C\x1D\x1E\x1F\x7F" },
		{ CharacterDomain::HIGH_ENTROPY_PRINTABLE, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}|;:,.<>?/~" },
		{ CharacterDomain::HIGH_ENTROPY_ALPHANUMERIC, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+" },
		{ CharacterDomain::HIGH_ENTROPY_ASCII_VISIBLE, "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!@#$%^&*()-_=+" },
		{ CharacterDomain::HUMAN_READABLE, "ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz23456789" },
		{ CharacterDomain::PASSWORD_SAFE, " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" },
		{ CharacterDomain::PIN_CODE, "0123456789" },
		{ CharacterDomain::SLUG_SAFE, "abcdefghijklmnopqrstuvwxyz-" },
		{ CharacterDomain::URL_SAFE_RFC3986, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~" },
		{ CharacterDomain::FILE_NAME_SAFE, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._-" },
		{ CharacterDomain::PATH_SEGMENT_SAFE, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._-" },
		{ CharacterDomain::JSON_SAFE, " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" },
		{ CharacterDomain::XML_SAFE, " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" },
		{ CharacterDomain::SHELL_SAFE, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@%+=:,./-" },
		{ CharacterDomain::FUZZ_PRINTABLE, " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" },
		{ CharacterDomain::FUZZ_ASCII, "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F"
									   "\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1A\x1B\x1C\x1D\x1E\x1F"
									   " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\x7F" },
		{ CharacterDomain::EDGE_CASE_ASCII, "\x00\x01\x7F" },
		{ CharacterDomain::MIXED_CASE_STRESS, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" },
		{ CharacterDomain::EXTENDED_ASCII, "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F"
										   "\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1A\x1B\x1C\x1D\x1E\x1F"
										   " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
										   "\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8A\x8B\x8C\x8D\x8E\x8F"
										   "\x90\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9A\x9B\x9C\x9D\x9E\x9F"
										   "\xA0\xA1\xA2\xA3\xA4\xA5\xA6\xA7\xA8\xA9\xAA\xAB\xAC\xAD\xAE\xAF"
										   "\xB0\xB1\xB2\xB3\xB4\xB5\xB6\xB7\xB8\xB9\xBA\xBB\xBC\xBD\xBE\xBF"
										   "\xC0\xC1\xC2\xC3\xC4\xC5\xC6\xC7\xC8\xC9\xCA\xCB\xCC\xCD\xCE\xCF"
										   "\xD0\xD1\xD2\xD3\xD4\xD5\xD6\xD7\xD8\xD9\xDA\xDB\xDC\xDD\xDE\xDF"
										   "\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF"
										   "\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF7\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF" }
	};

	TEST_F(CharacterDomainManagerTest, Should_ConstructSuccessfully_When_RuntimeEnabled)
	{
		ASSERT_TRUE(manager.construct());
	}

	TEST_F(CharacterDomainManagerTest, Should_DestructSuccessfully_When_RuntimeEnabled)
	{
		ASSERT_TRUE(manager.destruct());
	}

	TEST_F(CharacterDomainManagerTest, Should_ReturnDefaultTypeValue_When_NoArgument)
	{
		manager.configurations.type = CharacterDomain::NUMERIC;
		ASSERT_EQ(manager.get_value(), "0123456789");
	}

	TEST_P(CharacterDomainManagerParameterizedTest,
		Should_ReturnCorrectValue_When_CharacterDomainSpecified)
	{
		const CharacterDomainParam& param = GetParam();
		ASSERT_EQ(manager.get_value(param.domain), param.expected_string);
	}

	TEST_F(CharacterDomainManagerTest,
		Should_HandleCustomDomainAndNone_When_CharacterDomainIsCustomOrNone)
	{
		ASSERT_EQ(manager.get_value(CharacterDomain::CUSTOM), "");
		ASSERT_EQ(manager.get_value(CharacterDomain::NONE), "");
	}

	TEST_F(CharacterDomainManagerTest,
		Should_HandleMultithreadedAccess_When_ConcurrentThreadsCallGetValue)
	{
		std::vector<std::thread> threads;
		std::vector<std::string> results(10);
		for (size_t i = 0; i < 10; ++i)
		{
			threads.emplace_back([&, i]()
				{
					results[i] = manager.get_value(CharacterDomain::ALPHANUMERIC);
				});
		}
		for (auto& thread : threads) thread.join();
		for (auto& result : results)
		{
			ASSERT_EQ(result, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
		}
	}

	TEST_F(CharacterDomainManagerTest,
		Should_HandleAsyncAccess_When_UsingFutures)
	{
		std::vector<std::future<std::string>> futures;
		for (size_t i = 0; i < 10; ++i)
		{
			futures.emplace_back(std::async(std::launch::async,
				[this]()
				{
					return manager.get_value(CharacterDomain::HEX_UPPERCASE);
				}));
		}
		for (auto& future : futures)
		{
			ASSERT_EQ(future.get(), "0123456789ABCDEF");
		}
	}

	TEST_F(CharacterDomainManagerTest,
		Should_HandleStress_When_CallingGetValueManyTimes)
	{
		auto start_time = std::chrono::steady_clock::now();
		for (size_t i = 0; i < 100000; ++i)
		{
			ASSERT_EQ(manager.get_value(CharacterDomain::NUMERIC), "0123456789");
		}
		auto end_time = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
		ASSERT_LT(duration.count(), 2);
	}

	TEST_F(CharacterDomainManagerTest,
		Should_CatchExceptions_When_HandleErrorOutputsThrows)
	{
		ASSERT_NO_THROW(manager.get_value(CharacterDomain::NUMERIC));
	}
	
	INSTANTIATE_TEST_CASE_P(
		CharacterDomainTests,
		CharacterDomainManagerParameterizedTest,
		::testing::ValuesIn(character_domain_params));
}
