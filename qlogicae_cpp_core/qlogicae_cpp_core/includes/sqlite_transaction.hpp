#pragma once

#include "sqlite_database_manager.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		SQLiteTransaction
    {
    public:
        bool
			committed;
        
        SQLiteDatabaseManager&
			database;

        SQLiteTransaction(
            SQLiteDatabaseManager&
				database_instance
        );
        
        ~SQLiteTransaction();

        bool
			commit();
    };
}

