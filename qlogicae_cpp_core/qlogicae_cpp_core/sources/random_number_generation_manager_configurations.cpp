#include "pch.hpp"

#include "../includes/random_number_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	RandomNumberGenerationManagerConfigurations
		::RandomNumberGenerationManagerConfigurations() :
			AbstractConfigurations<RandomNumberGenerationManagerConfigurations>()
	{
		
	}

	RandomNumberGenerationManagerConfigurations
		RandomNumberGenerationManagerConfigurations
			::initial_configurations;

	RandomNumberGenerationManagerConfigurations
		RandomNumberGenerationManagerConfigurations
			::default_configurations =
				RandomNumberGenerationManagerConfigurations
					::initial_configurations;
}

