#include "pch.hpp"

#include "../includes/aes256_signature_cryptography_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	Aes256SignatureCryptographyManagerConfigurations
		Aes256SignatureCryptographyManagerConfigurations
			::initial_configurations =
				[]()
				{
					Aes256SignatureCryptographyManagerConfigurations
						configurations;

					return
						configurations;
				}();

	Aes256SignatureCryptographyManagerConfigurations
		Aes256SignatureCryptographyManagerConfigurations
			::default_configurations =
				Aes256SignatureCryptographyManagerConfigurations
					::initial_configurations;
}
