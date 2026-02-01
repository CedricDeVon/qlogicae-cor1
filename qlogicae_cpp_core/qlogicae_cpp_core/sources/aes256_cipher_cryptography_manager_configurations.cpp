#include "pch.hpp"

#include "../includes/aes256_cipher_cryptography_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	Aes256CipherCryptographyManagerConfigurations
		::Aes256CipherCryptographyManagerConfigurations() :
			AbstractConfigurations<Aes256CipherCryptographyManagerConfigurations>()
	{
		
	}

	Aes256CipherCryptographyManagerConfigurations
		Aes256CipherCryptographyManagerConfigurations
			::initial_configurations;

	Aes256CipherCryptographyManagerConfigurations
		Aes256CipherCryptographyManagerConfigurations
			::default_configurations =
				Aes256CipherCryptographyManagerConfigurations
					::initial_configurations;
}
