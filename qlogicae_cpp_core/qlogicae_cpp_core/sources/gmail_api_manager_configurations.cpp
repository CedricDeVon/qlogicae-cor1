#include "pch.hpp"

#include "../includes/gmail_api_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	GmailApiManagerConfigurations
		::GmailApiManagerConfigurations() :
			AbstractConfigurations<GmailApiManagerConfigurations>()
	{		
		subject =
			"";

		html_body =
			"";

		plain_body =
			"";

		smtp_server =
			"";

		sender_address =
			"";

		to_recipients =
			{};

		cc_recipients =
			{};

		bcc_recipients =
			{};

		password_provider =
			[]() { return ""; };

		custom_headers =
			{};
	}

	GmailApiManagerConfigurations
		GmailApiManagerConfigurations
			::initial_configurations;

	GmailApiManagerConfigurations
		GmailApiManagerConfigurations
			::default_configurations =
				GmailApiManagerConfigurations
					::initial_configurations;
}
