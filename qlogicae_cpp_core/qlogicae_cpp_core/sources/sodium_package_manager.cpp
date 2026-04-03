#include "pch.hpp"

#include "../includes/sodium_package_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{               
	SodiumPackageManager
		::SodiumPackageManager() :
			AbstractClass<SodiumPackageManagerConfigurations>()
	{

	}
	
	bool
		SodiumPackageManager
			::setup()
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

			static std::once_flag
				initialization_flag;

			std::call_once(
				initialization_flag,
				[]()
				{
					sodium_init();
				}
			);

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
