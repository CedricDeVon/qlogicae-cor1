#pragma once

namespace
	QLogicaeCppCore
{
    struct
		SQLiteStatementData
    {
    public:
        sqlite3_stmt*
			statement_handle;

        SQLiteStatementData(
            sqlite3_stmt*
				raw_statement
        );

		SQLiteStatementData();
        
        ~SQLiteStatementData();
    };
}
