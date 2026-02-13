#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		RandomStringGenerationManagerConfigurations :
			AbstractConfigurations<RandomStringGenerationManagerConfigurations>
    {
	public:
		static RandomStringGenerationManagerConfigurations
			initial_configurations;

		static RandomStringGenerationManagerConfigurations
			default_configurations;

		RandomStringGenerationManagerConfigurations();
    };
}
