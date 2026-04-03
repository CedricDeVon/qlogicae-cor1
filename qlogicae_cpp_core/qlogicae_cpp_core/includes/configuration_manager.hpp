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
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
			);

			TypeConfigurations
				::default_configurations =
					new_configurations;

			return
				true;
		}
		catch
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
		}		
	}

	template <typename TypeConfigurations> bool
		ConfigurationManager
			::reset_defaults()
	{
		try
		{
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
			);

			TypeConfigurations
				::default_configurations =
					TypeConfigurations::
						initial_configurations;

			return
				true;
		}
		catch
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
		}		
	}
}
