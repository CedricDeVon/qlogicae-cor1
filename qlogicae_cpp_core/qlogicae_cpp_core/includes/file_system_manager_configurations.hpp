#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		FileSystemManagerConfigurations :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<FileSystemManagerConfigurations>
    {
	public:
		bool
			is_recursive =
				true;

		FileSystemManagerConfigurations();
    };
}
