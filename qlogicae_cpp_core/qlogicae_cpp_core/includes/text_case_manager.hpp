#pragma once

#include "text_case.hpp"
#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "text_case_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    class
		TextCaseManager :
			public AbstractClass<TextCaseManagerConfigurations>
    {
    public:        
		TextCaseManager();

		std::string
			convert_text(
				const std::string&
					text,
				const TextCase&
					target_type
			);

		std::string
			convert_text(
				const std::string&
					text
			);	
    };    
}
