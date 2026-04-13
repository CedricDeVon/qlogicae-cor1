#pragma once

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class SQLiteException :
        public std::runtime_error
    {
    public:
		int
			error_code;

		int
			extended_code;

        SQLiteException(
            const std::string&
				message,
            const int
				error_code,
            const int
				extended_code
        );

		SQLiteException();
    };
}
