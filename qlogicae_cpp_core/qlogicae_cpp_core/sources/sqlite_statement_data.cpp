#include "pch.hpp"

#include "../includes/sqlite_statement_data.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    SQLiteStatementData
		::SQLiteStatementData(
			sqlite3_stmt*
				raw_statement
		)
    {
		statement_handle =
			raw_statement;
    }

	SQLiteStatementData
		::SQLiteStatementData()
    {
		statement_handle =
			nullptr;
    }

    SQLiteStatementData
		::~SQLiteStatementData()
    {
        sqlite3_finalize(
			statement_handle
		);
    }
}
