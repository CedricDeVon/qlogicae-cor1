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
				default_configurations
					.file_path;

		static TomlFileIoManagerConfigurations
			initial_configurations;

		static TomlFileIoManagerConfigurations
			default_configurations;

		TomlFileIoManagerConfigurations();
    };    
}
