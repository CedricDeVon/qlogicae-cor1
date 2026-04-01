#pragma once

#include "email_security.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
