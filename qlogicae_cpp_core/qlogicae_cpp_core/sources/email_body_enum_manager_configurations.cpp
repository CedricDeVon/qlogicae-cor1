#include "pch.hpp"

#include "../includes/email_body_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
	EmailBodyEnumManagerConfigurations
		::EmailBodyEnumManagerConfigurations() :
			AbstractConfigurations<EmailBodyEnumManagerConfigurations>()
	{
		type =
			EmailBody
				::PLAIN;
	}

	EmailBodyEnumManagerConfigurations
		EmailBodyEnumManagerConfigurations
			::initial_configurations;

	EmailBodyEnumManagerConfigurations
		EmailBodyEnumManagerConfigurations
			::default_configurations =
				EmailBodyEnumManagerConfigurations
					::initial_configurations;
}
