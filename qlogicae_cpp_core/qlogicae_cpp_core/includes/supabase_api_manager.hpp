#pragma once

#include "abstract_class.hpp"
#include "supabase_api_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		SupabaseApiManager :
			public AbstractClass<SupabaseApiManagerConfigurations>
    {
    public:		
		SupabaseApiManager();
    };
}
