#include "pch.hpp"

#include "../includes/validation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	ValidationManagerConfigurations
		ValidationManagerConfigurations
			::initial_configurations =
				[]()
				{
					ValidationManagerConfigurations
						configurations;

					configurations
						.conditional_callback =
							[]() { return true; };

					return
						configurations;
				}();

	ValidationManagerConfigurations
		ValidationManagerConfigurations
			::default_configurations =
				ValidationManagerConfigurations
					::initial_configurations;
}
