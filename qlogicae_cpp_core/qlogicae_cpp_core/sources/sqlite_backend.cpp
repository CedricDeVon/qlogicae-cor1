#include "pch.hpp"

#include "../includes/sqlite_backend.hpp"

namespace
	QLogicae::Cor::V1
{
    SQLiteBackend
		::SQLiteBackend(
			sqlite3*
				raw_database
			)
    {
		database_handle =
			raw_database;
    }

	SQLiteBackend
		::SQLiteBackend()
    {
		database_handle =
			nullptr;
    }

    SQLiteBackend
		::~SQLiteBackend()
    {
		if (!database_handle)
		{
			sqlite3_close(
				database_handle
			);
			database_handle = nullptr;
		}
    }
}
