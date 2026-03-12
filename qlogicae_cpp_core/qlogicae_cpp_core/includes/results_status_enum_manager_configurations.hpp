#pragma once

#include "results_status.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		ResultsStatusEnumManagerConfigurations :
			AbstractConfigurations<ResultsStatusEnumManagerConfigurations>
	{
	public:	
		ResultsStatus
			type =
				default_configurations
					.type;

		static ResultsStatusEnumManagerConfigurations
			initial_configurations;

		static ResultsStatusEnumManagerConfigurations
			default_configurations;

		ResultsStatusEnumManagerConfigurations();
	};
}
