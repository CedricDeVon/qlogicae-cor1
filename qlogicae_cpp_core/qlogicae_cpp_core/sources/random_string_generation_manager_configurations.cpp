#include "pch.hpp"

#include "../includes/random_string_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	RandomStringGenerationManagerConfigurations
		::RandomStringGenerationManagerConfigurations() :
			AbstractConfigurations<RandomStringGenerationManagerConfigurations>()
	{
		character_domain =
			CharacterDomain
				::ASCII;

		length =
			32;
	}

	RandomStringGenerationManagerConfigurations
		RandomStringGenerationManagerConfigurations
			::initial_configurations;

	RandomStringGenerationManagerConfigurations
		RandomStringGenerationManagerConfigurations
			::default_configurations =
				RandomStringGenerationManagerConfigurations
					::initial_configurations;
}

