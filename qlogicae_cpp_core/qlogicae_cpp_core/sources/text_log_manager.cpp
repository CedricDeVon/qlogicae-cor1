#include "pch.hpp"

#include "../includes/text_log_manager.hpp"

namespace
	QLogicaeCppCore
{        
	TextLogManager&
		TextLogManager
			::singleton = 
				SingletonManager
					::get_singleton<TextLogManager>();	


	
	TextLogManager
		::TextLogManager() :
			AbstractClass<TextLogManagerConfigurations>()
    {
        
    }
}
