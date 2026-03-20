#pragma once

#include "time_format.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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
