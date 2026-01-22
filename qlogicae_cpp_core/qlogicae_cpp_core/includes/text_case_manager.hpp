#pragma once

#include "text_case.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_case_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    class
		TextCaseManager :
			public AbstractClass<TextCaseManagerConfigurations>
    {
    public:        
        static TextCaseManager&
            singleton;

		TextCaseManager();

		~TextCaseManager();

		bool
			construct();

		bool
			destruct();

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

