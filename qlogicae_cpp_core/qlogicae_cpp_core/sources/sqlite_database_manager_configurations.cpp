#include "pch.hpp"

#include "../includes/sqlite_database_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	SqliteDatabaseManagerConfigurations
		::SqliteDatabaseManagerConfigurations() :
			AbstractConfigurations<SqliteDatabaseManagerConfigurations>()
	{
		file_path =
			"";
	}

	SqliteDatabaseManagerConfigurations
		SqliteDatabaseManagerConfigurations
			::initial_configurations;

	SqliteDatabaseManagerConfigurations
		SqliteDatabaseManagerConfigurations
			::default_configurations =
				SqliteDatabaseManagerConfigurations
					::initial_configurations;
}

