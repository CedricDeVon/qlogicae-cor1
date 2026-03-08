#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		SQLiteDatabaseManagerConfigurations :
			AbstractConfigurations<SQLiteDatabaseManagerConfigurations>
	{
	public:		
		std::string
			file_path =
				default_configurations
					.file_path;

		static SQLiteDatabaseManagerConfigurations
			initial_configurations;

		static SQLiteDatabaseManagerConfigurations
			default_configurations;

		SQLiteDatabaseManagerConfigurations();
	};
}

