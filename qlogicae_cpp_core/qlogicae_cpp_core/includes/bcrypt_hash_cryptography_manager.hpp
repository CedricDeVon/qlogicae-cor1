#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "bcrypt_hash_cryptography_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		BcryptHashCryptographyManager :
			public AbstractClass<BcryptHashCryptographyManagerConfigurations>
    {
    public:
        static BcryptHashCryptographyManager&
            singleton;

		BcryptHashCryptographyManager();

		~BcryptHashCryptographyManager();

		bool
			construct();

		bool
			destruct();
		
		std::string
			hash_text(
				const std::string&
					text
			);

		bool
			verify_text(
				const std::string&
					text,
				const std::string&
					hash
			);
    };
}
