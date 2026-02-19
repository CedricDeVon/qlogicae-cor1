#pragma once

#include "abstract_class.hpp"
#include "character_domain.hpp"
#include "singleton_manager.hpp"
#include "character_domain_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		CharacterDomainManager :
			public AbstractClass<CharacterDomainManagerConfigurations>
    {
    public:		
        static CharacterDomainManager&
            singleton;

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
