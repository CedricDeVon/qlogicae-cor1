#include "pch.hpp"

#include "../includes/bcrypt_hash_cryptography_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	BcryptHashCryptographyManagerConfigurations
		::BcryptHashCryptographyManagerConfigurations() :
			AbstractConfigurations<BcryptHashCryptographyManagerConfigurations>()
	{
		
	}

	BcryptHashCryptographyManagerConfigurations
		BcryptHashCryptographyManagerConfigurations
			::initial_configurations;

	BcryptHashCryptographyManagerConfigurations
		BcryptHashCryptographyManagerConfigurations
			::default_configurations =
				BcryptHashCryptographyManagerConfigurations
					::initial_configurations;
}
