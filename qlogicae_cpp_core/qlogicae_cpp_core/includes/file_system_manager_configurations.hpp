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
		bool
			is_recursive =
				default_configurations
					.is_recursive;

		static FileSystemManagerConfigurations
			initial_configurations;

		static FileSystemManagerConfigurations
			default_configurations;

		FileSystemManagerConfigurations();
    };
}

