#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		ExcelFileIoManagerConfigurations :
			AbstractConfigurations<ExcelFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				"";

		std::string
			worksheet_name =
				"";

		ExcelFileIoManagerConfigurations();
    };    
}

