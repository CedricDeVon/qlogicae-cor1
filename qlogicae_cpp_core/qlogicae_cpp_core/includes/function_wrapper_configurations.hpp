#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    struct
		FunctionWrapperConfigurations :
			AbstractConfigurations<FunctionWrapperConfigurations>
    {
	public:
		static FunctionWrapperConfigurations
			initial_configurations;

		static FunctionWrapperConfigurations
			default_configurations;

		FunctionWrapperConfigurations();
    };
}
