#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		ValidationManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<ValidationManagerConfigurations>
	{
	public:	
		std::function<bool()>
			conditional_callback =
				[]() { return true; };

		ValidationManagerConfigurations();
	};
}
