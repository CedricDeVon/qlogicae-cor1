#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		JsonWebTokenCryptographyManagerConfigurations :
			AbstractConfigurations<JsonWebTokenCryptographyManagerConfigurations>
    {
	public:
		std::string
			issuer =
				"issuer";

		std::chrono::seconds
			lifetime =
				std::chrono::seconds { 86'400'000 };

		std::map<std::string, std::string>
			claims = 
				{};

		JsonWebTokenCryptographyManagerConfigurations();
    };    
}
