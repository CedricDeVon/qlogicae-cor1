#include "pch.hpp"

#include "../includes/qlogicae_desktop_application_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	QLogicaeDesktopApplicationManagerConfigurations
		::QLogicaeDesktopApplicationManagerConfigurations() :
			AbstractConfigurations<QLogicaeDesktopApplicationManagerConfigurations>()
	{
		
	}

	QLogicaeDesktopApplicationManagerConfigurations
		QLogicaeDesktopApplicationManagerConfigurations
			::initial_configurations;

	QLogicaeDesktopApplicationManagerConfigurations
		QLogicaeDesktopApplicationManagerConfigurations
			::default_configurations =
				QLogicaeDesktopApplicationManagerConfigurations
					::initial_configurations;
}
