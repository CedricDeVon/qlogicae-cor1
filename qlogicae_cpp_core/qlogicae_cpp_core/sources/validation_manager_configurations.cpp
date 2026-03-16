#include "pch.hpp"

#include "../includes/validation_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	ValidationManagerConfigurations
		::ValidationManagerConfigurations() :
			AbstractConfigurations<ValidationManagerConfigurations>()
	{
		conditional_callback =
			[]() { return true; };
	}

	ValidationManagerConfigurations
		ValidationManagerConfigurations
			::initial_configurations;

	ValidationManagerConfigurations
		ValidationManagerConfigurations
			::default_configurations =
				ValidationManagerConfigurations
					::initial_configurations;
}
