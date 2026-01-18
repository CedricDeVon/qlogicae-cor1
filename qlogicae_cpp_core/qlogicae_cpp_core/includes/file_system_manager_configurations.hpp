#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		FileSystemManagerConfigurations :
			AbstractConfigurations<FileSystemManagerConfigurations>
    {
	public:
		static FileSystemManagerConfigurations
			initial_configurations;

		static FileSystemManagerConfigurations
			default_configurations;
    };
}
