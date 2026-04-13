#pragma once

#include "uuid.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		UuidEnumManagerConfigurations :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<UuidEnumManagerConfigurations>
	{
	public:	
		Uuid
			type =
				Uuid
					::V4;

		UuidEnumManagerConfigurations();
	};
}
