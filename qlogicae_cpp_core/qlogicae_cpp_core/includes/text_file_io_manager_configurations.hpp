#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		TextFileIoManagerConfigurations :
			AbstractConfigurations<TextFileIoManagerConfigurations>
	{
	public:		
		std::string
			file_path =
				default_configurations
					.file_path;

		static TextFileIoManagerConfigurations
			initial_configurations;

		static TextFileIoManagerConfigurations
			default_configurations;

		TextFileIoManagerConfigurations();
	};
}

