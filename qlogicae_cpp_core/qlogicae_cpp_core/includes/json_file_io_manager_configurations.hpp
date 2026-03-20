#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		JsonFileIoManagerConfigurations :
			AbstractConfigurations<JsonFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				"";

		JsonFileIoManagerConfigurations();
    };    
}
