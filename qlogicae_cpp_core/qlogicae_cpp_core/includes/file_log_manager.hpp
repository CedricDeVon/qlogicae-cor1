#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "file_log_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		FileLogManager :
			public AbstractClass<FileLogManagerConfigurations>
    {
    public:
        static FileLogManager&
            singleton;

		FileLogManager();

		~FileLogManager();

		bool
			construct();

		bool
			destruct();
    };
}

