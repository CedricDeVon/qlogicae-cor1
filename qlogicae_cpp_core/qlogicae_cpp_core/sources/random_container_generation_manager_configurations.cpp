#include "pch.hpp"

#include "../includes/random_container_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	RandomContainerGenerationManagerConfigurations
		::RandomContainerGenerationManagerConfigurations() :
			AbstractConfigurations<RandomContainerGenerationManagerConfigurations>()
	{
		
	}

	RandomContainerGenerationManagerConfigurations
		RandomContainerGenerationManagerConfigurations
			::initial_configurations;

	RandomContainerGenerationManagerConfigurations
		RandomContainerGenerationManagerConfigurations
			::default_configurations =
				RandomContainerGenerationManagerConfigurations
					::initial_configurations;
}
