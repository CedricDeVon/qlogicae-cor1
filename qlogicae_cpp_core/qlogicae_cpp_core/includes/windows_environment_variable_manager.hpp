#pragma once

#include "text_case.hpp"
#include "text_manager.hpp"
#include "abstract_class.hpp"
#include "text_case_manager.hpp"
#include "windows_environment_variable_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	class
		WindowsEnvironmentVariableManager :
			public AbstractClass<WindowsEnvironmentVariableManagerConfigurations>
	{
	public:
		WindowsEnvironmentVariableManager();

		std::wstring
			get_value(
				const std::wstring&
					key
			);

		bool
			set_value(
				const std::wstring&
					key,
				const std::wstring&
					value
			);

		bool
			remove_value(
				const std::wstring&
					key
			);

		std::string
			get_value(
				const std::string&
					key
			);

		bool
			set_value(
				const std::string&
					key,
				const std::string&
					value
			);

		bool
			remove_value(
				const std::string&
					key
			);
	};
}

