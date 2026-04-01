#pragma once

#include "time_format.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		TimeFormatEnumManagerConfigurations :
			AbstractConfigurations<TimeFormatEnumManagerConfigurations>
	{
	public:	
		TimeFormat
			type =
				TimeFormat
					::FULL_TIMESTAMP;

		TimeFormatEnumManagerConfigurations();
	};
}
