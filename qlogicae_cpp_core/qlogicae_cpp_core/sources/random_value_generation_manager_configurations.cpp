#include "pch.hpp"

#include "../includes/random_value_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	RandomValueGenerationManagerConfigurations
		::RandomValueGenerationManagerConfigurations() :
			AbstractConfigurations<RandomValueGenerationManagerConfigurations>()
	{
		
	}

	RandomValueGenerationManagerConfigurations
		RandomValueGenerationManagerConfigurations
			::initial_configurations;

	RandomValueGenerationManagerConfigurations
		RandomValueGenerationManagerConfigurations
			::default_configurations =
				RandomValueGenerationManagerConfigurations
					::initial_configurations;
}
