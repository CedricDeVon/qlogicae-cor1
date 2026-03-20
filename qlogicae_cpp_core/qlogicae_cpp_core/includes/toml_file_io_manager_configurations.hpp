#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		TomlFileIoManagerConfigurations :
			AbstractConfigurations<TomlFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				"";

		TomlFileIoManagerConfigurations();
    };    
}
