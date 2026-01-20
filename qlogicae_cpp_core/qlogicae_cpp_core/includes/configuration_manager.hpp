#pragma once

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

		bool
			construct();

		bool
			destruct();

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
