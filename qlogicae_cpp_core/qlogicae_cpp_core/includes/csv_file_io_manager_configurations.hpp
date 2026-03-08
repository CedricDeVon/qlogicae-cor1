#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		CsvFileIoManagerConfigurations :
			AbstractConfigurations<CsvFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				default_configurations
					.file_path;

		std::string
			delimeter =
				default_configurations
					.delimeter;

		static CsvFileIoManagerConfigurations
			initial_configurations;

		static CsvFileIoManagerConfigurations
			default_configurations;

		CsvFileIoManagerConfigurations();
    };    
}
