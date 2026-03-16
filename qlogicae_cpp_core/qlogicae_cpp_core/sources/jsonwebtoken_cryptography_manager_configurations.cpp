#include "pch.hpp"

#include "../includes/jsonwebtoken_cryptography_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	JsonWebTokenCryptographyManagerConfigurations
		::JsonWebTokenCryptographyManagerConfigurations() :
			AbstractConfigurations<JsonWebTokenCryptographyManagerConfigurations>()
	{
		issuer =
			"issuer";

		lifetime =
			std::chrono::seconds { 86'400'000 };

		claims = 
			{};
	}

	JsonWebTokenCryptographyManagerConfigurations
		JsonWebTokenCryptographyManagerConfigurations
			::initial_configurations;

	JsonWebTokenCryptographyManagerConfigurations
		JsonWebTokenCryptographyManagerConfigurations
			::default_configurations =
				JsonWebTokenCryptographyManagerConfigurations
					::initial_configurations;
}
