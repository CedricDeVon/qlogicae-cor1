#pragma once

#include "uuid.hpp"
#include "text_case.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		UuidManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<UuidManagerConfigurations>
    {
	public:			
		Uuid
			type =
				Uuid::V4;

		UuidManagerConfigurations();
    };
}
