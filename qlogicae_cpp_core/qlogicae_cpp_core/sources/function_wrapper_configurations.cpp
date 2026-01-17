#include "pch.hpp"

#include "../includes/function_wrapper_configurations.hpp"

namespace
	QLogicaeCppCore
{
	FunctionWrapperConfigurations
		FunctionWrapperConfigurations
			::initial_configurations =
				{
					.is_enabled =
						true,

					.is_thread_safety_enabled =
						false,
				};

	FunctionWrapperConfigurations
		FunctionWrapperConfigurations
			::default_configurations =
				FunctionWrapperConfigurations
					::initial_configurations;
}
