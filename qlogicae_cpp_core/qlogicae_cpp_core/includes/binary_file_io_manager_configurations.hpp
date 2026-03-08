#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		BinaryFileIoManagerConfigurations :
			AbstractConfigurations<BinaryFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				default_configurations
					.file_path;

		static BinaryFileIoManagerConfigurations
			initial_configurations;

		static BinaryFileIoManagerConfigurations
			default_configurations;

		BinaryFileIoManagerConfigurations();
    };    
}
