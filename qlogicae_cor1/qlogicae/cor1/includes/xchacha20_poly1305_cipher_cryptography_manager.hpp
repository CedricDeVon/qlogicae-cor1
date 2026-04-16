#pragma once

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		XChaCha20Poly1305CipherCryptographyManager \
	)

#include "text_manager.hpp"
#include "abstract_class.hpp"
#include "xchacha20_poly1305_cipher_cryptography_manager_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		XChaCha20Poly1305CipherCryptographyManager :
			public QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<XChaCha20Poly1305CipherCryptographyManagerConfigurations>
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

#endif
