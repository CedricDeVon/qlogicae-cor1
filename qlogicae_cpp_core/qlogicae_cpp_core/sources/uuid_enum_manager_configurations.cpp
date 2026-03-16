#include "pch.hpp"

#include "../includes/uuid_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
	UuidEnumManagerConfigurations
		::UuidEnumManagerConfigurations() :
			AbstractConfigurations<UuidEnumManagerConfigurations>()
	{
		type =
			Uuid
				::V4;
	}

	UuidEnumManagerConfigurations
		UuidEnumManagerConfigurations
			::initial_configurations;

	UuidEnumManagerConfigurations
		UuidEnumManagerConfigurations
			::default_configurations =
				UuidEnumManagerConfigurations
					::initial_configurations;
}
