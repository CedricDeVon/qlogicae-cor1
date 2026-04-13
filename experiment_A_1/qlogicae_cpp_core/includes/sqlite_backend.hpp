#pragma once

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		SQLiteBackend
    {
    public:
        sqlite3*
			database_handle;

        SQLiteBackend(
            sqlite3*
				raw_database
        );

		SQLiteBackend();

        ~SQLiteBackend();
    };
}
