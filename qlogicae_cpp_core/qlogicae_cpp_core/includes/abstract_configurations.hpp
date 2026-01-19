#pragma once

namespace
	QLogicaeCppCore
{
	template <typename DerivedConfigurations> struct
		AbstractConfigurations
	{
	public:
		bool
			is_feature_handling_enabled =
				DerivedConfigurations
					::default_configurations
						.is_feature_handling_enabled;

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
			is_utility_handling_thread_safety_enabled =
				DerivedConfigurations
					::default_configurations
						.is_utility_handling_thread_safety_enabled;

		bool
			is_feature_handling_thread_safety_enabled =
				DerivedConfigurations
					::default_configurations
						.is_feature_handling_thread_safety_enabled;

		bool
			is_error_handling_thread_safety_enabled =
				DerivedConfigurations
					::default_configurations
						.is_error_handling_thread_safety_enabled;



		bool
			is_thread_safety_enabled_for_utility_handling();

		bool
			is_thread_safety_enabled_for_feature_handling();

		bool
			is_thread_safety_enabled_for_error_handling();
	};

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_thread_safety_enabled_for_utility_handling()
	{
		return
			is_thread_safety_override_enabled ||
			is_utility_handling_thread_safety_enabled;
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_thread_safety_enabled_for_feature_handling()
	{
		return
			is_thread_safety_override_enabled ||
			is_feature_handling_thread_safety_enabled;
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
