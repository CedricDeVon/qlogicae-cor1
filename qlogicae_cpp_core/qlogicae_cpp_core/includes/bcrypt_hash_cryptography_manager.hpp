#pragma once

#include "abstract_class.hpp"
#include "bcrypt_hash_cryptography_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		BcryptHashCryptographyManager :
			public AbstractClass<BcryptHashCryptographyManagerConfigurations>
    {
    public:
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
