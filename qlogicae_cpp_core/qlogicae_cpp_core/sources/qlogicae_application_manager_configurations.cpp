#include "pch.hpp"

#include "../includes/qlogicae_application_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	QLogicaeApplicationManagerConfigurations
		::QLogicaeApplicationManagerConfigurations() :
			AbstractConfigurations<QLogicaeApplicationManagerConfigurations>()
	{
		
	}

	QLogicaeApplicationManagerConfigurations
		QLogicaeApplicationManagerConfigurations
			::initial_configurations;

	QLogicaeApplicationManagerConfigurations
		QLogicaeApplicationManagerConfigurations
			::default_configurations =
				QLogicaeApplicationManagerConfigurations
					::initial_configurations;
}

