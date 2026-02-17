#include "pch.hpp"

#include "../includes/rest_api_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	RestApiManagerConfigurations
		::RestApiManagerConfigurations() :
			AbstractConfigurations<RestApiManagerConfigurations>()
	{
		
	}

	RestApiManagerConfigurations
		RestApiManagerConfigurations
			::initial_configurations;

	RestApiManagerConfigurations
		RestApiManagerConfigurations
			::default_configurations =
				RestApiManagerConfigurations
					::initial_configurations;
}
