#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TimeoutClockConfigurations :
			AbstractConfigurations<TimeoutClockConfigurations>
	{
	public:
		std::function<void()>
			callback =
				default_configurations
					.callback;

		std::chrono::milliseconds
			delay_in_milliseconds =
				default_configurations
					.delay_in_milliseconds;

		bool
			is_executed_immediately =
				default_configurations
					.is_executed_immediately;
	


		static TimeoutClockConfigurations
			initial_configurations;

		static TimeoutClockConfigurations
			default_configurations;
	};
}
