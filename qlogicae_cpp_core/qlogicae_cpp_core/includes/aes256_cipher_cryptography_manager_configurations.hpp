#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		Aes256CipherCryptographyManagerConfigurations :
			AbstractConfigurations<Aes256CipherCryptographyManagerConfigurations>
    {
	public:
		static Aes256CipherCryptographyManagerConfigurations
			initial_configurations;

		static Aes256CipherCryptographyManagerConfigurations
			default_configurations;

		Aes256CipherCryptographyManagerConfigurations();
    };    
}

