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
						.is_method_execution_enabled =
							true;
					
					configurations
						.is_error_handling_enabled =
							true;

					configurations
						.is_thread_safety_override_enabled =
							false;

					configurations
						.is_method_execution_thread_safety_enabled =
							true;

					configurations
						.is_error_handling_thread_safety_enabled =
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

