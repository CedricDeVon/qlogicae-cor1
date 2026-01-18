#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		FileSystemManagerConfigurations :
			AbstractConfigurations<FileSystemManagerConfigurations>
    {
		static FileSystemManagerConfigurations
			initial_configurations;

		static FileSystemManagerConfigurations
			default_configurations;
    };
}
