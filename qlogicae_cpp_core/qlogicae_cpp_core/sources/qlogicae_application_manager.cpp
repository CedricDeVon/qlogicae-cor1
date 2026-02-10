#include "pch.hpp"

#include "../includes/qlogicae_application_manager.hpp"

namespace
	QLogicaeCppCore
{
    QLogicaeApplicationManager&
        QLogicaeApplicationManager
			::singleton =
				SingletonManager
					::get_singleton<QLogicaeApplicationManager>();



	QLogicaeApplicationManager
		::QLogicaeApplicationManager() :
			AbstractClass<QLogicaeApplicationManagerConfigurations>()
    {
        
    }
}

