#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		ExcelFileIoManagerConfigurations :
			AbstractConfigurations<ExcelFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				default_configurations
					.file_path;

		std::string
			worksheet_name =
				default_configurations
					.worksheet_name;

		static ExcelFileIoManagerConfigurations
			initial_configurations;

		static ExcelFileIoManagerConfigurations
			default_configurations;

		ExcelFileIoManagerConfigurations();
    };    
}
