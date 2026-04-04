#include "pch.hpp"

#include "../includes/asynchronous_batch_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{  
	AsynchronousBatchManager
		::AsynchronousBatchManager() :
			AbstractClass<AsynchronousBatchManagerConfigurations>()
    {
        construct();
    }

    AsynchronousBatchManager
		::~AsynchronousBatchManager()
    {
        destruct();
    }

    bool
        AsynchronousBatchManager
			::construct()
    {
        try
        {			
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
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

    bool
        AsynchronousBatchManager
			::destruct()
    {
        try
        {		
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
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

	std::unordered_map<std::string, std::any>
		AsynchronousBatchManager
			::execute_await_batch(
				const std::unordered_map<std::string, std::function<std::any()>>&
					values
			)
	{
		try
        {			
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				!values.size()
			);

			AsynchronousManager&
				asynchronous_manager =
					SingletonManager
						::get_singleton<AsynchronousManager>();

			std::unordered_map<std::string, std::future<std::any>>
				futures;

            std::unordered_map<std::string, std::any>
				outputs;

			for
			(
				auto& [key, callback] :
				values
			)
			{
				if (callback)
				{
					futures[key] =
						asynchronous_manager
							.co_spawn_strand_await<std::any>(
								callback
							);
				}				
			}	

			for
			(
				auto& [key, value] :
				futures
			)
			{
				outputs[key] = value.get();
			}

			return
				outputs;
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
	}

	std::unordered_map<std::string, std::future<std::any>>
		AsynchronousBatchManager
			::execute_async_batch(
				const std::unordered_map<std::string, std::function<std::any()>>&
					values
			)
	{
		try
        {			
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				!values.size()
			);

			AsynchronousManager&
				asynchronous_manager =
					SingletonManager
						::get_singleton<AsynchronousManager>();

			std::unordered_map<std::string, std::future<std::any>>
				outputs;

			for
			(
				auto& [key, callback] :
				values
			)
			{
				if (callback)
				{
					outputs[key] =
						asynchronous_manager
							.co_spawn_strand_await<std::any>(
								callback
							);
				}				
			}	

			return
				outputs;
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
