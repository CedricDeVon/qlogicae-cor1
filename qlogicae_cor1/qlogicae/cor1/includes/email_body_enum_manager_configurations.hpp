#pragma once

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		FULL \
	)

#include "email_body.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		EmailBodyEnumManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<EmailBodyEnumManagerConfigurations>
	{
	public:	
		EmailBody
			type =
				EmailBody
					::PLAIN;

		EmailBodyEnumManagerConfigurations();
	};
}

#endif
