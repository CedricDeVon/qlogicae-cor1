#include "pch.hpp"

#include "../includes/bcrypt_hash_cryptography_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	BcryptHashCryptographyManagerConfigurations
		BcryptHashCryptographyManagerConfigurations
			::initial_configurations =
				[]()
				{
					BcryptHashCryptographyManagerConfigurations
						configurations;

					return
						configurations;
				}();

	BcryptHashCryptographyManagerConfigurations
		BcryptHashCryptographyManagerConfigurations
			::default_configurations =
				BcryptHashCryptographyManagerConfigurations
					::initial_configurations;
}
