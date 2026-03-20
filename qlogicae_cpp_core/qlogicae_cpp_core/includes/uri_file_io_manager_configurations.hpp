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
				"";

		std::string
			mime_type =
				"application/octet-stream";

		UriFileIoManagerConfigurations();
    };    
}
