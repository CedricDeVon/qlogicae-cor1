#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		PdfFileIoManagerConfigurations :
			AbstractConfigurations<PdfFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				default_configurations
					.file_path;

		static PdfFileIoManagerConfigurations
			initial_configurations;

		static PdfFileIoManagerConfigurations
			default_configurations;

		PdfFileIoManagerConfigurations();
    };    
}
