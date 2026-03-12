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
				default_configurations
					.file_path;

		static JsonFileIoManagerConfigurations
			initial_configurations;

		static JsonFileIoManagerConfigurations
			default_configurations;

		JsonFileIoManagerConfigurations();
    };    
}
