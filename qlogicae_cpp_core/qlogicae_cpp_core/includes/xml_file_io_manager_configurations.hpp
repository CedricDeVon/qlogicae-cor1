#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		XmlFileIoManagerConfigurations :
			AbstractConfigurations<XmlFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				default_configurations
					.file_path;

		size_t
			indentation_count =
				default_configurations
					.indentation_count;

		static XmlFileIoManagerConfigurations
			initial_configurations;

		static XmlFileIoManagerConfigurations
			default_configurations;

		XmlFileIoManagerConfigurations();
    };    
}
