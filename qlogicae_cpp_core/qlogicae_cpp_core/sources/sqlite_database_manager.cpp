#include "pch.hpp"

#include "../includes/sqlite_database_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{	
    SQLiteDatabaseManager
		::SQLiteDatabaseManager()
    {
        try
		{
			construct();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);
		}	
    }

	SQLiteDatabaseManager
		::~SQLiteDatabaseManager()
    {
        try
		{
			destruct();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);
		}	
    }

	bool
		SQLiteDatabaseManager
			::construct()
	{
		try
		{
			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);

			return
				{};
		}	
	}

	bool
		SQLiteDatabaseManager
			::destruct()
	{
		try
		{
			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);

			return
				{};
		}	
	}

    SQLiteStatement
		SQLiteDatabaseManager
			::setup_statement(
				const std::string&
					file_path,
				const std::string&
					sql_text
			)
    {
		try
		{
			return
				SQLiteStatement(
					file_path,
					sql_text
				);
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);

			return
				SQLiteStatement(
					configurations
						.file_path,
					""
				);
		}	        
    }

	SQLiteStatement
		SQLiteDatabaseManager
			::setup_statement(
				const std::string&
					sql_text
			)
    {
		try
		{
			return
				SQLiteStatement(
					configurations
						.file_path,
					sql_text
				);
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);

			return
				SQLiteStatement(
					configurations
						.file_path,
					""
				);
		}	        
    }

    int64_t
		SQLiteDatabaseManager
			::last_insert_rowid()
    {
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					0;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			return
				sqlite3_last_insert_rowid(
					backend
						->database_handle
				);
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);

			return
				{};
		}
    }
}
