#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_case_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    class
		TextCaseEnumManager :
			public AbstractClass<TextCaseEnumManagerConfigurations>
    {
    public:        
        static TextCaseEnumManager&
            singleton;

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
