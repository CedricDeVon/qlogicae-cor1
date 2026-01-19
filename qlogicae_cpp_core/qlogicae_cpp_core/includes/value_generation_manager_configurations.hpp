#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		ValueGenerationManagerConfigurations :
			AbstractConfigurations<ValueGenerationManagerConfigurations>
    {
	public:
		static ValueGenerationManagerConfigurations
			initial_configurations;

		static ValueGenerationManagerConfigurations
			default_configurations;
    };
}
