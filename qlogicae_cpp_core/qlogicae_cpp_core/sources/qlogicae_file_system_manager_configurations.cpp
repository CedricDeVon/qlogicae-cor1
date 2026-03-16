#include "pch.hpp"

#include "../includes/qlogicae_file_system_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	QLogicaeFileSystemManagerConfigurations
		::QLogicaeFileSystemManagerConfigurations() :
			AbstractConfigurations<QLogicaeFileSystemManagerConfigurations>()
	{
		
	}

	QLogicaeFileSystemManagerConfigurations
		QLogicaeFileSystemManagerConfigurations
			::initial_configurations;

	QLogicaeFileSystemManagerConfigurations
		QLogicaeFileSystemManagerConfigurations
			::default_configurations =
				QLogicaeFileSystemManagerConfigurations
					::initial_configurations;
}

