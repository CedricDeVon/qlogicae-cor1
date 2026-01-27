#include "pch.hpp"

#include "../includes/sha256_hash_cryptography_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	Sha256HashCryptographyManagerConfigurations
		Sha256HashCryptographyManagerConfigurations
			::initial_configurations =
				[]()
				{
					Sha256HashCryptographyManagerConfigurations
						configurations;

					return
						configurations;
				}();

	Sha256HashCryptographyManagerConfigurations
		Sha256HashCryptographyManagerConfigurations
			::default_configurations =
				Sha256HashCryptographyManagerConfigurations
					::initial_configurations;
}
