#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		WindowsSystemAccessManagerConfigurations :
			AbstractConfigurations<WindowsSystemAccessManagerConfigurations>
	{
	public:	
		static WindowsSystemAccessManagerConfigurations
			initial_configurations;

		static WindowsSystemAccessManagerConfigurations
			default_configurations;

		WindowsSystemAccessManagerConfigurations();
	};
}
