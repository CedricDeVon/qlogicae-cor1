#include "pch.hpp"

#include "../includes/qlogicae_file_system_manager.hpp"

namespace
	QLogicaeCppCore
{
    QLogicaeFileSystemManager&
        QLogicaeFileSystemManager
			::singleton =
				SingletonManager
					::get_singleton<QLogicaeFileSystemManager>();



	QLogicaeFileSystemManager
		::QLogicaeFileSystemManager() :
			AbstractClass<QLogicaeFileSystemManagerConfigurations>()
    {

    }
}

