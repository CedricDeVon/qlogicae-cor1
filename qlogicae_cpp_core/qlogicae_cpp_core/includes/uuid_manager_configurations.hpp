#pragma once

#include "uuid.hpp"
#include "text_case.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    struct
		UuidManagerConfigurations :
			AbstractConfigurations<UuidManagerConfigurations>
    {
	public:			
		Uuid
			type =
				Uuid::V4;

		UuidManagerConfigurations();
    };
}

