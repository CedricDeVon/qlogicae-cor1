#pragma once

namespace
	QLogicae::Cor::V1
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
