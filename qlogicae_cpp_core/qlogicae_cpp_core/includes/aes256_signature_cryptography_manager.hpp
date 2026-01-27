#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "aes256_signature_cryptography_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		Aes256SignatureCryptographyManager :
			public AbstractClass<Aes256SignatureCryptographyManagerConfigurations>
    {
    public:
        static Aes256SignatureCryptographyManager&
            singleton;

		Aes256SignatureCryptographyManager();

		~Aes256SignatureCryptographyManager();

		bool
			construct();

		bool
			destruct();
		
		std::string
			sign_text(
				const std::string&
					text,
				const std::string&
					private_key,
				const std::string&
					nonce
			);

		std::string
			verify_text(
				const std::string&
					text,
				const std::string&
					private_key,
				const std::string&
					nonce
			);
    };
}
