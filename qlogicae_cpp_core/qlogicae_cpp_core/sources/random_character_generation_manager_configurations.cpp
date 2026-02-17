#include "pch.hpp"

#include "../includes/random_character_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	RandomCharacterGenerationManagerConfigurations
		::RandomCharacterGenerationManagerConfigurations() :
			AbstractConfigurations<RandomCharacterGenerationManagerConfigurations>()
	{
		
	}

	RandomCharacterGenerationManagerConfigurations
		RandomCharacterGenerationManagerConfigurations
			::initial_configurations;

	RandomCharacterGenerationManagerConfigurations
		RandomCharacterGenerationManagerConfigurations
			::default_configurations =
				RandomCharacterGenerationManagerConfigurations
					::initial_configurations;
}

