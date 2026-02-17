#pragma once

#include "abstract_class.hpp"
#include "sqlite_exception.hpp"
#include "sqlite_statement.hpp"
#include "singleton_manager.hpp"
#include "sqlite_database_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		SqliteDatabaseManager :
			public AbstractClass<SqliteDatabaseManagerConfigurations>
    {
    public:
		std::shared_ptr<SQLiteBackend>
			backend;

        static SqliteDatabaseManager&
            singleton;

		SqliteDatabaseManager();

		~SqliteDatabaseManager();

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

