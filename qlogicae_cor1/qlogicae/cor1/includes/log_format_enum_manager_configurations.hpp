#pragma once

#include "log_format.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		LogFormatEnumManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<LogFormatEnumManagerConfigurations>
	{
	public:	
		LogFormat
			type =
				LogFormat
					::STANDARD;

		LogFormatEnumManagerConfigurations();
	};
}
