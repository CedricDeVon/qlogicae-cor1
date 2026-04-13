#pragma once

#include "sqlite_exception.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	class SQLiteRow;

    class SQLiteRow
    {
    public:
        sqlite3_stmt*
			statement;
        
        mutable std::unordered_map<std::string, int>
			column_name_to_index;

        SQLiteRow(
            sqlite3_stmt*
				raw_statement
        );

        template<typename Type> Type
			get(
				int
					column_index
			);

        template<typename Type> Type
			get(
				const std::string&
					column_name
			);

        int
			get_column_count();

        std::string
			get_column_name(
				int
					column_index
			);

        int
			get_index(
				const std::string&
					column_name
			);
    };
}
