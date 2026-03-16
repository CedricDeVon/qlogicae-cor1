#pragma once

#include "abstract_class.hpp"
#include "jsonwebtoken_cryptography_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		JsonWebTokenCryptographyManager :
			public AbstractClass<JsonWebTokenCryptographyManagerConfigurations>
    {
    public:
		JsonWebTokenCryptographyManager();

		std::string
			sign_text(
				const std::string&
					text,
				const std::string&
					public_key,
				const std::string&
					private_key
			);

		std::string
			verify_text(
				const std::string&
					text,
				const std::string&
					public_key
			);
	};
}
