#pragma once

namespace
	QLogicaeCppCore
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
