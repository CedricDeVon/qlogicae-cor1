#pragma once

#include "abstract_class.hpp"
#include "character_domain.hpp"
#include "singleton_manager.hpp"
#include "character_domain_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		CharacterDomainEnumManager :
			public AbstractClass<CharacterDomainEnumManagerConfigurations>
    {
    public:
        static CharacterDomainEnumManager&
            singleton;

		CharacterDomainEnumManager();

		std::string
			convert_enum_to_string(
				const CharacterDomain&
					value
			);

		std::string
			convert_enum_to_string();

		CharacterDomain
			convert_string_to_enum(
				const std::string&
					value
			);

		CharacterDomain
			convert_string_to_enum();
    };
}

