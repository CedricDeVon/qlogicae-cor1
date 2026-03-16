#pragma once

namespace
	QLogicae::Cor::V1
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
