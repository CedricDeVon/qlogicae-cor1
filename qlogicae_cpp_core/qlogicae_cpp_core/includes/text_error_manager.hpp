#pragma once

#include "abstract_class.hpp"
#include "text_error_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    class
		TextErrorManager :
			public AbstractClass<TextErrorManagerConfigurations>
    {
    public:        
		TextErrorManager();

		std::string
			convert_text(
				const std::string&
					origin,
				const std::string&
					message
			);

		std::string
			convert_text(
				const std::string&
					message
			);
    };    
}

