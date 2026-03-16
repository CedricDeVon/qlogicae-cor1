#include "pch.hpp"

#include "../includes/edsca_signature_cryptography_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{	
	EdscaSignatureCryptographyManagerConfigurations
		::EdscaSignatureCryptographyManagerConfigurations() :
			AbstractConfigurations<EdscaSignatureCryptographyManagerConfigurations>()
	{
		
	}

	EdscaSignatureCryptographyManagerConfigurations
		EdscaSignatureCryptographyManagerConfigurations
			::initial_configurations;

	EdscaSignatureCryptographyManagerConfigurations
		EdscaSignatureCryptographyManagerConfigurations
			::default_configurations =
				EdscaSignatureCryptographyManagerConfigurations
					::initial_configurations;
}
