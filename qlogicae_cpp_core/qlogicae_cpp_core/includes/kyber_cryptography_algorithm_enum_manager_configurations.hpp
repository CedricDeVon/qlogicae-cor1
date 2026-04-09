#pragma once

#include "abstract_configurations.hpp"
#include "kyber_cryptography_algorithm.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		KyberCryptographyAlgorithmEnumManagerConfigurations :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<KyberCryptographyAlgorithmEnumManagerConfigurations>
    {
	public:	
		KyberCryptographyAlgorithm
			type =
				KyberCryptographyAlgorithm
					::KYBER_768;

		KyberCryptographyAlgorithmEnumManagerConfigurations();
    };    
}
