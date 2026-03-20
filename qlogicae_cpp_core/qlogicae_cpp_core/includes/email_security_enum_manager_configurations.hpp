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
				EmailSecurity
					::SSL;

		EmailSecurityEnumManagerConfigurations();
	};
}
