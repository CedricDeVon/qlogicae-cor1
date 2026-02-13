#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
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
