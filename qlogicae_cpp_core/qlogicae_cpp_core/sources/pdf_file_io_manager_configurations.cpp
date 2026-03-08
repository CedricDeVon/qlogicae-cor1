#include "pch.hpp"

#include "../includes/pdf_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	PdfFileIoManagerConfigurations
		::PdfFileIoManagerConfigurations() :
			AbstractConfigurations<PdfFileIoManagerConfigurations>()
	{
		
	}

	PdfFileIoManagerConfigurations
		PdfFileIoManagerConfigurations
			::initial_configurations;

	PdfFileIoManagerConfigurations
		PdfFileIoManagerConfigurations
			::default_configurations =
				PdfFileIoManagerConfigurations
					::initial_configurations;
}
