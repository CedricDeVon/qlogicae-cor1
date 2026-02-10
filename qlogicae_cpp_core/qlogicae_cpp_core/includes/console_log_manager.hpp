#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "console_log_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		ConsoleLogManager :
			public AbstractClass<ConsoleLogManagerConfigurations>
    {
    public:
        static ConsoleLogManager&
            singleton;

		ConsoleLogManager();

		~ConsoleLogManager();

		bool
			construct();

		bool
			destruct();
    };
}

