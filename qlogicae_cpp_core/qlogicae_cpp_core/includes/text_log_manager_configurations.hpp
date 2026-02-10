#pragma once

#include "text_case.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TextLogManagerConfigurations :
			AbstractConfigurations<TextLogManagerConfigurations>
	{
	public:		
		static TextLogManagerConfigurations
			initial_configurations;

		static TextLogManagerConfigurations
			default_configurations;

		TextLogManagerConfigurations();
	};
}

