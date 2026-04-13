#include "pch.hpp"

#include "../includes/kyber_cryptography_manager_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	KyberCryptographyManagerConfigurations
		::KyberCryptographyManagerConfigurations() :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<KyberCryptographyManagerConfigurations>()
	{
		algorithm =
			KyberCryptographyAlgorithm
				::KYBER_768;
	}
}
