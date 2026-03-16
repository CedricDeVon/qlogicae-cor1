#include "pch.hpp"

#include "../includes/supabase_api_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	SupabaseApiManagerConfigurations
		::SupabaseApiManagerConfigurations() :
			AbstractConfigurations<SupabaseApiManagerConfigurations>()
	{
		
	}

	SupabaseApiManagerConfigurations
		SupabaseApiManagerConfigurations
			::initial_configurations;

	SupabaseApiManagerConfigurations
		SupabaseApiManagerConfigurations
			::default_configurations =
				SupabaseApiManagerConfigurations
					::initial_configurations;
}
