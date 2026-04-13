#pragma once

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
