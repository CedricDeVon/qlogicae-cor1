#include "pch.hpp"

#include "../includes/sqlite_row.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	SQLiteRow
		::SQLiteRow(
			sqlite3_stmt*
				raw_statement
		) :
			statement(
				raw_statement
			)
	{

	}

    template<> int
		SQLiteRow::get<int>(
			int
				column_index
		)
    {
        if (sqlite3_column_type(statement, column_index) == SQLITE_NULL)
        {
            throw
				SQLiteException(
					"Column Should Not Be Null",
					-1,
					-1
				);
        }

        return
			sqlite3_column_int(
				statement,
				column_index
			);
    }

    template<> double
		SQLiteRow
			::get<double>(
				int
					column_index
			)
    {
        if (sqlite3_column_type(statement, column_index) == SQLITE_NULL)
        {
            throw
				SQLiteException(
					"Column Should Not Be Null",
					-1,
					-1
				);
        }

        return
			sqlite3_column_double(
				statement,
				column_index
			);
    }

    template<> float
		SQLiteRow
			::get<float>(
				int
					column_index
			)
    {
        return
			static_cast<float>(
				get<double>(
					column_index
				)
			);
    }

    template<> bool
		SQLiteRow
			::get<bool>(
				int
					column_index
			)
    {
        return
			get<int>(column_index) != 0;
    }

    template<> std::string
		SQLiteRow
			::get<std::string>(
				int
					column_index
			)
    {
        const char*
			text =
				reinterpret_cast<const char*>(
					sqlite3_column_text(
						statement,
						column_index
					)
				);

        return
			text ?
				std::string(text) :
				"";
    }

    template<> int
		SQLiteRow
			::get<int>(
				const std::string&
					column_name
			)
    {
        return
			get<int>(
				get_index(
					column_name
				)
			);
    }

    template<> std::string
		SQLiteRow
			::get<std::string>(
				const std::string&
					column_name
			)
    {
        return
			get<std::string>(
				get_index(
					column_name
				)
			);
    }

	int
		SQLiteRow
			::get_column_count()
	{
		return
			sqlite3_column_count(
				statement
			);
	}

	std::string
		SQLiteRow
			::get_column_name(
				int
					column_index
			)
	{
		const char* name =
			sqlite3_column_name(
				statement,
				column_index
			);

		return name ?
			std::string(name) :
			"";
	}

	int
		SQLiteRow
			::get_index(
				const std::string&
					column_name
			)
	{
		auto
			it =
				column_name_to_index
					.find(
						column_name
					);

		if (it != column_name_to_index.end())
		{
			return
				it->second;
		}

		int
			count =
				get_column_count();

		for
		(
			int index = 0;
			index < count;
			++index
		)
		{
			if (get_column_name(index) == column_name)
			{
				column_name_to_index[column_name] =
					index;

				return
					index;
			}
		}

		throw
			SQLiteException("column name not found", -1, -1);
	}
}
