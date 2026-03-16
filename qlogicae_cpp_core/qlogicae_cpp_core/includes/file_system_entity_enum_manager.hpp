#pragma once

#include "abstract_class.hpp"
#include "file_system_entity.hpp"
#include "file_system_entity_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		FileSystemEntityEnumManager :
			public AbstractClass<FileSystemEntityEnumManagerConfigurations>
    {
    public:
		FileSystemEntityEnumManager();

		std::string
			convert_enum_to_string(
				const FileSystemEntity&
					value
			);

		std::string
			convert_enum_to_string();

		FileSystemEntity
			convert_string_to_enum(
				const std::string&
					value
			);

		FileSystemEntity
			convert_string_to_enum();
    };
}
