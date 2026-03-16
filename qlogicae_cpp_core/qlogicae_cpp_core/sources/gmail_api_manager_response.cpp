#include "pch.hpp"

#include "../includes/gmail_api_manager_response.hpp"

namespace
	QLogicae::Cor::V1
{
	GmailApiManagerResponse
		::GmailApiManagerResponse()
	{		
		status =
			ResultsStatus
				::GOOD;

		message =
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
