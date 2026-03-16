#include "pch.hpp"

#include "../includes/asynchronous_batch_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	AsynchronousBatchManagerConfigurations
		::AsynchronousBatchManagerConfigurations() :
			AbstractConfigurations<AsynchronousBatchManagerConfigurations>()
	{
		
	}

    AsynchronousBatchManagerConfigurations
		AsynchronousBatchManagerConfigurations
			::initial_configurations;

	AsynchronousBatchManagerConfigurations
		AsynchronousBatchManagerConfigurations
			::default_configurations =
				AsynchronousBatchManagerConfigurations
					::initial_configurations;
}
