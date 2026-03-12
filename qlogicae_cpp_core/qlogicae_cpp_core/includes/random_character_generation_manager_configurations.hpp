#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    struct
		RandomCharacterGenerationManagerConfigurations :
			AbstractConfigurations<RandomCharacterGenerationManagerConfigurations>
    {
	public:
		static RandomCharacterGenerationManagerConfigurations
			initial_configurations;

		static RandomCharacterGenerationManagerConfigurations
			default_configurations;

		RandomCharacterGenerationManagerConfigurations();
    };
}

