#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "random_character_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		RandomCharacterGenerationManager :
			public AbstractClass<RandomCharacterGenerationManagerConfigurations>
    {
    public:
		static RandomCharacterGenerationManager&
			singleton;

		RandomCharacterGenerationManager();
	};
}
