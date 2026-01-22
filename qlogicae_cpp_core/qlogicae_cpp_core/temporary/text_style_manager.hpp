#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_style_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    class
		TextStyleManager :
			public AbstractClass<TextStyleManagerConfigurations>
    {
    public:        
        static TextStyleManager&
            singleton;

		TextStyleManager();

		~TextStyleManager();

		bool
			construct();

		bool
			destruct();
    };    
}
