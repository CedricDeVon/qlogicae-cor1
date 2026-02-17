#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		RandomContainerGenerationManagerConfigurations :
			AbstractConfigurations<RandomContainerGenerationManagerConfigurations>
    {
	public:
		static RandomContainerGenerationManagerConfigurations
			initial_configurations;

		static RandomContainerGenerationManagerConfigurations
			default_configurations;

		RandomContainerGenerationManagerConfigurations();
    };
}
