#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		ValidationManagerConfigurations :
			AbstractConfigurations<ValidationManagerConfigurations>
	{
	public:	
		std::function<bool()>
			conditional_callback =
				default_configurations
					.conditional_callback;

		static ValidationManagerConfigurations
			initial_configurations;

		static ValidationManagerConfigurations
			default_configurations;
		
		ValidationManagerConfigurations();
	};
}
