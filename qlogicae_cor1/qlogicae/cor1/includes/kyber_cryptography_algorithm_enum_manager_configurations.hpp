#pragma once

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		FULL \
	)

#include "abstract_configurations.hpp"
#include "kyber_cryptography_algorithm.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		KyberCryptographyAlgorithmEnumManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<KyberCryptographyAlgorithmEnumManagerConfigurations>
    {
	public:	
		KyberCryptographyAlgorithm
			type =
				KyberCryptographyAlgorithm
					::KYBER_768;

		KyberCryptographyAlgorithmEnumManagerConfigurations();
    };    
}

#endif
