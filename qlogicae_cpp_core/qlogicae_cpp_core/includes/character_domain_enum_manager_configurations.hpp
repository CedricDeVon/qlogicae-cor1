#pragma once

#include "character_domain.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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
