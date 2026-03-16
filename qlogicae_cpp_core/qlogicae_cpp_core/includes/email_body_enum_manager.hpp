#pragma once

#include "email_body.hpp"
#include "abstract_class.hpp"
#include "email_body_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		EmailBodyEnumManager :
			public AbstractClass<EmailBodyEnumManagerConfigurations>
    {
    public:
		EmailBodyEnumManager();

		std::string
			convert_enum_to_string(
				const EmailBody&
					value
			);

		std::string
			convert_enum_to_string();

		EmailBody
			convert_string_to_enum(
				const std::string&
					value
			);

		EmailBody
			convert_string_to_enum();
    };
}
