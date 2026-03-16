#pragma once

#include "file_entity.hpp"
#include "email_body.hpp"
#include "email_security.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    struct
		GmailApiManagerConfigurations :
			AbstractConfigurations<GmailApiManagerConfigurations>
    {
	public:
		bool
			is_inner_logging_enabled =
				default_configurations
					.is_inner_logging_enabled;
		
		std::string
			subject_name =
				default_configurations
					.subject_name;

		EmailBody
			email_body_type =
				default_configurations
					.email_body_type;

		EmailSecurity
			email_security_type =
				default_configurations
					.email_security_type;

		std::string
			raw_body =
				default_configurations
					.raw_body;

		std::string
			full_smtp_server_address =
				default_configurations
					.full_smtp_server_address;

		std::string
			sender_email_address =
				default_configurations
					.sender_email_address;

		std::vector<std::string>
			to_recipients =
				default_configurations
					.to_recipients;

		std::vector<std::string>
			cc_recipients =
				default_configurations
					.cc_recipients;

		std::vector<std::string>
			bcc_recipients =
				default_configurations
					.bcc_recipients;

		std::vector<FileEntity>
			attached_files =
				default_configurations
					.attached_files;

		std::function<std::string()>
			password_provider =
				default_configurations
					.password_provider;

		std::map<std::string, std::string>
			custom_headers =
				{};

		static GmailApiManagerConfigurations
			initial_configurations;

		static GmailApiManagerConfigurations
			default_configurations;

		GmailApiManagerConfigurations();
    };
}
