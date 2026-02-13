#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "random_number_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		RandomNumberGenerationManager :
			public AbstractClass<RandomNumberGenerationManagerConfigurations>
    {
    public:
		static RandomNumberGenerationManager&
			singleton;

		RandomNumberGenerationManager();
	};
}
