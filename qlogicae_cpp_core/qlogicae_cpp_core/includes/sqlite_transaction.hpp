#pragma once

#include "sqlite_database.hpp"

namespace
	QLogicaeCppCore
{
    class
		SQLiteTransaction
    {
    public:
        bool
			committed;
        
        SQLiteDatabase&
			database;

        SQLiteTransaction(
            SQLiteDatabase&
				database_instance
        );
        
        ~SQLiteTransaction();

        bool
			commit();
    };
}
