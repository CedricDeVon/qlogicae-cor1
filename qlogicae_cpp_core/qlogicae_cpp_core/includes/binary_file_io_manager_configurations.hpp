#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		BinaryFileIoManagerConfigurations :
			AbstractConfigurations<BinaryFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				"";

		BinaryFileIoManagerConfigurations();
    };    
}
