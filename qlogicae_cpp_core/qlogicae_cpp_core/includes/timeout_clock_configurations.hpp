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
		static TimeoutClockConfigurations
			initial_configurations;

		static TimeoutClockConfigurations
			default_configurations;
	};
}


/*

#pragma once

#include "instance_manager.hpp"

namespace QLogicaeCppCore
{
	struct TimeoutClockConfigurations
	{
		std::function<void()> callback = []() {};

		std::chrono::milliseconds delay_in_milliseconds{ 100 };

		bool is_executed_immediately = true;
	};

	inline static TimeoutClockConfigurations& TIMEOUT_CLOCK_CONFIGURATIONS =
		INSTANCE_MANAGER.get_instance<TimeoutClockConfigurations>();
}

*/ 
