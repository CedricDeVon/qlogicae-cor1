#pragma once

#include "character_domain.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		CharacterDomainManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<CharacterDomainManagerConfigurations>
    {
	public:
		CharacterDomain
			type =
				CharacterDomain
					::ALPHABETIC;

		CharacterDomainManagerConfigurations();
    };    
}
