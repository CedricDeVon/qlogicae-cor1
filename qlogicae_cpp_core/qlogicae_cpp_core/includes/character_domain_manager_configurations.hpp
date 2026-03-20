#pragma once

#include "character_domain.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		CharacterDomainManagerConfigurations :
			AbstractConfigurations<CharacterDomainManagerConfigurations>
    {
	public:
		CharacterDomain
			type =
				CharacterDomain
					::ALPHABETIC;

		CharacterDomainManagerConfigurations();
    };    
}
