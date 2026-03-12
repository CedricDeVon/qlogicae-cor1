#pragma once

#include "abstract_class.hpp"
#include "pdf_file_io_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		PdfFileIoManager :
			public AbstractClass<PdfFileIoManagerConfigurations>
    {
    public:		
		PdfFileIoManager();
    };
}
