#pragma once

#include "email_security.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		EmailSecurityEnumManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<EmailSecurityEnumManagerConfigurations>
	{
	public:	
		EmailSecurity
			type =
				EmailSecurity
					::SSL;

		EmailSecurityEnumManagerConfigurations();
	};
}
