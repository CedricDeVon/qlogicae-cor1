#pragma once

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		TimeoutClockConfigurations \
	)

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		TimeoutClockConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<TimeoutClockConfigurations>
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

#endif
