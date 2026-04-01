#pragma once

#include "log_format.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		LogFormatEnumManagerConfigurations :
			AbstractConfigurations<LogFormatEnumManagerConfigurations>
	{
	public:	
		LogFormat
			type =
				LogFormat
					::STANDARD;

		LogFormatEnumManagerConfigurations();
	};
}
