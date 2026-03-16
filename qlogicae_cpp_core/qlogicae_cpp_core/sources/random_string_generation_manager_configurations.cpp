#include "pch.hpp"

#include "../includes/random_string_generation_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	RandomStringGenerationManagerConfigurations
		::RandomStringGenerationManagerConfigurations() :
			AbstractConfigurations<RandomStringGenerationManagerConfigurations>()
	{
		character_domain =
			CharacterDomain
				::ASCII_PRINTABLE;

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

