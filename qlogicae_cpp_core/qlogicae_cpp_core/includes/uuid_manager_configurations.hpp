#pragma once

#include "uuid.hpp"
#include "text_case.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		UuidManagerConfigurations :
			AbstractConfigurations<UuidManagerConfigurations>
    {
	public:			
		Uuid
			type =
				default_configurations.type;

		static UuidManagerConfigurations
			initial_configurations;

		static UuidManagerConfigurations
			default_configurations;

		UuidManagerConfigurations();
    };
}

