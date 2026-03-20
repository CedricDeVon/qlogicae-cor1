#pragma once

#include "email_body.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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
