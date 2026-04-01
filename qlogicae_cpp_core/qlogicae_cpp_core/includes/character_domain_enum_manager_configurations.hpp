#pragma once

#include "character_domain.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		CharacterDomainEnumManagerConfigurations :
			AbstractConfigurations<CharacterDomainEnumManagerConfigurations>
    {
	public:
		CharacterDomain
			type =
				CharacterDomain
					::ALPHABETIC;

		CharacterDomainEnumManagerConfigurations();
    };    
}
