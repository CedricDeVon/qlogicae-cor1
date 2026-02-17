#include "pch.hpp"

#include "../includes/character_domain_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	CharacterDomainEnumManagerConfigurations
		::CharacterDomainEnumManagerConfigurations() :
			AbstractConfigurations<CharacterDomainEnumManagerConfigurations>()
	{
		type =
			CharacterDomain
				::ALPHABETIC;
	}

	CharacterDomainEnumManagerConfigurations
		CharacterDomainEnumManagerConfigurations
			::initial_configurations;

	CharacterDomainEnumManagerConfigurations
		CharacterDomainEnumManagerConfigurations
			::default_configurations =
				CharacterDomainEnumManagerConfigurations
					::initial_configurations;
}

