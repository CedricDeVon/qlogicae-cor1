#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "pdf_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		PdfFileIoManager :
			public AbstractClass<PdfFileIoManagerConfigurations>
    {
    public:		
        static PdfFileIoManager&
            singleton;

		PdfFileIoManager();
    };
}
