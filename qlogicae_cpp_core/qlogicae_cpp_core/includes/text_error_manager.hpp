#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_error_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    class
		TextErrorManager :
			public AbstractClass<TextErrorManagerConfigurations>
    {
    public:        
        static TextErrorManager&
            singleton;

		TextErrorManager();

		~TextErrorManager();

		bool
			construct();

		bool
			destruct();

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
