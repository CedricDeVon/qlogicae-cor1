#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		XmlFileIoManagerConfigurations :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<XmlFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				"";

		size_t
			indentation_count =
				1;

		XmlFileIoManagerConfigurations();
    };    
}
