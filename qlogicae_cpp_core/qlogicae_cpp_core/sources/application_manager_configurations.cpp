#include "pch.hpp"

#include "../includes/application_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    ApplicationManagerConfigurations
		ApplicationManagerConfigurations
			::initial_configurations =
				[]()
				{
					ApplicationManagerConfigurations
						configurations;

					return
						configurations;
				}();

	ApplicationManagerConfigurations
		ApplicationManagerConfigurations
			::default_configurations =
				ApplicationManagerConfigurations
					::initial_configurations;
}
