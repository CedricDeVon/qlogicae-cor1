#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		XmlFileIoManagerConfigurations :
			AbstractConfigurations<XmlFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				"";

		size_t
			indentation_count =
				1;

		XmlFileIoManagerConfigurations();
    };    
}
