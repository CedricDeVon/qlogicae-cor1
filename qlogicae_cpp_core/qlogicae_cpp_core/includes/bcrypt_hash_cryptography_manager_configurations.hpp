#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		BcryptHashCryptographyManagerConfigurations :
			AbstractConfigurations<BcryptHashCryptographyManagerConfigurations>
    {
	public:
		static BcryptHashCryptographyManagerConfigurations
			initial_configurations;

		static BcryptHashCryptographyManagerConfigurations
			default_configurations;
    };    
}
