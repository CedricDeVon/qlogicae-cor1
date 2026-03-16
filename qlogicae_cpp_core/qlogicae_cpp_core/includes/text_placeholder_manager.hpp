#pragma once

#include "abstract_class.hpp"
#include "text_case_manager.hpp"
#include "text_placeholder_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    class
		TextPlaceholderManager :
			public AbstractClass<TextPlaceholderManagerConfigurations>
    {
    public:        
		TextPlaceholderManager();

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

