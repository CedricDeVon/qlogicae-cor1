#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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
