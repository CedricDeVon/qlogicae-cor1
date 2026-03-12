#include "pch.hpp"

#include "../includes/excel_file_io_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	ExcelFileIoManagerConfigurations
		::ExcelFileIoManagerConfigurations() :
			AbstractConfigurations<ExcelFileIoManagerConfigurations>()
	{
		
	}

	ExcelFileIoManagerConfigurations
		ExcelFileIoManagerConfigurations
			::initial_configurations;

	ExcelFileIoManagerConfigurations
		ExcelFileIoManagerConfigurations
			::default_configurations =
				ExcelFileIoManagerConfigurations
					::initial_configurations;
}
