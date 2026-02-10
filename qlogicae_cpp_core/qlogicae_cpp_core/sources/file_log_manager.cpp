#include "pch.hpp"

#include "../includes/file_log_manager.hpp"

namespace
	QLogicaeCppCore
{        
	FileLogManager&
		FileLogManager
			::singleton = 
				SingletonManager
					::get_singleton<FileLogManager>();	


	
	FileLogManager
		::FileLogManager() :
			AbstractClass<FileLogManagerConfigurations>()
    {
        
    }
}

