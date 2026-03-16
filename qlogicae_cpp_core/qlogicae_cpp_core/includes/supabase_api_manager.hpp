#pragma once

#include "abstract_class.hpp"
#include "supabase_api_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		SupabaseApiManager :
			public AbstractClass<SupabaseApiManagerConfigurations>
    {
    public:		
		SupabaseApiManager();
    };
}
