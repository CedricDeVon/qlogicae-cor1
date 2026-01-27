#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		Argon2idHashCryptographyManagerConfigurations :
			AbstractConfigurations<Argon2idHashCryptographyManagerConfigurations>
    {
	public:
		static Argon2idHashCryptographyManagerConfigurations
			initial_configurations;

		static Argon2idHashCryptographyManagerConfigurations
			default_configurations;
    };    
}
