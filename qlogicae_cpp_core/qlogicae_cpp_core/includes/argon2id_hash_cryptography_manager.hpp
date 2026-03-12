#pragma once

#include "abstract_class.hpp"
#include "random_value_generation_manager.hpp"
#include "argon2id_hash_cryptography_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		Argon2idHashCryptographyManager :
			public AbstractClass<Argon2idHashCryptographyManagerConfigurations>
    {
    public:
		Argon2idHashCryptographyManager();

		std::string
			hash_text(
				const std::string&
					text
			);

		bool
			verify_text(
				const std::string&
					text,
				const std::string&
					hash
			);
    };
}

