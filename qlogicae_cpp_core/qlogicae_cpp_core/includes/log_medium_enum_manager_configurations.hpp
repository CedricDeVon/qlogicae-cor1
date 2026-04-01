#pragma once

#include "log_medium.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{ 
	struct
		LogMediumEnumManagerConfigurations :
			AbstractConfigurations<LogMediumEnumManagerConfigurations>
	{
	public:	
		LogMedium
			type =
				LogMedium
					::ALL;

		LogMediumEnumManagerConfigurations();
	};
}
