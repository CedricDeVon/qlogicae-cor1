#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
