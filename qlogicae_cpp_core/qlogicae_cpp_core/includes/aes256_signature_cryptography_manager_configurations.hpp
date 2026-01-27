#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		Aes256SignatureCryptographyManagerConfigurations :
			AbstractConfigurations<Aes256SignatureCryptographyManagerConfigurations>
    {
	public:
		static Aes256SignatureCryptographyManagerConfigurations
			initial_configurations;

		static Aes256SignatureCryptographyManagerConfigurations
			default_configurations;
    };    
}
