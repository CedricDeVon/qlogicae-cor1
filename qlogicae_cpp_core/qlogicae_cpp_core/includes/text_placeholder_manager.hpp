#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_case_manager.hpp"
#include "text_placeholder_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    class
		TextPlaceholderManager :
			public AbstractClass<TextPlaceholderManagerConfigurations>
    {
    public:        
        static TextPlaceholderManager&
            singleton;

		TextPlaceholderManager();

		~TextPlaceholderManager();

		bool
			construct();

		bool
			destruct();

		std::string
			convert_text(
				const std::string&
					text,
				const std::string&
					placeholder
			);
		
		std::string
			convert_text(
				const std::string&
					text
			);
    };    
}
