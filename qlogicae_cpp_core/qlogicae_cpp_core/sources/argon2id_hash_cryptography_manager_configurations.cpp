#include "pch.hpp"

#include "../includes/argon2id_hash_cryptography_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	Argon2idHashCryptographyManagerConfigurations
		::Argon2idHashCryptographyManagerConfigurations() :
			AbstractConfigurations<Argon2idHashCryptographyManagerConfigurations>()
	{
		
	}

	Argon2idHashCryptographyManagerConfigurations
		Argon2idHashCryptographyManagerConfigurations
			::initial_configurations;

	Argon2idHashCryptographyManagerConfigurations
		Argon2idHashCryptographyManagerConfigurations
			::default_configurations =
				Argon2idHashCryptographyManagerConfigurations
					::initial_configurations;
}
