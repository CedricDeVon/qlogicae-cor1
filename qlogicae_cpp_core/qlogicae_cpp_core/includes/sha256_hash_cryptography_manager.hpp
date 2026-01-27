#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "sha256_hash_cryptography_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		Sha256HashCryptographyManager :
			public AbstractClass<Sha256HashCryptographyManagerConfigurations>
    {
    public:
        static Sha256HashCryptographyManager&
            singleton;

		Sha256HashCryptographyManager();

		~Sha256HashCryptographyManager();

		bool
			construct();

		bool
			destruct();
		
		std::string
			hash_text(
				const std::string&
					text,
				const std::string&
					private_key
			);

		std::string
			verify_text(
				const std::string&
					text,
				const std::string&
					private_key
			);
    };
}
