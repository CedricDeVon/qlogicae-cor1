#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "rocksdb_database_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    class
		RocksDbDatabaseManager :
			public AbstractClass<RocksDbDatabaseManagerConfigurations>
    {
    public:        
		rocksdb::DB*
			object{};

		std::string
			file_path;

		rocksdb::Options
			options;

		rocksdb::WriteOptions
			write_options;

		rocksdb::BlockBasedTableOptions
			table_options;

		rocksdb::TransactionDBOptions
			txn_db_options;

		rocksdb::Status
			status;

		rocksdb::WriteBatch
			write_batch;

		std::vector<std::string>
			cf_names;

		rocksdb::ReadOptions
			read_options;

		rocksdb::Transaction*
			transaction{};

		rocksdb::TransactionDB*
			transaction_db{};

		rocksdb::TransactionDBOptions
			txn_options;

		std::unique_ptr<const rocksdb::FilterPolicy>
			bloom_filter;

		std::unordered_map<std::string, rocksdb::ColumnFamilyHandle*>
			column_families;

		boost::mutex
			feature_handling_mutex_2;

		boost::mutex
			feature_handling_mutex_3;

        static RocksDbDatabaseManager&
            singleton;

		RocksDbDatabaseManager();

		bool
			setup(
				const RocksDbDatabaseManagerConfigurations&
					new_configurations
			) override;

		bool
			is_path_found(
				const std::string&
					value
			);

		bool
			is_key_found(
				const std::string&
					value
			);

		bool
			remove_value(
				const std::string&
					value
			);

		bool
			create_column_family(
				const std::string&
					value
			);

		bool
			drop_column_family(
				const std::string&
					value
			);

		bool
			use_column_family(
				const std::string&
					value
			);

		bool
			create_backup(
				const std::string&
					value
			);

		bool
			restore_backup(
				const std::string&
					value
			);

		bool
			create_checkpoint(
				const std::string&
					value
			);

		std::string
			get_with_bounds(
				const std::string&
					value,
				const uint64_t&
					minimum,
				const uint64_t&
					maximum
			);

		rocksdb::ColumnFamilyHandle*
			get_cf_handle(
				const std::string&
				name
			);

		bool
			batch_execute();

		bool
			begin_batch();

		bool
			commit_batch();

		bool
			begin_transaction();

		bool
			commit_transaction();

		bool
			rollback_transaction();

		bool
			clear();

		bool
			open();

		bool
			close();

		template <typename Type> bool 
			set_value(
				const std::string&
					value,
				const Type&
					type
			);

		template <typename Type> bool 
			batch_set_value(
				const std::string&
					value,
				const Type&
					type
			);

		template <typename Type> bool 
			batch_remove_value(
				const std::string&
					value,
				const Type&
					type
			);

		template <typename Type> Type
			get_value(
				const std::string&
					value
			);

		template <typename Type> std::string
			serialize(
				const Type&
					value
			);

		template <typename Type> Type
			deserialize(
				const std::string&
					value
			);
    };    

    template <typename Type> Type
		RocksDbDatabaseManager
			::get_value(
				const std::string&
					key
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						key.empty()
					)
				)
			)
			{
				return
					Type {};
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

			std::string value = "";

			object->Get(read_options, key, &value);

			return
				value;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs<Type>(
					exception
				);
		}
	}

	template <typename Type> bool
		RocksDbDatabaseManager
			::set_value(
				const std::string&
					key,
				const Type&
					value
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						key.empty()
					)
				)
			)
			{
				return
					false;
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

			auto result_value = object->Put(
				write_options,
				key,
				serialize(value)
			);

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs(
					exception
				);
		}
	}

	template <typename Type> bool
		RocksDbDatabaseManager
			::batch_set_value(
				const std::string&
					key,
				const Type&
					value
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						key.empty()
					)
				)
			)
			{
				return
					false;
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

			write_batch.Put(key, serialize(value));

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs(
					exception
				);
		}
	}

	template <typename Type> bool
		RocksDbDatabaseManager
			::batch_remove_value(
				const std::string&
					key,
				const Type&
					type
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						key.empty()
					)
				)
			)
			{
				return
					false;
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

			write_batch.Delete(key);

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs(
					exception
				);
		}
	}

	template <typename Type> std::string
		RocksDbDatabaseManager
			::serialize(
				const Type&
					value
			)
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
					value;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_2
					);
			}

			return
				value;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs<std::string>(
					exception
				);
		}
	}

	template <typename Type> Type
		RocksDbDatabaseManager
			::deserialize(
				const std::string&
					value
			)
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
					value;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_2
					);
			}

			return
				value;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs<Type>(
					exception
				);
		}
	}

	template <> std::string
		RocksDbDatabaseManager
			::serialize<std::string>(
				const std::string&
					value
			)
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
					value;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_2
					);
			}

			return
				value;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs<std::string>(
					exception
				);
		}
	}

	template <> std::string
		RocksDbDatabaseManager
			::deserialize<std::string>(
				const std::string&
					value
			)
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
					value;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_2
					);
			}

			return
				value;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs<std::string>(
					exception
				);
		}
    }
}

