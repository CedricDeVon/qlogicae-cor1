#include "pch.hpp"

#include "../includes/sqlite_database_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	SQLiteDatabaseManagerConfigurations
		::SQLiteDatabaseManagerConfigurations() :
			AbstractConfigurations<SQLiteDatabaseManagerConfigurations>()
	{
		file_path =
			"";
	}

	SQLiteDatabaseManagerConfigurations
		SQLiteDatabaseManagerConfigurations
			::initial_configurations;

	SQLiteDatabaseManagerConfigurations
		SQLiteDatabaseManagerConfigurations
			::default_configurations =
				SQLiteDatabaseManagerConfigurations
					::initial_configurations;
}

