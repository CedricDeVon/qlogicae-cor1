#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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
