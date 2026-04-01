#pragma once

#include "abstract_class.hpp"
#include "configuration_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	class
		ConfigurationManager :
			public AbstractClass<ConfigurationManagerConfigurations>
	{
	public:
		ConfigurationManager();

		template <typename TypeConfigurations> bool
			setup_defaults(
				const TypeConfigurations&
					new_configurations
			);

		template <typename TypeConfigurations> bool
			reset_defaults();
	};

	template <typename TypeConfigurations> bool
		ConfigurationManager
			::setup_defaults(
				const TypeConfigurations&
					new_configurations
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			TypeConfigurations
				::default_configurations =
					new_configurations;

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs(
					exception
				);
		}		
	}

	template <typename TypeConfigurations> bool
		ConfigurationManager
			::reset_defaults()
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			TypeConfigurations
				::default_configurations =
					TypeConfigurations::
						initial_configurations;

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs(
					exception
				);
		}		
	}
}
