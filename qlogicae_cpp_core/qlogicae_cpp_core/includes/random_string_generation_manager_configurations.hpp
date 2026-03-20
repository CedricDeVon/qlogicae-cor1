#pragma once

#include "character_domain.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    struct
		RandomStringGenerationManagerConfigurations :
			AbstractConfigurations<RandomStringGenerationManagerConfigurations>
    {
	public:
		CharacterDomain
			character_domain =
				CharacterDomain
					::ASCII_PRINTABLE;

		size_t
			length =
				32;

		RandomStringGenerationManagerConfigurations();
    };
}

