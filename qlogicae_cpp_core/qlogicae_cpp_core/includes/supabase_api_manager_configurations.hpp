#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		SupabaseApiManagerConfigurations :
			AbstractConfigurations<SupabaseApiManagerConfigurations>
	{
	public:
		static SupabaseApiManagerConfigurations
			initial_configurations;

		static SupabaseApiManagerConfigurations
			default_configurations;

		SupabaseApiManagerConfigurations();
	};
}

