#pragma once

#include "abstract_class.hpp"
#include "character_domain.hpp"
#include "character_domain_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		CharacterDomainEnumManager :
			public AbstractClass<CharacterDomainEnumManagerConfigurations>
    {
    public:
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

