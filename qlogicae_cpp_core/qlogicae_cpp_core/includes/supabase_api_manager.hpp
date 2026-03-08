#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "supabase_api_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		SupabaseApiManager :
			public AbstractClass<SupabaseApiManagerConfigurations>
    {
    public:		
        static SupabaseApiManager&
            singleton;

		SupabaseApiManager();
    };
}
