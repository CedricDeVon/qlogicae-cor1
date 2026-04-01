#pragma once

#include "email_body.hpp"
#include "file_entity.hpp"
#include "email_security.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		GmailApiManagerConfigurations :
			AbstractConfigurations<GmailApiManagerConfigurations>
    {
	public:
		bool
			is_inner_logging_enabled =
				true;
		
		std::string
			subject_name =
				"";

		EmailBody
			email_body_type =
				EmailBody::PLAIN;

		EmailSecurity
			email_security_type =
				EmailSecurity::SSL;

		std::string
			raw_body =
				"";

		std::string
			full_smtp_server_address =
				"";

		std::string
			sender_email_address =
				"";

		std::vector<std::string>
			to_recipients =
				{};

		std::vector<std::string>
			cc_recipients =
				{};

		std::vector<std::string>
			bcc_recipients =
				{};

		std::vector<FileEntity>
			attached_files =
				{};

		std::function<std::string()>
			password_provider =
				[]() { return ""; };

		std::map<std::string, std::string>
			custom_headers =
				{};

		GmailApiManagerConfigurations();
    };
}
