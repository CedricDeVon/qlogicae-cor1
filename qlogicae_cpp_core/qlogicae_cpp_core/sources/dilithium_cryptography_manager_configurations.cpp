#include "pch.hpp"

#include "../includes/dilithium_cryptography_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	DilithiumCryptographyManagerConfigurations
		::DilithiumCryptographyManagerConfigurations() :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<DilithiumCryptographyManagerConfigurations>()
	{
		algorithm =
			DilithiumCryptographyAlgorithm
				::DILITHIUM_3;
	}
}
