#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{   
    struct
		MutexManagerConfigurations :
			AbstractConfigurations<MutexManagerConfigurations>
    {
	public:
        std::string
            name =
                default_configurations
					.name;



		static MutexManagerConfigurations
			initial_configurations;

		static MutexManagerConfigurations
			default_configurations;
    };
}
