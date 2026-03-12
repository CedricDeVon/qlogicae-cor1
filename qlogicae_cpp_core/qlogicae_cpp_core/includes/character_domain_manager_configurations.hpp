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
				default_configurations
					.type;

		static CharacterDomainManagerConfigurations
			initial_configurations;

		static CharacterDomainManagerConfigurations
			default_configurations;

		CharacterDomainManagerConfigurations();
    };    
}
