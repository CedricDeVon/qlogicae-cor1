#pragma once

#include "uuid.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		UuidEnumManagerConfigurations :
			AbstractConfigurations<UuidEnumManagerConfigurations>
	{
	public:	
		Uuid
			type =
				Uuid
					::V4;

		UuidEnumManagerConfigurations();
	};
}
