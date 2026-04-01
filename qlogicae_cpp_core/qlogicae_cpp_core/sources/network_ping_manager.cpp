#include "pch.hpp"

#include "../includes/network_ping_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
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

	NetworkPingManagerResponse
		NetworkPingManager
			::get_icmp_ping(
				const std::string&
					host_address
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
						host_address.empty()
					)
				)
			)
			{
				return
					NetworkPingManagerResponse {};
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

			NetworkPingManagerResponse output{};

			boost::asio::io_context io;
			boost::asio::ip::icmp::resolver resolver(io);
			boost::system::error_code ec;

			auto endpoints = resolver.resolve(host_address, "", ec);
			if (ec) return output;

			boost::asio::ip::icmp::socket socket(io, boost::asio::ip::icmp::v4());

			bool completed = false;
			auto start = std::chrono::steady_clock::now();

			boost::asio::steady_timer timer(io, configurations.timeout);
			timer.async_wait([&](const boost::system::error_code&) {
				if (!completed) socket.close();
				});

			socket.async_send_to(boost::asio::buffer("ping"), *endpoints.begin(),
				[&](const boost::system::error_code& send_ec, std::size_t) {
					completed = !send_ec;
					timer.cancel();
				});

			io.run_for(configurations.timeout);

			auto end = std::chrono::steady_clock::now();
			if (!completed) return output;

			auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
			output.sent_duration = scale_duration(duration_ns, configurations.time_scale_unit);
			output.receive_duration = output.sent_duration;
			output.roundtrip_duration = output.sent_duration + output.receive_duration;
			return output;
        }
        catch (const std::exception& exception)
        {            
            return handle_error_outputs<NetworkPingManagerResponse>(exception);
        }
    }

	NetworkPingManagerResponse
		NetworkPingManager
			::get_tcp_ping(
				const std::string&
					host_address
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
						host_address.empty()
					)
				)
			)
			{
				return
					NetworkPingManagerResponse {};
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

			NetworkPingManagerResponse output{};

			boost::asio::io_context io;
			boost::asio::ip::tcp::resolver resolver(io);
			boost::system::error_code ec;

			auto endpoints = resolver.resolve(host_address, "80", ec);
			if (ec) return output;

			boost::asio::ip::tcp::socket socket(io);

			auto start = std::chrono::steady_clock::now();
			bool connected = false;

			std::thread t([&]()
				{
					for (auto it = endpoints.begin(); it != endpoints.end() && !connected; ++it)
					{
						socket.close();
						socket.open(it->endpoint().protocol(), ec);
						if (ec) continue;
						socket.connect(it->endpoint(), ec);
						connected = !ec;
					}
				});

			if (t.joinable())
			{
				if (t.joinable()) t.join(); 
			}

			auto end = std::chrono::steady_clock::now();
			auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

			if (!connected) return output;

			output.sent_duration = scale_duration(duration_ns, configurations.time_scale_unit);
			output.receive_duration = 0;
			output.roundtrip_duration = output.sent_duration;

			return output;
        }
        catch (const std::exception& exception)
        {            
            return handle_error_outputs<NetworkPingManagerResponse>(exception);
        }
    }

	NetworkPingManagerResponse
		NetworkPingManager
			::get_icmp_ping()
	{
		return
			get_icmp_ping(
				configurations
					.host_address
			);
	}

	NetworkPingManagerResponse
		NetworkPingManager
			::get_tcp_ping()
	{
		return
			get_tcp_ping(
				configurations
					.host_address
			);
	}

	double
		NetworkPingManager
			::scale_duration(
				const std::chrono::nanoseconds&
					duration,
				const TimeScaleUnit&
					unit
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
						unit == TimeScaleUnit::NONE
					)
				)
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
						feature_handling_mutex_2
					);
			}

			switch (unit)
			{
				case TimeScaleUnit::NANOSECONDS:
					return static_cast<double>(duration.count());
				case TimeScaleUnit::MICROSECONDS:
					return static_cast<double>(
						std::chrono::duration_cast<std::chrono::microseconds>(duration).count()
					);
				case TimeScaleUnit::MILLISECONDS:
					return static_cast<double>(
						std::chrono::duration_cast<std::chrono::milliseconds>(duration).count()
					);
				case TimeScaleUnit::SECONDS:
					return std::chrono::duration<double>(duration).count();
				case TimeScaleUnit::MINUTES:
					return std::chrono::duration<double, std::ratio<60>>(duration).count();
				case TimeScaleUnit::HOURS:
					return std::chrono::duration<double, std::ratio<3600>>(duration).count();
				case TimeScaleUnit::DAYS:
					return std::chrono::duration<double, std::ratio<86400>>(duration).count();
				default:
					return static_cast<double>(duration.count());
			}
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs<double>(
					exception
				);
		}
	}
}
 