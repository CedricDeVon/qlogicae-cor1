#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
    struct
		MutexManagerConfigurations :
			AbstractConfigurations<MutexManagerConfigurations>
    {
	public:
        std::string
            name =
				"static";

		MutexManagerConfigurations();
    };
}

