#include "pch.hpp"

#include "../includes/character_domain_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	CharacterDomainManagerConfigurations
		::CharacterDomainManagerConfigurations() :
			AbstractConfigurations<CharacterDomainManagerConfigurations>()
	{
		type =
			CharacterDomain
				::ALPHABETIC;
	}

	CharacterDomainManagerConfigurations
		CharacterDomainManagerConfigurations
			::initial_configurations;

	CharacterDomainManagerConfigurations
		CharacterDomainManagerConfigurations
			::default_configurations =
				CharacterDomainManagerConfigurations
					::initial_configurations;
}

