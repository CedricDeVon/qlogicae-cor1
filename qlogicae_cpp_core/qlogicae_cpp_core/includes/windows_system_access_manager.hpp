#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "windows_system_access_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	class
		WindowsSystemAccessManager :
			public AbstractClass<WindowsSystemAccessManagerConfigurations>
	{
	public:
		static WindowsSystemAccessManager&
			singleton;

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
