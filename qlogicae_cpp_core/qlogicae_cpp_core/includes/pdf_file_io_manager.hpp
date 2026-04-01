#pragma once

#include "abstract_class.hpp"
#include "pdf_file_io_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		PdfFileIoManager :
			public AbstractClass<PdfFileIoManagerConfigurations>
    {
    public:		
		PdfFileIoManager();
    };
}
