#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		EdscaSignatureCryptographyManagerConfigurations :
			AbstractConfigurations<EdscaSignatureCryptographyManagerConfigurations>
    {
	public:
		static EdscaSignatureCryptographyManagerConfigurations
			initial_configurations;

		static EdscaSignatureCryptographyManagerConfigurations
			default_configurations;

		EdscaSignatureCryptographyManagerConfigurations();
    };    
}
