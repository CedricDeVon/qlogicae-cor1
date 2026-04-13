#pragma once

#include "abstract_configurations.hpp"
#include "kyber_cryptography_algorithm.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		KyberCryptographyManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<KyberCryptographyManagerConfigurations>
    {
	public:	
		KyberCryptographyAlgorithm
			algorithm =
				KyberCryptographyAlgorithm
					::KYBER_768;

		KyberCryptographyManagerConfigurations();
    };    
}
