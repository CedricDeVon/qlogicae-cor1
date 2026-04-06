#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		TomlFileIoManagerConfigurations :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<TomlFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				"";

		TomlFileIoManagerConfigurations();
    };    
}
