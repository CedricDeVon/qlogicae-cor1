#pragma once

#include "sqlite_exception.hpp"
#include "sqlite_statement.hpp"

namespace
	QLogicaeCppCore
{
    class
		SQLiteDatabase
    {
    public:
        std::shared_ptr<SQLiteBackend>
			backend;
        
		SQLiteDatabase(
            const std::string&
				file_path
        );

		SQLiteDatabase();

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
