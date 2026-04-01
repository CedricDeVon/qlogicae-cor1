#pragma once

#include "abstract_class.hpp"
#include "asynchronous_manager.hpp"
#include "asynchronous_batch_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		AsynchronousBatchManager :
			public AbstractClass<AsynchronousBatchManagerConfigurations>
    {
    public:		
		AsynchronousBatchManager();

		~AsynchronousBatchManager();

		bool
			construct();

		bool
			destruct();

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
