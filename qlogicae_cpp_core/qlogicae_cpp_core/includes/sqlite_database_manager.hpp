#pragma once

#include "sqlite_exception.hpp"
#include "sqlite_statement.hpp"

namespace
	QLogicaeCppCore
{
    class
		SQLiteDatabaseManager
    {
    public:
        std::shared_ptr<SQLiteBackend>
			backend;
        
		SQLiteDatabaseManager(
            const std::string&
				file_path
        );

		SQLiteDatabaseManager();

        bool
			enable_foreign_keys();

        int64_t
			last_insert_rowid();

        SQLiteStatement
			prepare(
				const std::string&
					sql_text
			);
    };
}
