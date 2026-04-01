#pragma once

#include "log_output.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		LogOutputEnumManagerConfigurations :
			AbstractConfigurations<LogOutputEnumManagerConfigurations>
	{
	public:	
		LogOutput
			type =
				LogOutput
					::ALL;

		LogOutputEnumManagerConfigurations();
	};
}
