#pragma once

#include "email_security.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		EmailSecurityEnumManagerConfigurations :
			AbstractConfigurations<EmailSecurityEnumManagerConfigurations>
	{
	public:	
		EmailSecurity
			type =
				default_configurations
					.type;

		static EmailSecurityEnumManagerConfigurations
			initial_configurations;

		static EmailSecurityEnumManagerConfigurations
			default_configurations;

		EmailSecurityEnumManagerConfigurations();
	};
}
