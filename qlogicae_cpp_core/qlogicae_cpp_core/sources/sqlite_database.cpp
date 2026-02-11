#include "pch.hpp"

#include "../includes/sqlite_database.hpp"

namespace
	QLogicaeCppCore
{
    SQLiteDatabase
		::SQLiteDatabase(
			const std::string&
				file_path
			)
    {
        sqlite3*
			raw_handle =
				nullptr;

        int
			result =
				sqlite3_open(
					file_path.c_str(),
					&raw_handle
				);

        if (result != SQLITE_OK)
        {
            throw
				SQLiteException(
					"Failed To Open Database",
					result,
					result
				);
        }

        backend =
			std::make_shared<SQLiteBackend>(
				raw_handle
			);
    }

    SQLiteDatabase
		::SQLiteDatabase()
    {
        
    }

    SQLiteStatement
		SQLiteDatabase
			::prepare(
				const std::string&
					sql_text
			)
    {
        return
			SQLiteStatement(
				backend,
				sql_text
			);
    }

    int64_t
		SQLiteDatabase
			::last_insert_rowid()
    {
        return
			sqlite3_last_insert_rowid(
				backend
					->database_handle
			);
    }

    bool
		SQLiteDatabase
			::enable_foreign_keys()
    {
        SQLiteStatement
			pragma_statement =
				prepare(
					"PRAGMA foreign_keys = ON;"
				);

        pragma_statement
			.step();

		return
			true;
    }
}
