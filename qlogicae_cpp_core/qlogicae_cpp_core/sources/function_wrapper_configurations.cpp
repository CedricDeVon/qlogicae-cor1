#include "pch.hpp"

#include "../includes/function_wrapper_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	FunctionWrapperConfigurations
		::FunctionWrapperConfigurations() :
			AbstractConfigurations<FunctionWrapperConfigurations>()
	{
		
	}

	FunctionWrapperConfigurations
		FunctionWrapperConfigurations
			::initial_configurations;

	FunctionWrapperConfigurations
		FunctionWrapperConfigurations
			::default_configurations =
				FunctionWrapperConfigurations
					::initial_configurations;
}

