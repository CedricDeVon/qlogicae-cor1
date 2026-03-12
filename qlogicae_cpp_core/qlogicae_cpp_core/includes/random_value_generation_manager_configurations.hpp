#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    struct
		RandomValueGenerationManagerConfigurations :
			AbstractConfigurations<RandomValueGenerationManagerConfigurations>
    {
	public:
		static RandomValueGenerationManagerConfigurations
			initial_configurations;

		static RandomValueGenerationManagerConfigurations
			default_configurations;

		RandomValueGenerationManagerConfigurations();
    };
}
