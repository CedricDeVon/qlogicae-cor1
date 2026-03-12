#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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

		BcryptHashCryptographyManagerConfigurations();
    };    
}

