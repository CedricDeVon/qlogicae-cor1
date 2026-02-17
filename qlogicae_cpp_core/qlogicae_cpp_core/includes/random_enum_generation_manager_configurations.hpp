#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		RandomEnumGenerationManagerConfigurations :
			AbstractConfigurations<RandomEnumGenerationManagerConfigurations>
    {
	public:
		static RandomEnumGenerationManagerConfigurations
			initial_configurations;

		static RandomEnumGenerationManagerConfigurations
			default_configurations;

		RandomEnumGenerationManagerConfigurations();
    };
}

