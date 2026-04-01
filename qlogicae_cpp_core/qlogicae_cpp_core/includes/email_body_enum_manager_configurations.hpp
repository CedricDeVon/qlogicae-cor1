#pragma once

#include "email_body.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		EmailBodyEnumManagerConfigurations :
			AbstractConfigurations<EmailBodyEnumManagerConfigurations>
	{
	public:	
		EmailBody
			type =
				EmailBody
					::PLAIN;

		EmailBodyEnumManagerConfigurations();
	};
}
