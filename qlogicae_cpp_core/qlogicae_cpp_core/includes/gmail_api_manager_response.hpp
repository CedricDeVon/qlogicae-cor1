#pragma once

#include "results_status.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		GmailApiManagerResponse
    {
		ResultsStatus
			status =
				default_configurations
					.status;

		std::string
			message =
				default_configurations
					.message;

		static GmailApiManagerResponse
			initial_configurations;

		static GmailApiManagerResponse
			default_configurations;

		GmailApiManagerResponse();
    };
}
