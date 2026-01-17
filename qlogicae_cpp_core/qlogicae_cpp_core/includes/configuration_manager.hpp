#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "configuration_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	class
		ConfigurationManager
	{
	public:
		boost::mutex
			mutex_1;

		ConfigurationManagerConfigurations
			configurations;

		static ConfigurationManager&
			singleton;

		ConfigurationManager();

		~ConfigurationManager();

		bool
			construct();

		bool
			destruct();

		bool
			setup(
				const ConfigurationManagerConfigurations&
					new_configurations =
						{}
			);

		bool
			reset();

		template <typename TypeConfigurations> void
			setup_defaults(
				const TypeConfigurations&
					configurations
			);

		template <typename TypeConfigurations> void
			reset_defaults();
	};

	template <typename TypeConfigurations> void
		ConfigurationManager
			::setup_defaults(
				const TypeConfigurations&
					configurations
			)
	{
		TypeConfigurations
			::default_configurations =
				configurations;
	}

	template <typename TypeConfigurations> void
		ConfigurationManager
			::reset_defaults()
	{
		TypeConfigurations
			::default_configurations =
				TypeConfigurations::
					initial_configurations;
	}
}
