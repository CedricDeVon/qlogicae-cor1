#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "application_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		ApplicationManager :
			public AbstractClass<ApplicationManagerConfigurations>
    {
    public:
        static ApplicationManager&
            singleton;

		ApplicationManager();

		~ApplicationManager();

		bool
			construct();

		bool
			destruct();
    };
}

