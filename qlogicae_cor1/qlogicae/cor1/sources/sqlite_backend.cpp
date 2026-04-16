#include "pch.hpp"

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		SQLiteBackend \
	)

#include "../includes/sqlite_backend.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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

#endif
