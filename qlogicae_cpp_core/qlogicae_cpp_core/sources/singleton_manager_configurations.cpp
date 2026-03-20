#include "pch.hpp"

#include "../includes/singleton_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   	
	SingletonManagerConfigurations
		::SingletonManagerConfigurations() :
			AbstractConfigurations<SingletonManagerConfigurations>()
	{

	}
}

/*


	bool
		SingletonManagerConfigurations
			::is_runtime_execution_enabled_for_utility_handling()
	{
		return
			(is_runtime_execution_handling_override_enabled) ?
				is_runtime_execution_handling_enabled :
				is_utility_runtime_execution_handling_enabled;
	}

	bool
		SingletonManagerConfigurations
			::is_runtime_execution_enabled_for_feature_handling()
	{
		return
			(is_runtime_execution_handling_override_enabled) ?
				is_runtime_execution_handling_enabled :
				is_feature_runtime_execution_handling_enabled;
	}

	bool
		SingletonManagerConfigurations
			::is_runtime_execution_enabled_for_error_handling()
	{		
		return
			(is_runtime_execution_handling_override_enabled) ?
				is_runtime_execution_handling_enabled :
				is_error_runtime_execution_handling_enabled;			
	}

	bool
		SingletonManagerConfigurations
			::is_edge_case_enabled_for_utility_handling()
	{
		return
			(is_edge_case_handling_override_enabled) ?
				is_edge_case_handling_enabled :
				is_utility_edge_case_handling_enabled;
	}

	bool
		SingletonManagerConfigurations
			::is_edge_case_enabled_for_feature_handling()
	{
		return
			(is_edge_case_handling_override_enabled) ?
				is_edge_case_handling_enabled :
				is_feature_edge_case_handling_enabled;
	}

	bool
		SingletonManagerConfigurations
			::is_edge_case_enabled_for_error_handling()
	{		
		return
			(is_edge_case_handling_override_enabled) ?
				is_edge_case_handling_enabled :
				is_error_edge_case_handling_enabled;	
	}

	bool
		SingletonManagerConfigurations
			::is_thread_safety_enabled_for_utility_handling()
	{
		return
			(is_thread_safety_handling_override_enabled) ?
				is_thread_safety_handling_enabled :
				is_utility_thread_safety_handling_enabled;
	}

	bool
		SingletonManagerConfigurations
			::is_thread_safety_enabled_for_feature_handling()
	{
		return
			(is_thread_safety_handling_override_enabled) ?
				is_thread_safety_handling_enabled :
				is_feature_thread_safety_handling_enabled;
	}

	bool
		SingletonManagerConfigurations
			::is_thread_safety_enabled_for_error_handling()
	{		
		return
			(is_thread_safety_handling_override_enabled) ?
				is_thread_safety_handling_enabled :
				is_error_thread_safety_handling_enabled;
	}

	bool
		SingletonManagerConfigurations
			::is_runtime_execution_disabled_for_utility_handling()
	{
		return
			!is_runtime_execution_enabled_for_utility_handling();
	}

	bool
		SingletonManagerConfigurations
			::is_runtime_execution_disabled_for_feature_handling()
	{
		return
			!is_runtime_execution_enabled_for_feature_handling();
	}

	bool
		SingletonManagerConfigurations
			::is_runtime_execution_disabled_for_error_handling()
	{		
		return
			!is_runtime_execution_enabled_for_error_handling();
	}

	bool
		SingletonManagerConfigurations
			::is_edge_case_disabled_for_utility_handling()
	{
		return
			!is_edge_case_enabled_for_utility_handling();
	}

	bool
		SingletonManagerConfigurations
			::is_edge_case_disabled_for_feature_handling()
	{
		return
			!is_edge_case_enabled_for_feature_handling();
	}

	bool
		SingletonManagerConfigurations
			::is_edge_case_disabled_for_error_handling()
	{		
		return
			!is_edge_case_enabled_for_error_handling();
	}

	bool
		SingletonManagerConfigurations
			::is_thread_safety_disabled_for_utility_handling()
	{
		return
			!is_thread_safety_enabled_for_utility_handling();
	}

	bool
		SingletonManagerConfigurations
			::is_thread_safety_disabled_for_feature_handling()
	{
		return
			!is_thread_safety_enabled_for_feature_handling();
	}

	bool
		SingletonManagerConfigurations
			::is_thread_safety_disabled_for_error_handling()
	{		
		return
			!is_thread_safety_enabled_for_error_handling();
	}

*/
