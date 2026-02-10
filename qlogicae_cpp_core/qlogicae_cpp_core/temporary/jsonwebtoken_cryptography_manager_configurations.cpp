#include "pch.hpp"

#include "../includes/jsonwebtoken_cryptography_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	JsonWebTokenCryptographyManagerConfigurations
		JsonWebTokenCryptographyManagerConfigurations
			::initial_configurations =
				[]()
				{
					JsonWebTokenCryptographyManagerConfigurations
						configurations;

					return
						configurations;
				}();

	JsonWebTokenCryptographyManagerConfigurations
		JsonWebTokenCryptographyManagerConfigurations
			::default_configurations =
				JsonWebTokenCryptographyManagerConfigurations
					::initial_configurations;
}
