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
				ResultsStatus
					::GOOD;

		std::string
			message =
				"";

		GmailApiManagerResponse();
    };
}
