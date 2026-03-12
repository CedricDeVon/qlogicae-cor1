#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		UriFileIoManagerConfigurations :
			AbstractConfigurations<UriFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				default_configurations
					.file_path;

		std::string
			mime_type =
				default_configurations
					.mime_type;

		static UriFileIoManagerConfigurations
			initial_configurations;

		static UriFileIoManagerConfigurations
			default_configurations;

		UriFileIoManagerConfigurations();
    };    
}
