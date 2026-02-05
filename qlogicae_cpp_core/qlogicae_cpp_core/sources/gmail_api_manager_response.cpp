#include "pch.hpp"

#include "../includes/gmail_api_manager_response.hpp"

namespace
	QLogicaeCppCore
{
	GmailApiManagerResponse
		::GmailApiManagerResponse()
	{		
		error_message =
			"";
	}

	GmailApiManagerResponse
		GmailApiManagerResponse
			::initial_configurations;

	GmailApiManagerResponse
		GmailApiManagerResponse
			::default_configurations =
				GmailApiManagerResponse
					::initial_configurations;
}
