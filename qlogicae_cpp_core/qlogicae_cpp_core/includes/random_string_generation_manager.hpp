#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "random_string_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		RandomStringGenerationManager :
			public AbstractClass<RandomStringGenerationManagerConfigurations>
    {
    public:
		static RandomStringGenerationManager&
			singleton;

		RandomStringGenerationManager();
	};
}
