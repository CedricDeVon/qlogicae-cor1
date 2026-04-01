#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
