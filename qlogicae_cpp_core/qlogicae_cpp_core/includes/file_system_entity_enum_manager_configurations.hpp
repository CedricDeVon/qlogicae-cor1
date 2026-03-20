#pragma once

#include "file_system_entity.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		FileSystemEntityEnumManagerConfigurations :
			AbstractConfigurations<FileSystemEntityEnumManagerConfigurations>
	{
	public:	
		FileSystemEntity
			type =
				FileSystemEntity
					::ALL;

		FileSystemEntityEnumManagerConfigurations();
	};
}
