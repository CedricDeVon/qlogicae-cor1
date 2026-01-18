#pragma once

namespace
	QLogicaeCppCore
{
	template <typename DerivedConfigurations> struct
		AbstractConfigurations
	{
	public:
		bool
			is_method_execution_enabled =
				DerivedConfigurations
					::default_configurations
						.is_method_execution_enabled;

		bool
			is_error_handling_enabled =
				DerivedConfigurations
					::default_configurations
						.is_error_handling_enabled;

		bool
			is_thread_safety_override_enabled =
				DerivedConfigurations
					::default_configurations
						.is_thread_safety_override_enabled;
	
		bool
			is_method_execution_thread_safety_enabled =
				DerivedConfigurations
					::default_configurations
						.is_method_execution_thread_safety_enabled;

		bool
			is_error_handling_thread_safety_enabled =
				DerivedConfigurations
					::default_configurations
						.is_error_handling_thread_safety_enabled;

		bool
			is_thread_safety_enabled_for_method_execution();

		bool
			is_thread_safety_enabled_for_error_handling();
	};

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_thread_safety_enabled_for_method_execution()
	{
		return
			is_thread_safety_override_enabled ||
			is_method_execution_thread_safety_enabled;
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_thread_safety_enabled_for_error_handling()
	{		
		return
			is_thread_safety_override_enabled ||
			is_error_handling_thread_safety_enabled;
	}
}
