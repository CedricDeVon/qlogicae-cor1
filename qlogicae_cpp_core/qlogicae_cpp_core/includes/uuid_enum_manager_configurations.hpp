#pragma once

#include "uuid.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
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
