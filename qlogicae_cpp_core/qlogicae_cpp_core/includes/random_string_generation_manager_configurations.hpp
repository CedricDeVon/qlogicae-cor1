#pragma once

#include "character_domain.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		RandomStringGenerationManagerConfigurations :
			AbstractConfigurations<RandomStringGenerationManagerConfigurations>
    {
	public:
		CharacterDomain
			character_domain =
				default_configurations
					.character_domain;

		size_t
			length =
				default_configurations
					.length;

		static RandomStringGenerationManagerConfigurations
			initial_configurations;

		static RandomStringGenerationManagerConfigurations
			default_configurations;

		RandomStringGenerationManagerConfigurations();
    };
}

