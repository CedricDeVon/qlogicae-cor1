#include "pch.hpp"

#include "../includes/function_wrapper_configurations.hpp"

namespace
	QLogicaeCppCore
{
	FunctionWrapperConfigurations
		FunctionWrapperConfigurations
			::initial_configurations =
				[]()
				{
					FunctionWrapperConfigurations
						configurations;

					return
						configurations;
				}();

	FunctionWrapperConfigurations
		FunctionWrapperConfigurations
			::default_configurations =
				FunctionWrapperConfigurations
					::initial_configurations;
}

