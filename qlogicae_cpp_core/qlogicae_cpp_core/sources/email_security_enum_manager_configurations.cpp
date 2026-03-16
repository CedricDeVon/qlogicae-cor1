#include "pch.hpp"

#include "../includes/email_security_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
	EmailSecurityEnumManagerConfigurations
		::EmailSecurityEnumManagerConfigurations() :
			AbstractConfigurations<EmailSecurityEnumManagerConfigurations>()
	{
		type =
			EmailSecurity
				::SSL;
	}

	EmailSecurityEnumManagerConfigurations
		EmailSecurityEnumManagerConfigurations
			::initial_configurations;

	EmailSecurityEnumManagerConfigurations
		EmailSecurityEnumManagerConfigurations
			::default_configurations =
				EmailSecurityEnumManagerConfigurations
					::initial_configurations;
}
