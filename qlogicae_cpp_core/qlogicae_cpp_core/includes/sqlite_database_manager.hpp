#pragma once

#include "abstract_class.hpp"
#include "sqlite_exception.hpp"
#include "sqlite_statement.hpp"
#include "sqlite_database_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		SQLiteDatabaseManager :
			public AbstractClass<SQLiteDatabaseManagerConfigurations>
    {
    public:
        std::shared_ptr<SQLiteBackend>
			backend;
        
		SQLiteDatabaseManager();

		~SQLiteDatabaseManager();

		bool
			construct();

		bool
			destruct();

        SQLiteStatement
			setup_statement(
				const std::string&
					file_path,
				const std::string&
					sql_text
			);

		SQLiteStatement
			setup_statement(
				const std::string&
					sql_text
			);

        int64_t
			last_insert_rowid();

    };
}
