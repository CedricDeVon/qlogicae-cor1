#pragma once

#include "file_system_entity.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
