#include "pch.hpp"

#include "../includes/windows_system_access_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	WindowsSystemAccessManagerConfigurations
		::WindowsSystemAccessManagerConfigurations() :
			AbstractConfigurations<WindowsSystemAccessManagerConfigurations>()
	{
		
	}

	WindowsSystemAccessManagerConfigurations
		WindowsSystemAccessManagerConfigurations
			::initial_configurations;

	WindowsSystemAccessManagerConfigurations
		WindowsSystemAccessManagerConfigurations
			::default_configurations =
				WindowsSystemAccessManagerConfigurations
					::initial_configurations;
}
