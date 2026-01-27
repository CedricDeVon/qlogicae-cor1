#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "network_ping_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		NetworkPingManager :
			public AbstractClass<NetworkPingManagerConfigurations>
    {
    public:
		static NetworkPingManager&
			singleton;

		NetworkPingManager();

		~NetworkPingManager();

		bool
			construct();

		bool
			destruct();

		bool
			start_listening();

		bool
			pause_listening();

	};
}
