#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		RandomValueGenerationManagerConfigurations :
			AbstractConfigurations<RandomValueGenerationManagerConfigurations>
    {
	public:
		static RandomValueGenerationManagerConfigurations
			initial_configurations;

		static RandomValueGenerationManagerConfigurations
			default_configurations;
    };
}
