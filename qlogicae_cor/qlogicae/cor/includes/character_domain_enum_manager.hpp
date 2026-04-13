#pragma once

#include "abstract_class.hpp"
#include "character_domain.hpp"
#include "character_domain_enum_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		CharacterDomainEnumManager :
			public QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<CharacterDomainEnumManagerConfigurations>
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
