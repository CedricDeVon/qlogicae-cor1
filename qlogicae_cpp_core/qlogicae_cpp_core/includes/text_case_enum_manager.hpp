#pragma once

#include "abstract_class.hpp"
#include "text_case_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    class
		TextCaseEnumManager :
			public AbstractClass<TextCaseEnumManagerConfigurations>
    {
    public:        
		TextCaseEnumManager();

		std::string
			convert_enum_to_string(
				const TextCase&
					value
			);

		std::string
			convert_enum_to_string();

		TextCase
			convert_string_to_enum(
				const std::string&
					value
			);

		TextCase
			convert_string_to_enum();
    };    
}
