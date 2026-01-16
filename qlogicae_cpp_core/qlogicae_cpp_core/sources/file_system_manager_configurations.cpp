#include "pch.hpp"

#include "../includes/file_system_manager_configurations.hpp"

namespace QLogicaeCppCore
{    
    FileSystemManagerConfigurations
		FileSystemManagerConfigurations
			::initial_configurations =
				{
					.is_enabled =
						true,

					.is_thread_safety_enabled =
						false,
				};

	FileSystemManagerConfigurations
		FileSystemManagerConfigurations
			::default_configurations =
				FileSystemManagerConfigurations
					::initial_configurations;
}
