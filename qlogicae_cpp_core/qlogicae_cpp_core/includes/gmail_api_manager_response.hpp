#pragma once

namespace
	QLogicaeCppCore
{
    struct
		GmailApiManagerResponse
    {
		std::string
			error_message =
				default_configurations
					.error_message;

		static GmailApiManagerResponse
			initial_configurations;

		static GmailApiManagerResponse
			default_configurations;

		GmailApiManagerResponse();
    };
}
