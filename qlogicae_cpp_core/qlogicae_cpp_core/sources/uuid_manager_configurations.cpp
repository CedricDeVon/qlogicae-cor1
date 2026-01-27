#include "pch.hpp"

#include "../includes/uuid_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	UuidManagerConfigurations
		UuidManagerConfigurations
			::initial_configurations =
				[]()
				{
					UuidManagerConfigurations
						configurations;

					configurations
						.type =
							Uuid::V4;

					return
						configurations;
				}();

	UuidManagerConfigurations
		UuidManagerConfigurations
			::default_configurations =
				UuidManagerConfigurations
					::initial_configurations;
}
