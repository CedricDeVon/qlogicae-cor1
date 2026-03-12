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
				default_configurations
					.type;

		static UuidEnumManagerConfigurations
			initial_configurations;

		static UuidEnumManagerConfigurations
			default_configurations;

		UuidEnumManagerConfigurations();
	};
}
