#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		CsvFileIoManagerConfigurations :
			AbstractConfigurations<CsvFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				"";	

		std::string				
			delimeter =
				",";
	
		CsvFileIoManagerConfigurations();
    };    
}
