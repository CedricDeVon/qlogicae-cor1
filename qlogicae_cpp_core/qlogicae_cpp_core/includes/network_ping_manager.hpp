#pragma once

#include "abstract_class.hpp"
#include "interval_clock.hpp"
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
		IntervalClock
			interval_clock;

		static NetworkPingManager&
			singleton;

		NetworkPingManager();

		~NetworkPingManager();

		bool
			construct();

		bool
			destruct();

		bool
			get_is_listening();

		bool
			set_is_listening(
				const bool&
					value
			);

		std::string
			get_name();

		bool
			set_name(
				const std::string&
					value
			);

		std::string
			get_host_address();

		bool
			set_host_address(
				const std::string&
					value
			);

		std::chrono::milliseconds
			get_delay_in_milliseconds();

		bool
			set_delay_in_milliseconds(
				const std::chrono::milliseconds&
					value
			);

		bool
			start_listening();

		bool
			pause_listening();

		bool
			continue_listening();

		int64_t
			ping();
	};
}
