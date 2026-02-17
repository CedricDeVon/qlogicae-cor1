#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "random_container_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		RandomContainerGenerationManager :
			public AbstractClass<RandomContainerGenerationManagerConfigurations>
    {
    public:
		static RandomContainerGenerationManager&
			singleton;

		RandomContainerGenerationManager();
	};
}
