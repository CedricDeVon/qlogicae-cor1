#pragma once

#include "text_encoding.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_encoding_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    class
		TextEncodingEnumManager :
			public AbstractClass<TextEncodingEnumManagerConfigurations>
    {
    public:        
        static TextEncodingEnumManager&
            singleton;

		TextEncodingEnumManager();

		std::string
			convert_enum_to_string(
				const TextEncoding&
					value
			);

		std::string
			convert_enum_to_string();

		TextEncoding
			convert_string_to_enum(
				const std::string&
					value
			);

		TextEncoding
			convert_string_to_enum();
    };    
}
