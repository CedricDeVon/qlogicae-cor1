#pragma once

#include "time_format.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		TimeFormatEnumManagerConfigurations :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<TimeFormatEnumManagerConfigurations>
	{
	public:	
		TimeFormat
			type =
				TimeFormat
					::FULL_TIMESTAMP;

		TimeFormatEnumManagerConfigurations();
	};
}
