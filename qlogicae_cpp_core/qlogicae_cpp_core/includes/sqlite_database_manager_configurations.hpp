#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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

