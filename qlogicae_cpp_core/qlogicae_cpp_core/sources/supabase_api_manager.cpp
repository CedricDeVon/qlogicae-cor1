#include "pch.hpp"

#include "../includes/supabase_api_manager.hpp"

namespace
	QLogicaeCppCore
{        
	SupabaseApiManager&
		SupabaseApiManager
			::singleton = 
				SingletonManager
					::get_singleton<SupabaseApiManager>();	


	
	SupabaseApiManager
		::SupabaseApiManager() :
			AbstractClass<SupabaseApiManagerConfigurations>()
    {
        
    }
}
