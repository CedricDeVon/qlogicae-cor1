#pragma once

#include "abstract_class.hpp"
#include "windows_system_access_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	class
		WindowsSystemAccessManager :
			public AbstractClass<WindowsSystemAccessManagerConfigurations>
	{
	public:
		WindowsSystemAccessManager();

		bool
			run_process(
				const std::string&
					command
			);

		bool
			has_admin_access();

		bool
			restart_with_admin_access();
	};
}
