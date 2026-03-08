#include "pch.hpp"

#include "../includes/toml_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TomlFileIoManagerConfigurations
		::TomlFileIoManagerConfigurations() :
			AbstractConfigurations<TomlFileIoManagerConfigurations>()
	{
		
	}

	TomlFileIoManagerConfigurations
		TomlFileIoManagerConfigurations
			::initial_configurations;

	TomlFileIoManagerConfigurations
		TomlFileIoManagerConfigurations
			::default_configurations =
				TomlFileIoManagerConfigurations
					::initial_configurations;
}
