#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		GmailApiManagerConfigurations :
			AbstractConfigurations<GmailApiManagerConfigurations>
    {
	public:			
		std::string
			subject =
				default_configurations
					.subject;

		std::string
			html_body =
				default_configurations
					.html_body;

		std::string
			plain_body =
				default_configurations
					.plain_body;

		std::string
			smtp_server =
				default_configurations
					.smtp_server;

		std::string
			sender_address =
				default_configurations
					.sender_address;

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
    };
}
