#include "pch.hpp"

#include "../includes/time_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TimeManagerConfigurations
		TimeManagerConfigurations
			::initial_configurations =
				[]()
				{
					TimeManagerConfigurations
						configurations;
				
					configurations
						.time_zone =
							TimeZone::UTC;
					

					return
						configurations;
				}();

	TimeManagerConfigurations
		TimeManagerConfigurations
			::default_configurations =
				TimeManagerConfigurations
					::initial_configurations;
}
