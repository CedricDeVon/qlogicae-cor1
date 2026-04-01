#pragma once

#include "character_domain.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
