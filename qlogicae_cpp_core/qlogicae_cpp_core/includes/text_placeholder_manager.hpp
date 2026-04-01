#pragma once

#include "abstract_class.hpp"
#include "text_case_manager.hpp"
#include "text_placeholder_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
