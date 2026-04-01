#pragma once

#include "abstract_class.hpp"
#include "character_domain.hpp"
#include "character_domain_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		CharacterDomainManager :
			public AbstractClass<CharacterDomainManagerConfigurations>
    {
    public:		
		CharacterDomainManager();

		~CharacterDomainManager();

		bool
			construct();

		bool
			destruct();

		std::string
			get_value(
				const CharacterDomain&
					character_domain
			);

		std::string
			get_value();
    };
}
