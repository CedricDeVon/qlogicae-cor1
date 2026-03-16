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
				default_configurations
					.issuer;

        std::chrono::seconds
			lifetime =
				default_configurations
					.lifetime;

        std::map<std::string, std::string>
			claims =
				{};

		static JsonWebTokenCryptographyManagerConfigurations
			initial_configurations;

		static JsonWebTokenCryptographyManagerConfigurations
			default_configurations;

		JsonWebTokenCryptographyManagerConfigurations();
    };    
}
