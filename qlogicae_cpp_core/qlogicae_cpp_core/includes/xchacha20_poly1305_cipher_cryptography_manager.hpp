#pragma once

#include "text_manager.hpp"
#include "abstract_class.hpp"
#include "xchacha20_poly1305_cipher_cryptography_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		XChaCha20Poly1305CipherCryptographyManager :
			public AbstractClass<XChaCha20Poly1305CipherCryptographyManagerConfigurations>
    {
    public:
		XChaCha20Poly1305CipherCryptographyManager();

		std::string
			encrypt_text(
				const std::string&
					text,
				const std::string&
					private_key,
				const std::string&
					nonce
			);

		std::string
			decrypt_text(
				const std::string&
					text,
				const std::string&
					private_key,
				const std::string&
					nonce
			);
    };
}
