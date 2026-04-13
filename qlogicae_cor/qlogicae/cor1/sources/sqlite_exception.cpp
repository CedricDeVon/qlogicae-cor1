#include "pch.hpp"

#include "../includes/sqlite_exception.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    SQLiteException
		::SQLiteException(
				const std::string&
					message,
				const int
					error_code,
				const int
					extended_code
		) :
			std::runtime_error(
				message
			),
			error_code(
				error_code
			),
			extended_code(
				extended_code
			)
    {
		
    }

	SQLiteException
		::SQLiteException() :
			std::runtime_error(
				"SQLiteException"
			)
    {
		error_code =
			0;

		extended_code =
			0;
    }
}

