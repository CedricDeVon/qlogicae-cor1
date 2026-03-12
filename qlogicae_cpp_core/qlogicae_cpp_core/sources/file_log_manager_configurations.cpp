#include "pch.hpp"

#include "../includes/file_log_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{       
	FileLogManagerConfigurations
		::FileLogManagerConfigurations() :
			LogManagerConfigurations<FileLogManagerConfigurations>()
	{
		is_feature_thread_safety_handling_enabled =
			true;

		is_feature_edge_case_handling_enabled = 
			true;

		file_output_paths =
			{};
	}

	FileLogManagerConfigurations
		FileLogManagerConfigurations
			::initial_configurations;

	FileLogManagerConfigurations
		FileLogManagerConfigurations
			::default_configurations =
				FileLogManagerConfigurations
					::initial_configurations;
}
