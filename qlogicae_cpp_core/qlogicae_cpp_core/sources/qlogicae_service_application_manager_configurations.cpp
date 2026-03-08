#include "pch.hpp"

#include "../includes/qlogicae_service_application_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	QLogicaeServiceApplicationManagerConfigurations
		::QLogicaeServiceApplicationManagerConfigurations() :
			AbstractConfigurations<QLogicaeServiceApplicationManagerConfigurations>()
	{
		
	}

	QLogicaeServiceApplicationManagerConfigurations
		QLogicaeServiceApplicationManagerConfigurations
			::initial_configurations;

	QLogicaeServiceApplicationManagerConfigurations
		QLogicaeServiceApplicationManagerConfigurations
			::default_configurations =
				QLogicaeServiceApplicationManagerConfigurations
					::initial_configurations;
}
