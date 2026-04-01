#include "pch.hpp"

#include "../includes/gmail_api_manager_response.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
