#include "pch.hpp"

#include "../includes/network_ping_manager.hpp"

namespace
	QLogicaeCppCore
{
	NetworkPingManager&
        NetworkPingManager
			::singleton =
				SingletonManager
					::get_singleton<NetworkPingManager>();



    NetworkPingManager
		::NetworkPingManager() :
			AbstractClass<NetworkPingManagerConfigurations>()
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

	NetworkPingManager
		::~NetworkPingManager()
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
        NetworkPingManager
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
						utility_handling_mutex_1
					);
			}			

			interval_clock.configurations.callback =
				[this](const size_t& current_iteration) -> bool
				{
					auto result = ping();
					if (result && interval_clock.configurations.callback)
					{
						NetworkPingManagerResponse
							response;

						response
							.round_trip_time_in_milliseconds =
								result;

						configurations
							.callback(
								response									
							);
					}

					return
						interval_clock
							.is_running();
				};

			interval_clock.configurations.maximum_interval_count =
				0;

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
        NetworkPingManager
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
						utility_handling_mutex_1
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
		NetworkPingManager
			::get_is_listening()
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

			return
				interval_clock
					.is_running();
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
		NetworkPingManager
			::set_is_listening(
				const bool&
					value
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

			(value) ?
				interval_clock.resume() :
				interval_clock.pause();

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

	std::string
		NetworkPingManager
			::get_name()
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
					"";
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

			return
				configurations
					.name;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs<std::string>(
					exception
				);
        }
	}

	bool
		NetworkPingManager
			::set_name(
				const std::string&
					value
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
						value.empty()
					)
				)
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

			configurations
				.name =
					value;

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

	std::string
		NetworkPingManager
			::get_host_address()
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
					"";
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

			return
				configurations
					.host_address;	
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs<std::string>(
					exception
				);
        }
	}

	bool
		NetworkPingManager
			::set_host_address(
				const std::string&
					value
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
						value.empty()
					)
				)
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

			configurations
				.host_address =
					value;

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

	std::chrono::milliseconds
		NetworkPingManager
			::get_delay_in_milliseconds()
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
					std::chrono::milliseconds
						{ 0 };
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

			return
				interval_clock
					.configurations
						.delay_in_milliseconds;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs<std::chrono::milliseconds>(
					exception
				);
        }
	}

	bool
		NetworkPingManager
			::set_delay_in_milliseconds(
				const std::chrono::milliseconds&
					value
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

			interval_clock
				.configurations
					.delay_in_milliseconds =
						value;

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
		NetworkPingManager
			::start_listening()
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
	
			if (!interval_clock.is_running())
			{
				interval_clock.start();

				return
					true;
			}

			return
				false;
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
		NetworkPingManager
			::pause_listening()
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

			if (interval_clock.is_running())
			{
				interval_clock.pause();

				return
					true;
			}

			return
				false;
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
		NetworkPingManager
			::continue_listening()
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

			if (!interval_clock.is_running())
			{
				interval_clock.resume();

				return
					true;
			}

			return
				false;
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

	int64_t
		NetworkPingManager
			::ping()
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
					0;
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

			boost::asio::io_context io;
            boost::asio::ip::tcp::resolver resolver(io);

            auto endpoints = resolver.resolve(configurations.host_address, "80");
            boost::asio::ip::tcp::socket socket(io);
            auto start = std::chrono::steady_clock::now();
            boost::asio::connect(socket, endpoints);
            auto end = std::chrono::steady_clock::now();

            return
				std::chrono::duration_cast<std::chrono::milliseconds>(
					end - start
				).count();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs<int64_t>(
					exception
				);
        }
	}
}
