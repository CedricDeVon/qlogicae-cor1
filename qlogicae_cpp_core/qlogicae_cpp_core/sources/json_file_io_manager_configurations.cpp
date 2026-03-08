#include "pch.hpp"

#include "../includes/json_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	JsonFileIoManagerConfigurations
		::JsonFileIoManagerConfigurations() :
			AbstractConfigurations<JsonFileIoManagerConfigurations>()
	{
		file_path =
			"";
	}

	JsonFileIoManagerConfigurations
		JsonFileIoManagerConfigurations
			::initial_configurations;

	JsonFileIoManagerConfigurations
		JsonFileIoManagerConfigurations
			::default_configurations =
				JsonFileIoManagerConfigurations
					::initial_configurations;
}
