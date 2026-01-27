#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
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
	};
}
