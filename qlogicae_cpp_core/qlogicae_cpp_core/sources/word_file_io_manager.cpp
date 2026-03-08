#include "pch.hpp"

#include "../includes/word_file_io_manager.hpp"

namespace
	QLogicaeCppCore
{        
	WordFileIoManager&
		WordFileIoManager
			::singleton = 
				SingletonManager
					::get_singleton<WordFileIoManager>();	


	
	WordFileIoManager
		::WordFileIoManager() :
			AbstractClass<WordFileIoManagerConfigurations>()
    {
        
    }
}
