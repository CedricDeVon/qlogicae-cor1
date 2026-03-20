#include "pch.hpp"

#include "../includes/asynchronous_batch_manager.hpp"

namespace
	QLogicae::Cor::V1
{  
	AsynchronousBatchManager
		::AsynchronousBatchManager() :
			AbstractClass<AsynchronousBatchManagerConfigurations>()
    {
        try
        {
            construct();
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

    AsynchronousBatchManager
		::~AsynchronousBatchManager()
    {
        try
        {
            destruct();
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

    bool
        AsynchronousBatchManager
			::construct()
    {
        try
        {			
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

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

    bool
        AsynchronousBatchManager
			::destruct()
    {
        try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

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

	std::unordered_map<std::string, std::any>
		AsynchronousBatchManager
			::execute_await_batch(
				const std::unordered_map<std::string, std::function<std::any()>>&
					values
			)
	{
		try
        {
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						!values.size()
					)
				)
			)
			{
				return
					{};
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
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);

			return
				{};
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						!values.size()
					)
				)
			)
			{
				return
					{};
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
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);

			return
				{};
        }
	}
}
