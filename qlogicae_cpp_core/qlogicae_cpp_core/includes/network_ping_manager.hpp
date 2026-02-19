#pragma once

#include "abstract_class.hpp"
#include "time_scale_unit.hpp"
#include "singleton_manager.hpp"
#include "network_ping_manager_response.hpp"
#include "network_ping_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{	
    class
		NetworkPingManager :
			public AbstractClass<NetworkPingManagerConfigurations>
    {
    public:
		boost::mutex
			feature_handling_mutex_2;

		static NetworkPingManager&
			singleton;

		NetworkPingManager();

		~NetworkPingManager();

		bool
			construct();

		bool
			destruct();

		NetworkPingManagerResponse
			get_icmp_ping(
				const std::string&
					host_address
			);

		NetworkPingManagerResponse
			get_icmp_ping();

		NetworkPingManagerResponse
			get_tcp_ping(
				const std::string&
					host_address
			);

		NetworkPingManagerResponse
			get_tcp_ping();

		double
			scale_duration(
				const std::chrono::nanoseconds&
					duration,
				const TimeScaleUnit&
					unit
		);
	};
}

