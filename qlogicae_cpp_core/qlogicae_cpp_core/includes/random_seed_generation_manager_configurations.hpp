#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		RandomSeedGenerationManagerConfigurations :
			AbstractConfigurations<RandomSeedGenerationManagerConfigurations>
    {
	public:
		static RandomSeedGenerationManagerConfigurations
			initial_configurations;

		static RandomSeedGenerationManagerConfigurations
			default_configurations;

		RandomSeedGenerationManagerConfigurations();
    };
}
