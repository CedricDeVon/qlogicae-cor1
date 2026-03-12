#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    struct
		RandomNumberGenerationManagerConfigurations :
			AbstractConfigurations<RandomNumberGenerationManagerConfigurations>
    {
	public:
		static RandomNumberGenerationManagerConfigurations
			initial_configurations;

		static RandomNumberGenerationManagerConfigurations
			default_configurations;

		RandomNumberGenerationManagerConfigurations();
    };
}

