#pragma once

#include "error_manager.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "configuration_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	class
		ConfigurationManager :
			public AbstractClass<ConfigurationManagerConfigurations>
	{
	public:
		static ConfigurationManager&
			singleton;

		ConfigurationManager();

		~ConfigurationManager();

		template <typename TypeConfigurations> void
			setup_defaults(
				const TypeConfigurations&
					new_configurations
			);

		template <typename TypeConfigurations> void
			reset_defaults();
	};

	template <typename TypeConfigurations> void
		ConfigurationManager
			::setup_defaults(
				const TypeConfigurations&
					new_configurations
			)
	{
		try
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_method_execution())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						method_handling_layer_mutex_1
					);
			}

			TypeConfigurations
				::default_configurations =
					new_configurations;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);
		}		
	}

	template <typename TypeConfigurations> void
		ConfigurationManager
			::reset_defaults()
	{
		try
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_method_execution())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						method_handling_layer_mutex_1
					);
			}

			TypeConfigurations
				::default_configurations =
					TypeConfigurations::
						initial_configurations;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);
		}		
	}
}
