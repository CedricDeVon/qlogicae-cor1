#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "qlogicae_file_system_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		QLogicaeFileSystemManager :
			public AbstractClass<QLogicaeFileSystemManagerConfigurations>
    {
    public:
        static QLogicaeFileSystemManager&
            singleton;

		QLogicaeFileSystemManager();

		~QLogicaeFileSystemManager();

		bool
			construct();

		bool
			destruct();
    };
}

