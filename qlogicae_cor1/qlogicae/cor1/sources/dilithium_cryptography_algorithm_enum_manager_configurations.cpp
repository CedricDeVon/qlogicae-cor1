#include "pch.hpp"

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		FULL \
	)

#include "../includes/dilithium_cryptography_algorithm_enum_manager_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	DilithiumCryptographyAlgorithmEnumManagerConfigurations
		::DilithiumCryptographyAlgorithmEnumManagerConfigurations() :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<DilithiumCryptographyAlgorithmEnumManagerConfigurations>()
	{
		type =
			DilithiumCryptographyAlgorithm
				::DILITHIUM_3;
	}
}

#endif
