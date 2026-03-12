#include "pch.hpp"

#include "../includes/asynchronous_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	AsynchronousManagerConfigurations
		::AsynchronousManagerConfigurations() :
			AbstractConfigurations<AsynchronousManagerConfigurations>()
	{
		
	}

    AsynchronousManagerConfigurations
		AsynchronousManagerConfigurations
			::initial_configurations;

	AsynchronousManagerConfigurations
		AsynchronousManagerConfigurations
			::default_configurations =
				AsynchronousManagerConfigurations
					::initial_configurations;
}

