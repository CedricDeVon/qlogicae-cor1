#include "pch.hpp"

#include "../includes/sqlite_transaction.hpp"

namespace
	QLogicae::Cor::V1
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
					.setup_statement("BEGIN;");
        		
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
							.setup_statement("ROLLBACK;");
                
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
						.setup_statement("COMMIT;");
            
            commit_statement.step();
            committed = true;
        }

		return
			true;
    }
}
