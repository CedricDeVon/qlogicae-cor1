#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		XChaCha20Poly1305CipherCryptographyManagerConfigurations :
			AbstractConfigurations<XChaCha20Poly1305CipherCryptographyManagerConfigurations>
    {
	public:
		static XChaCha20Poly1305CipherCryptographyManagerConfigurations
			initial_configurations;

		static XChaCha20Poly1305CipherCryptographyManagerConfigurations
			default_configurations;

		XChaCha20Poly1305CipherCryptographyManagerConfigurations();
    };    
}
