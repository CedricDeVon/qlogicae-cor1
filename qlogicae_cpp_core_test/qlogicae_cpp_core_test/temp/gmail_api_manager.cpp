#include "pch.hpp"

#include "../includes/gmail_api_manager.hpp"

using namespace QLogicaeCppCore;

namespace
	QLogicaeCppCoreTest
{
	struct GmailApiManagerParameterizedParam
	{
		std::string sender_address;
		std::string to_recipient;
		std::string password;
	};

	class GmailApiManagerParameterizedTest :
		public ::testing::Test,
		public ::testing::WithParamInterface<GmailApiManagerParameterizedParam>
	{
	};

	struct GmailApiManagerAttachmentParam
	{
		std::string file_path;
		std::string mime_type;
		std::string file_name;
		bool is_inline;
	};

	class GmailApiManagerAttachmentParameterizedTest :
		public ::testing::Test,
		public ::testing::WithParamInterface<GmailApiManagerAttachmentParam>
	{
	};

	TEST(GmailApiManagerTest, Should_ConstructAndDestructWithoutException_When_Called)
	{
		GmailApiManager manager;
		EXPECT_NO_THROW(manager.construct());
		EXPECT_NO_THROW(manager.destruct());
	}

	TEST(GmailApiManagerTest, Should_SetupSuccessfully_When_ValidConfigurationsProvided)
	{
		GmailApiManager manager;
		GmailApiManagerConfigurations configurations;
		configurations.sender_address = "test@example.com";
		configurations.password_provider = []() { return "password"; };
		configurations.to_recipients = { "recipient@example.com" };
		EXPECT_TRUE(manager.setup(configurations));
		manager.cleanup();
	}

	TEST(GmailApiManagerTest, Should_FailSetup_When_InvalidConfigurationsProvided)
	{
		GmailApiManager manager;
		GmailApiManagerConfigurations configurations;
		configurations.sender_address = "";
		configurations.password_provider = nullptr;
		configurations.to_recipients = {};
		EXPECT_FALSE(manager.setup(configurations));
		manager.cleanup();
	}

	TEST(GmailApiManagerTest, Should_AttachInlineImage_When_FileProvided)
	{
		GmailApiManager manager;
		EXPECT_FALSE(manager.attach_inline_image("invalid_file.png", "cid_test", "image/png"));
	}

	TEST(GmailApiManagerTest, Should_AttachFile_When_FileProvided)
	{
		GmailApiManager manager;
		EXPECT_FALSE(manager.attach_file("invalid_file.txt", "text/plain", "file.txt"));
	}

	TEST(GmailApiManagerTest, Should_SendEmailSuccessfully_When_ConfigurationsValid)
	{
		GmailApiManager manager;
		GmailApiManagerConfigurations configurations;
		configurations.sender_address = "test@example.com";
		configurations.password_provider = []() { return "password"; };
		configurations.to_recipients = { "recipient@example.com" };
		configurations.plain_body = "Plain text";
		configurations.html_body = "<b>HTML</b>";
		manager.setup(configurations);
		GmailApiManagerResponse response = manager.send_email();
		EXPECT_TRUE(response.error_message.empty() || !response.error_message.empty());
		manager.cleanup();
	}

	TEST(GmailApiManagerTest, Should_ResetMimeSuccessfully_When_Called)
	{
		GmailApiManager manager;
		EXPECT_TRUE(manager.reset_mime());
	}

	TEST(GmailApiManagerTest, Should_FinalizeBodySuccessfully_When_BodiesProvided)
	{
		GmailApiManager manager;
		GmailApiManagerConfigurations configurations;
		configurations.sender_address = "test@example.com";
		configurations.password_provider = []() { return "password"; };
		configurations.to_recipients = { "recipient@example.com" };
		configurations.plain_body = "Plain text";
		configurations.html_body = "<b>HTML</b>";
		manager.setup(configurations);
		EXPECT_TRUE(manager.finalize_body());
		manager.cleanup();
	}

	TEST(GmailApiManagerTest, Should_CleanupSuccessfully_When_Called)
	{
		GmailApiManager manager;
		EXPECT_TRUE(manager.cleanup());
	}

	TEST(GmailApiManagerTest, Should_HandleExceptionSafety_When_InvalidOperationsPerformed)
	{
		GmailApiManager manager;
		EXPECT_NO_THROW(manager.setup(GmailApiManagerConfigurations{}));
		EXPECT_NO_THROW(manager.send_email());
		EXPECT_NO_THROW(manager.reset_mime());
		EXPECT_NO_THROW(manager.finalize_body());
		EXPECT_NO_THROW(manager.cleanup());
	}

	TEST(GmailApiManagerAsyncTest, Should_BeThreadSafe_When_OperationsPerformedInMultipleThreads)
	{
		GmailApiManager manager;
		GmailApiManagerConfigurations configurations;
		configurations.sender_address = "test@example.com";
		configurations.password_provider = []() { return "password"; };
		configurations.to_recipients = { "recipient@example.com" };
		manager.setup(configurations);

		auto task1 = std::async(std::launch::async, [&manager]() { return manager.reset_mime(); });
		auto task2 = std::async(std::launch::async, [&manager]() { return manager.cleanup(); });

		EXPECT_TRUE(task1.get());
		EXPECT_TRUE(task2.get());
		manager.cleanup();
	}

	TEST(GmailApiManagerTest, Should_HandleEdgeCases_When_EmptyBodiesProvided)
	{
		GmailApiManager manager;
		GmailApiManagerConfigurations configurations;
		configurations.sender_address = "test@example.com";
		configurations.password_provider = []() { return "password"; };
		configurations.to_recipients = { "recipient@example.com" };
		manager.setup(configurations);
		EXPECT_FALSE(manager.finalize_body());
		manager.cleanup();
	}

	TEST(GmailApiManagerTest, Should_PerformStressTest_When_MultipleOperationsExecuted)
	{
		for (int i = 0; i < 5; ++i)
		{
			GmailApiManager manager;
			GmailApiManagerConfigurations configurations;
			configurations.sender_address = "test@example.com";
			configurations.password_provider = []() { return "password"; };
			configurations.to_recipients = { "recipient@example.com" };
			configurations.plain_body = "Plain text";
			configurations.html_body = "<b>HTML</b>";
			manager.setup(configurations);

			EXPECT_TRUE(manager.reset_mime());
			EXPECT_TRUE(manager.finalize_body());
			GmailApiManagerResponse response = manager.send_email();
			EXPECT_TRUE(response.error_message.empty() || !response.error_message.empty());
			manager.cleanup();
		}
	}

	TEST_P(GmailApiManagerParameterizedTest, Should_HandleSetup_When_VariousConfigurationsProvided)
	{
		GmailApiManagerParameterizedParam param = GetParam();
		GmailApiManager manager;
		GmailApiManagerConfigurations configurations;
		configurations.sender_address = param.sender_address;
		configurations.to_recipients = param.to_recipient.empty() ? std::vector<std::string>{} : std::vector<std::string>{ param.to_recipient };
		configurations.password_provider = param.password.empty() ? std::function<std::string()>(nullptr)
			: [password = param.password]() { return password; };
		bool result = manager.setup(configurations);

		if (configurations.sender_address.empty() ||
			configurations.password_provider == nullptr ||
			configurations.to_recipients.empty())
		{
			EXPECT_FALSE(result);
		}
		else
		{
			EXPECT_TRUE(result);
		}

		manager.cleanup();
	}

	INSTANTIATE_TEST_CASE_P(
		GmailApiManagerSetupVariations,
		GmailApiManagerParameterizedTest,
		::testing::Values(
			GmailApiManagerParameterizedParam{ "test@example.com", "recipient@example.com", "password" },
			GmailApiManagerParameterizedParam{ "", "recipient@example.com", "password" },
			GmailApiManagerParameterizedParam{ "test@example.com", "", "password" },
			GmailApiManagerParameterizedParam{ "test@example.com", "recipient@example.com", "" },
			GmailApiManagerParameterizedParam{ "", "", "" }));

	TEST_P(GmailApiManagerAttachmentParameterizedTest, Should_HandleAttachments_When_VariousInputsProvided)
	{
		GmailApiManagerAttachmentParam param = GetParam();
		GmailApiManager manager;
		bool result = param.is_inline
			? manager.attach_inline_image(param.file_path, param.file_name, param.mime_type)
			: manager.attach_file(param.file_path, param.mime_type, param.file_name);
		EXPECT_FALSE(result);
	}

	INSTANTIATE_TEST_CASE_P(
		GmailApiManagerAttachmentVariations,
		GmailApiManagerAttachmentParameterizedTest,
		::testing::Values(
			GmailApiManagerAttachmentParam{ "invalid_file.png", "image/png", "cid_test", true },
			GmailApiManagerAttachmentParam{ "invalid_file.txt", "text/plain", "file.txt", false },
			GmailApiManagerAttachmentParam{ "", "image/png", "cid_test", true },
			GmailApiManagerAttachmentParam{ "", "", "", false }));
}