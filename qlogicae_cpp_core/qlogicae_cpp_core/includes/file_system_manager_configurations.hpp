#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    struct
		FileSystemManagerConfigurations :
			AbstractConfigurations<FileSystemManagerConfigurations>
    {
	public:
		bool
			is_recursive =
				true;

		FileSystemManagerConfigurations();
    };
}

