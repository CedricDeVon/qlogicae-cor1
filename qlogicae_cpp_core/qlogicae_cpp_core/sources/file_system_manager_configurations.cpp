#include "pch.hpp"

#include "../includes/file_system_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{       
	FileSystemManagerConfigurations
		::FileSystemManagerConfigurations() :
			AbstractConfigurations<FileSystemManagerConfigurations>()
	{
		is_feature_thread_safety_handling_enabled =
			true;

		is_recursive =
			true;
	}

	FileSystemManagerConfigurations
		FileSystemManagerConfigurations
			::initial_configurations;

	FileSystemManagerConfigurations
		FileSystemManagerConfigurations
			::default_configurations =
				FileSystemManagerConfigurations
					::initial_configurations;
}

