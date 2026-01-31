#include "pch.hpp"

#include "../includes/application_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	ApplicationManagerConfigurations
		::ApplicationManagerConfigurations() :
			AbstractConfigurations<ApplicationManagerConfigurations>()
	{
		
	}

	ApplicationManagerConfigurations
		ApplicationManagerConfigurations
			::initial_configurations;

	ApplicationManagerConfigurations
		ApplicationManagerConfigurations
			::default_configurations =
				ApplicationManagerConfigurations
					::initial_configurations;
}

