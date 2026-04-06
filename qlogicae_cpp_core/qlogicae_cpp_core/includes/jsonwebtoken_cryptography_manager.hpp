#pragma once

#include "abstract_class.hpp"
#include "jsonwebtoken_cryptography_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		JsonWebTokenCryptographyManager :
			public QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<JsonWebTokenCryptographyManagerConfigurations>
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
