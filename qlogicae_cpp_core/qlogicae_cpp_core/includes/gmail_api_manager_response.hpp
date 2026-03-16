#pragma once

#include "results_status.hpp"

namespace
	QLogicae::Cor::V1
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
