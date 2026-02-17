#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		SqliteDatabaseManagerConfigurations :
			AbstractConfigurations<SqliteDatabaseManagerConfigurations>
	{
	public:		
		std::string
			file_path =
				default_configurations
					.file_path;

		static SqliteDatabaseManagerConfigurations
			initial_configurations;

		static SqliteDatabaseManagerConfigurations
			default_configurations;

		SqliteDatabaseManagerConfigurations();
	};
}

