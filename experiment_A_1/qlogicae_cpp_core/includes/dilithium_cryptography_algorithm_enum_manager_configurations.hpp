#pragma once

#include "abstract_configurations.hpp"
#include "dilithium_cryptography_algorithm.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		DilithiumCryptographyAlgorithmEnumManagerConfigurations :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<DilithiumCryptographyAlgorithmEnumManagerConfigurations>
    {
	public:	
		DilithiumCryptographyAlgorithm
			type =
				DilithiumCryptographyAlgorithm
					::DILITHIUM_3;

		DilithiumCryptographyAlgorithmEnumManagerConfigurations();
    };    
}
