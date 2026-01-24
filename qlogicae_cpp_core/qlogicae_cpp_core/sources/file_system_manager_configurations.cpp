#include "pch.hpp"

#include "../includes/file_system_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    FileSystemManagerConfigurations
		FileSystemManagerConfigurations
			::initial_configurations =
				[]()
				{
					FileSystemManagerConfigurations
						configurations;

					configurations
						.is_feature_handling_thread_safety_enabled =
							true;

					configurations
						.is_recursive =
							true;

					return
						configurations;
				}();

	FileSystemManagerConfigurations
		FileSystemManagerConfigurations
			::default_configurations =
				FileSystemManagerConfigurations
					::initial_configurations;
}

