#pragma once

#include "uuid.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		UuidEnumManagerConfigurations :
			AbstractConfigurations<UuidEnumManagerConfigurations>
	{
	public:	
		Uuid
			type =
				Uuid
					::V4;

		UuidEnumManagerConfigurations();
	};
}
