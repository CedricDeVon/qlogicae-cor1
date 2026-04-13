#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		MutexManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<MutexManagerConfigurations>
    {
	public:
        std::string
            name =
				"static";

		MutexManagerConfigurations();
    };
}
