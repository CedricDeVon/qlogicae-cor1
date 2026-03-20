#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		TimeoutClockConfigurations :
			AbstractConfigurations<TimeoutClockConfigurations>
	{
	public:
		std::function<void()>
			callback =
				[]() {};

		std::chrono::milliseconds
			delay_in_milliseconds =
				std::chrono::milliseconds{ 1000 };

		bool
			is_executed_immediately =
				true;

		TimeoutClockConfigurations();
	};
}

