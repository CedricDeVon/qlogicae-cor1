#pragma once

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		FULL \
	)

#include "sqlite_database_manager.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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

#endif
