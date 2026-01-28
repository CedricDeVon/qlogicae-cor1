#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "aes256_cipher_cryptography_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		Aes256CipherCryptographyManager :
			public AbstractClass<Aes256CipherCryptographyManagerConfigurations>
    {
    public:
        static Aes256CipherCryptographyManager&
            singleton;

		Aes256CipherCryptographyManager();

		~Aes256CipherCryptographyManager();

		bool
			construct();

		bool
			destruct();

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

