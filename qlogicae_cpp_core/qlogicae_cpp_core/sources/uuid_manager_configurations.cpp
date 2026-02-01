#include "pch.hpp"

#include "../includes/uuid_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{	
	UuidManagerConfigurations
		::UuidManagerConfigurations() :
			AbstractConfigurations<UuidManagerConfigurations>()
	{
		type =
			Uuid::V4;
	}

	UuidManagerConfigurations
		UuidManagerConfigurations
			::initial_configurations;

	UuidManagerConfigurations
		UuidManagerConfigurations
			::default_configurations =
				UuidManagerConfigurations
					::initial_configurations;
}
