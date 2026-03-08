#include "pch.hpp"

#include "../includes/sqlite_transaction.hpp"

namespace
	QLogicaeCppCore
{
    SQLiteTransaction
		::SQLiteTransaction(
			SQLiteDatabaseManager&
				database_instance
		) :
			database(
				database_instance
			)
    {
        SQLiteStatement
			begin_statement =
				database
					.prepare("BEGIN;");
        		
		committed =
			false;

        begin_statement
			.step();
    }

    SQLiteTransaction
		::~SQLiteTransaction()
    {
        if (!committed)
        {
            try
            {
                SQLiteStatement
					rollback_statement =
						database
							.prepare("ROLLBACK;");
                
                rollback_statement
					.step();
            }
            catch (...)
            {
            
            }
        }
    }

    bool
		SQLiteTransaction
			::commit()
    {
        if (!committed)
        {
            SQLiteStatement
				commit_statement =
					database
						.prepare("COMMIT;");
            
            commit_statement.step();
            committed = true;
        }

		return
			true;
    }
}
