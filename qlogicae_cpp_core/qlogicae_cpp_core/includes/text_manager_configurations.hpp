#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		TextManagerConfigurations :
			AbstractConfigurations<TextManagerConfigurations>
    {
	public:
		static TextManagerConfigurations
			initial_configurations;

		static TextManagerConfigurations
			default_configurations;
    };    
}
