#pragma once

#include "abstract_class.hpp"
#include "sqlite_backend.hpp"
#include "sqlite_exception.hpp"
#include "sqlite_statement.hpp"
#include "singleton_manager.hpp"
#include "sqlite_database_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		SQLiteDatabaseManager :
			public AbstractClass<SQLiteDatabaseManagerConfigurations>
    {
    public:
		std::shared_ptr<SQLiteBackend>
			backend;

        static SQLiteDatabaseManager&
            singleton;

		SQLiteDatabaseManager();

		~SQLiteDatabaseManager();

		bool
			construct();

		bool
			destruct();

        bool
			enable_foreign_keys();

        int64_t
			last_insert_rowid();

        SQLiteStatement
			setup(
				const std::string&
					sql_text
			);
    };
}

