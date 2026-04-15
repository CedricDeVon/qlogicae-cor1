#pragma once

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		FULL \
	)

#include "character_domain.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		RandomStringGenerationManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<RandomStringGenerationManagerConfigurations>
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

#endif
