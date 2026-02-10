#include "pch.hpp"

#include "../includes/results_status_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	ResultsStatusEnumManagerConfigurations
		::ResultsStatusEnumManagerConfigurations() :
			AbstractConfigurations<ResultsStatusEnumManagerConfigurations>()
	{
		type =
			ResultsStatus
				::GOOD;
	}

	ResultsStatusEnumManagerConfigurations
		ResultsStatusEnumManagerConfigurations
			::initial_configurations;

	ResultsStatusEnumManagerConfigurations
		ResultsStatusEnumManagerConfigurations
			::default_configurations =
				ResultsStatusEnumManagerConfigurations
					::initial_configurations;
}
