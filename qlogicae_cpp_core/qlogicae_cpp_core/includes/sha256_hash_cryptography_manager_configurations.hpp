#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		Sha256HashCryptographyManagerConfigurations :
			AbstractConfigurations<Sha256HashCryptographyManagerConfigurations>
    {
	public:
		static Sha256HashCryptographyManagerConfigurations
			initial_configurations;

		static Sha256HashCryptographyManagerConfigurations
			default_configurations;

		Sha256HashCryptographyManagerConfigurations();
    };    
}
