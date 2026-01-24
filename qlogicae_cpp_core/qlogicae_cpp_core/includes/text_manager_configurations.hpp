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
		bool
			is_specified_length_enabled =
				default_configurations.is_specified_length_enabled;

		size_t
			specified_length =
				default_configurations.specified_length;



		static TextManagerConfigurations
			initial_configurations;

		static TextManagerConfigurations
			default_configurations;
    };    
}

