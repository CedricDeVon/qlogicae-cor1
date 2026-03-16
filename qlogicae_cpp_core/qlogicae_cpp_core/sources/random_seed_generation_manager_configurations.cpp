#include "pch.hpp"

#include "../includes/random_seed_generation_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	RandomSeedGenerationManagerConfigurations
		::RandomSeedGenerationManagerConfigurations() :
			AbstractConfigurations<RandomSeedGenerationManagerConfigurations>()
	{
		
	}

	RandomSeedGenerationManagerConfigurations
		RandomSeedGenerationManagerConfigurations
			::initial_configurations;

	RandomSeedGenerationManagerConfigurations
		RandomSeedGenerationManagerConfigurations
			::default_configurations =
				RandomSeedGenerationManagerConfigurations
					::initial_configurations;
}
