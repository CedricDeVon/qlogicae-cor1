#pragma once

#include "abstract_class.hpp"
#include "sqlite_exception.hpp"
#include "sqlite_statement.hpp"
#include "sqlite_database_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		SQLiteDatabaseManager :
			public QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<SQLiteDatabaseManagerConfigurations>
    {
    public:
        std::shared_ptr<SQLiteBackend>
			backend;
        
		SQLiteDatabaseManager();

		~SQLiteDatabaseManager();

		bool
			construct();

		bool
			destruct();

        SQLiteStatement
			setup_statement(
				const std::string&
					file_path,
				const std::string&
					sql_text
			);

		SQLiteStatement
			setup_statement(
				const std::string&
					sql_text
			);

        int64_t
			last_insert_rowid();

    };
}
