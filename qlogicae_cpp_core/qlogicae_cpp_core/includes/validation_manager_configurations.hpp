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
				[]() { return true; };

		ValidationManagerConfigurations();
	};
}
