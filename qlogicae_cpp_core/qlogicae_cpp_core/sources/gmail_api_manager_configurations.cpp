#include "pch.hpp"

#include "../includes/gmail_api_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	GmailApiManagerConfigurations
		::GmailApiManagerConfigurations() :
			AbstractConfigurations<GmailApiManagerConfigurations>()
	{		
		is_inner_logging_enabled =
			true;

		subject_name =
			"";

		email_body_type =
			EmailBody::PLAIN;

		email_security_type =
			EmailSecurity::SSL;

		raw_body =
			"";

		full_smtp_server_address =
			"";

		sender_email_address =
			"";

		to_recipients =
			{};

		cc_recipients =
			{};

		bcc_recipients =
			{};

		attached_files =
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
