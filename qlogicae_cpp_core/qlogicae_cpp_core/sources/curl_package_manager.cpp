#include "pch.hpp"

#include "../includes/curl_package_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{               
	CurlPackageManager
		::CurlPackageManager() :
			AbstractClass<CurlPackageManagerConfigurations>()
	{

	}
	
	bool
		CurlPackageManager
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
					curl_global_init(
						CURL_GLOBAL_DEFAULT
					);
				}
			);

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
