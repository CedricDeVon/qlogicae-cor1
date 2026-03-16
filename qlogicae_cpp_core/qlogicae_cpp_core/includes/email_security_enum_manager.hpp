#pragma once

#include "abstract_class.hpp"
#include "email_security.hpp"
#include "email_security_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		EmailSecurityEnumManager :
			public AbstractClass<EmailSecurityEnumManagerConfigurations>
    {
    public:
		EmailSecurityEnumManager();

		std::string
			convert_enum_to_string(
				const EmailSecurity&
					value
			);

		std::string
			convert_enum_to_string();

		EmailSecurity
			convert_string_to_enum(
				const std::string&
					value
			);

		EmailSecurity
			convert_string_to_enum();
    };
}
