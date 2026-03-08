#include "pch.hpp"

#include "../includes/pdf_file_io_manager.hpp"

namespace
	QLogicaeCppCore
{        
	PdfFileIoManager&
		PdfFileIoManager
			::singleton = 
				SingletonManager
					::get_singleton<PdfFileIoManager>();	


	
	PdfFileIoManager
		::PdfFileIoManager() :
			AbstractClass<PdfFileIoManagerConfigurations>()
    {
        
    }
}
