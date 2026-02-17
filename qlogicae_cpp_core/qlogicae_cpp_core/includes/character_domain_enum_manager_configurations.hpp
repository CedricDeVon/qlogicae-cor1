#pragma once

#include "character_domain.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		CharacterDomainEnumManagerConfigurations :
			AbstractConfigurations<CharacterDomainEnumManagerConfigurations>
    {
	public:
		CharacterDomain
			type =
				default_configurations
					.type;

		static CharacterDomainEnumManagerConfigurations
			initial_configurations;

		static CharacterDomainEnumManagerConfigurations
			default_configurations;

		CharacterDomainEnumManagerConfigurations();
    };    
}
