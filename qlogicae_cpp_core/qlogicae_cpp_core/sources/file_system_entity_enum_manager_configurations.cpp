#include "pch.hpp"

#include "../includes/file_system_entity_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{   
	FileSystemEntityEnumManagerConfigurations
		::FileSystemEntityEnumManagerConfigurations() :
			AbstractConfigurations<FileSystemEntityEnumManagerConfigurations>()
	{
		type =
			FileSystemEntity
				::ALL;
	}

	FileSystemEntityEnumManagerConfigurations
		FileSystemEntityEnumManagerConfigurations
			::initial_configurations;

	FileSystemEntityEnumManagerConfigurations
		FileSystemEntityEnumManagerConfigurations
			::default_configurations =
				FileSystemEntityEnumManagerConfigurations
					::initial_configurations;
}
