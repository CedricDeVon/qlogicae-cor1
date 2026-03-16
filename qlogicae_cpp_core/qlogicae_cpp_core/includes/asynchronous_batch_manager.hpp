#pragma once

#include "abstract_class.hpp"
#include "asynchronous_manager.hpp"
#include "asynchronous_batch_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		AsynchronousBatchManager :
			public AbstractClass<AsynchronousBatchManagerConfigurations>
    {
    public:		
		AsynchronousBatchManager();

		std::unordered_map<std::string, std::any>
			execute_await_batch(
				const std::unordered_map<std::string, std::function<std::any()>>&
					values
			);

		std::unordered_map<std::string, std::future<std::any>>
			execute_async_batch(
				const std::unordered_map<std::string, std::function<std::any()>>&
					values
			);
    };
}
