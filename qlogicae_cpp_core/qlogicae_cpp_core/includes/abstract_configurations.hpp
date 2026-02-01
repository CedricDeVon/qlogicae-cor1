#pragma once

namespace
	QLogicaeCppCore
{
	template <typename DerivedConfigurations> struct
		AbstractConfigurations
	{
	public:
		bool
			is_runtime_execution_handling_override_enabled =
				DerivedConfigurations
					::default_configurations
						.is_runtime_execution_handling_override_enabled;

		bool
			is_utility_runtime_execution_handling_enabled =
				DerivedConfigurations
					::default_configurations
						.is_utility_runtime_execution_handling_enabled;

		bool
			is_feature_runtime_execution_handling_enabled =
				DerivedConfigurations
					::default_configurations
						.is_feature_runtime_execution_handling_enabled;

		bool
			is_error_runtime_execution_handling_enabled =
				DerivedConfigurations
					::default_configurations
						.is_error_runtime_execution_handling_enabled;

		bool
			is_edge_case_handling_override_enabled =
				DerivedConfigurations
					::default_configurations
						.is_edge_case_handling_override_enabled;

		bool
			is_utility_edge_case_handling_enabled =
				DerivedConfigurations
					::default_configurations
						.is_utility_edge_case_handling_enabled;

		bool
			is_feature_edge_case_handling_enabled =
				DerivedConfigurations
					::default_configurations
						.is_feature_edge_case_handling_enabled;

		bool
			is_error_edge_case_handling_enabled =
				DerivedConfigurations
					::default_configurations
						.is_error_edge_case_handling_enabled;

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

		AbstractConfigurations();

		bool
			is_runtime_execution_enabled_for_utility_handling();

		bool
			is_runtime_execution_enabled_for_feature_handling();

		bool
			is_runtime_execution_enabled_for_error_handling();

		bool
			is_runtime_execution_disabled_for_utility_handling();

		bool
			is_runtime_execution_disabled_for_feature_handling();

		bool
			is_runtime_execution_disabled_for_error_handling();

		bool
			is_edge_case_enabled_for_utility_handling();

		bool
			is_edge_case_enabled_for_feature_handling();

		bool
			is_edge_case_enabled_for_error_handling();

		bool
			is_edge_case_disabled_for_utility_handling();

		bool
			is_edge_case_disabled_for_feature_handling();

		bool
			is_edge_case_disabled_for_error_handling();

		bool
			is_thread_safety_enabled_for_utility_handling();

		bool
			is_thread_safety_enabled_for_feature_handling();

		bool
			is_thread_safety_enabled_for_error_handling();

		bool
			is_thread_safety_disabled_for_utility_handling();

		bool
			is_thread_safety_disabled_for_feature_handling();

		bool
			is_thread_safety_disabled_for_error_handling();
	};

	template <typename DerivedConfigurations>
		AbstractConfigurations<DerivedConfigurations>
			::AbstractConfigurations()
	{		
			is_edge_case_handling_override_enabled =
				false;

			is_utility_edge_case_handling_enabled =
				true;

			is_feature_edge_case_handling_enabled =
				true;

			is_error_edge_case_handling_enabled =
				true;

			is_runtime_execution_handling_override_enabled =
				false;

			is_utility_runtime_execution_handling_enabled =
				true;

			is_feature_runtime_execution_handling_enabled =
				true;

			is_error_runtime_execution_handling_enabled =
				true;

			is_thread_safety_override_enabled =
				false;	
			
			is_utility_handling_thread_safety_enabled =
				true;
			
			is_feature_handling_thread_safety_enabled =
				false;
			
			is_error_handling_thread_safety_enabled =
				true;
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_runtime_execution_enabled_for_utility_handling()
	{
		return
			is_runtime_execution_handling_override_enabled ||
			is_utility_runtime_execution_handling_enabled;
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_runtime_execution_enabled_for_feature_handling()
	{
		return
			is_runtime_execution_handling_override_enabled ||
			is_feature_runtime_execution_handling_enabled;
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_runtime_execution_enabled_for_error_handling()
	{		
		return
			is_runtime_execution_handling_override_enabled ||
			is_error_runtime_execution_handling_enabled;
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_edge_case_enabled_for_utility_handling()
	{
		return
			is_edge_case_handling_override_enabled ||
			is_utility_edge_case_handling_enabled;
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_edge_case_enabled_for_feature_handling()
	{
		return
			is_edge_case_handling_override_enabled ||
			is_feature_edge_case_handling_enabled;
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_edge_case_enabled_for_error_handling()
	{		
		return
			is_edge_case_handling_override_enabled ||
			is_error_edge_case_handling_enabled;
	}

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

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_runtime_execution_disabled_for_utility_handling()
	{
		return
			!is_runtime_execution_enabled_for_utility_handling();
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_runtime_execution_disabled_for_feature_handling()
	{
		return
			!is_runtime_execution_enabled_for_feature_handling();
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_runtime_execution_disabled_for_error_handling()
	{		
		return
			!is_runtime_execution_enabled_for_error_handling();
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_edge_case_disabled_for_utility_handling()
	{
		return
			!is_edge_case_enabled_for_utility_handling();
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_edge_case_disabled_for_feature_handling()
	{
		return
			!is_edge_case_enabled_for_feature_handling();
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_edge_case_disabled_for_error_handling()
	{		
		return
			!is_edge_case_enabled_for_error_handling();
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_thread_safety_disabled_for_utility_handling()
	{
		return
			!is_thread_safety_enabled_for_utility_handling();
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_thread_safety_disabled_for_feature_handling()
	{
		return
			!is_thread_safety_enabled_for_feature_handling();
	}

	template <typename DerivedConfigurations> bool
		AbstractConfigurations<DerivedConfigurations>
			::is_thread_safety_disabled_for_error_handling()
	{		
		return
			!is_thread_safety_enabled_for_error_handling();
	}
}
