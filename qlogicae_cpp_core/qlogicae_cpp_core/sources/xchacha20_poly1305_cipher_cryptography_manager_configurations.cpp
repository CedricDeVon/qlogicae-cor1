#include "pch.hpp"

#include "../includes/xchacha20_poly1305_cipher_cryptography_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	XChaCha20Poly1305CipherCryptographyManagerConfigurations
		XChaCha20Poly1305CipherCryptographyManagerConfigurations
			::initial_configurations =
				[]()
				{
					XChaCha20Poly1305CipherCryptographyManagerConfigurations
						configurations;

					return
						configurations;
				}();

	XChaCha20Poly1305CipherCryptographyManagerConfigurations
		XChaCha20Poly1305CipherCryptographyManagerConfigurations
			::default_configurations =
				XChaCha20Poly1305CipherCryptographyManagerConfigurations
					::initial_configurations;
}
