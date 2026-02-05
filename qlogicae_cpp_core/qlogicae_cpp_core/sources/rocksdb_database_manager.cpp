#include "pch.hpp"

#include "../includes/rocksdb_database_manager.hpp"

namespace
	QLogicaeCppCore
{	    
    RocksDbDatabaseManager&
        RocksDbDatabaseManager
			::singleton =
				SingletonManager
					::get_singleton<RocksDbDatabaseManager>();



	RocksDbDatabaseManager
		::RocksDbDatabaseManager() :
			AbstractClass<RocksDbDatabaseManagerConfigurations>()
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

	RocksDbDatabaseManager
		::~RocksDbDatabaseManager()
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
        RocksDbDatabaseManager
			::construct()
    {
        try
        {			
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_utility_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

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

    bool
        RocksDbDatabaseManager
			::destruct()
    {
        try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_utility_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

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


	bool
		RocksDbDatabaseManager
			::setup(
				const RocksDbDatabaseManagerConfigurations&
					new_configurations
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
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			configurations =
				new_configurations;

			options.create_if_missing = configurations.create_if_missing;
            options.max_open_files = configurations.max_open_files;
            options.use_fsync = configurations.use_fsync;
            options.use_direct_reads = configurations.use_direct_reads;
            options.use_direct_io_for_flush_and_compaction =
                configurations.use_direct_io_for_flush_and_compaction;
            options.max_background_flushes = configurations.max_background_flushes;
            options.compression = configurations.compression;

            options.compaction_style = configurations.compaction_style;
            options.level0_file_num_compaction_trigger =
                configurations.level0_file_num_compaction_trigger;
            options.level0_slowdown_writes_trigger =
                configurations.level0_slowdown_writes_trigger;
            options.level0_stop_writes_trigger =
                configurations.level0_stop_writes_trigger;

            options.write_buffer_size = configurations.write_buffer_size;
            options.max_write_buffer_number = configurations.max_write_buffer_number;
            options.min_write_buffer_number_to_merge =
                configurations.min_write_buffer_number_to_merge;
            options.target_file_size_base = configurations.target_file_size_base;
            options.max_bytes_for_level_base = configurations.max_bytes_for_level_base;
            options.bytes_per_sync = configurations.bytes_per_sync;

            write_options.sync = configurations.write_sync;
            write_options.disableWAL = configurations.write_disable_wal;

            table_options.no_block_cache = configurations.no_block_cache;
            table_options.block_restart_interval = configurations.block_restart_interval;
            table_options.block_size = configurations.block_size;

            options.IncreaseParallelism(static_cast<int>(
                std::thread::hardware_concurrency()));
            options.OptimizeLevelStyleCompaction();
            options.env->SetBackgroundThreads(static_cast<int>(
                configurations.background_threads));

            table_options.filter_policy.reset(
                rocksdb::NewBloomFilterPolicy(configurations.new_bloom_filter_policy));

            options.table_factory.reset(
                rocksdb::NewBlockBasedTableFactory(table_options));

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

	bool
		RocksDbDatabaseManager
			::is_path_found(
				const std::string&
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
						value.empty()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			return
				std::filesystem::exists(value);
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

	bool
		RocksDbDatabaseManager
			::is_key_found(
				const std::string&
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
						value.empty() ||
						object == nullptr
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			std::string result;

			return object->Get(
				read_options,
				std::string(value),
				&result
			).ok();
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

	bool
		RocksDbDatabaseManager
			::remove_value(
				const std::string&
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
						value.empty()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			return
				object->Delete(
					write_options,
					value
				).ok();
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

	bool
		RocksDbDatabaseManager
			::create_column_family(
				const std::string&
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
						value.empty()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			rocksdb::ColumnFamilyHandle* handle = nullptr;

			bool result = object->CreateColumnFamily(
				rocksdb::ColumnFamilyOptions(), value, &handle).ok();

			if (result)
			{
				column_families.emplace(std::move(value), handle);
			}
	
			return
				result;
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

	bool
		RocksDbDatabaseManager
			::drop_column_family(
				const std::string&
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
						value.empty()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			auto iterator = column_families.find(value);

			if (iterator == column_families.end())
			{
				return
					false;
			}

			bool result = object->DropColumnFamily(iterator->second).ok();

			if (result)
			{
				object->DestroyColumnFamilyHandle(iterator->second);
				column_families.erase(iterator);
			}

			return
				result;
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

	bool
		RocksDbDatabaseManager
			::use_column_family(
				const std::string&
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
						value.empty()
					)
				)
			)
			{
				return
					column_families.contains(
						value
					);
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			
		
			return
				column_families.contains(
					value
				);
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

	bool
		RocksDbDatabaseManager
			::create_backup(
				const std::string&
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
						value.empty()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			rocksdb::BackupEngine* backup;
			rocksdb::BackupEngineOptions options(value);

			auto result = rocksdb::BackupEngine::Open(
				rocksdb::Env::Default(), options, &backup);

			if (!result.ok())
			{
				return false;
			}

			result = backup->CreateNewBackup(object);
			delete backup;

			return
				result.ok();
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

	bool
		RocksDbDatabaseManager
			::restore_backup(
				const std::string&
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
						value.empty()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			close();

			rocksdb::BackupEngineReadOnly* backup;
			rocksdb::BackupEngineOptions options(value);

			auto result = rocksdb::BackupEngineReadOnly::Open(
				rocksdb::Env::Default(),
				options, &backup
			);

			if (!result.ok())
			{
				return false;
			}

			result = backup->RestoreDBFromLatestBackup(file_path, file_path);
			delete backup;
			if (!result.ok())
			{
				return false;
			}
		
			return
				open();
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

	bool
		RocksDbDatabaseManager
			::create_checkpoint(
				const std::string&
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
						value.empty()
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			rocksdb::Checkpoint* checkpoint;
			auto string = rocksdb::Checkpoint::Create(object, &checkpoint);

			if (!string.ok())
			{
				return false;
			}

			string = checkpoint->CreateCheckpoint(value);
			delete checkpoint;

			return
				string.ok();
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

	std::string
		RocksDbDatabaseManager
			::get_with_bounds(
				const std::string&
					value,
				const uint64_t&
					size,
				const uint64_t&
					offset
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
						value.empty() ||
						object == nullptr
					)
				)
			)
			{
				return
					"";
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			rocksdb::PinnableSlice pvalue;
			rocksdb::ReadOptions options;
			options.verify_checksums = true;

			auto s = object->Get(options, object->DefaultColumnFamily(),
				value, &pvalue);

			if (!s.ok())
			{
				return
					"";
			}

			const uint64_t psize =
				static_cast<uint64_t>(pvalue.size());

			if (offset >= psize)
			{
				return
					"";
			}

			const uint64_t max_size =
				psize - offset;

			const size_t use_size =
				static_cast<size_t>(std::min<uint64_t>(size, max_size));

			return
				std::string(
					pvalue.data() + static_cast<size_t>(offset), use_size
				);
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

	bool
		RocksDbDatabaseManager
			::batch_execute()
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
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_2
					);
			}			

			auto string = object->Write(
				write_options, &write_batch);
			write_batch.Clear();

			return
				string.ok();
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

	bool
		RocksDbDatabaseManager
			::begin_batch()
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
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			write_batch.Clear();

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

	bool
		RocksDbDatabaseManager
			::commit_batch()
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
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			return
				batch_execute();
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

	bool
		RocksDbDatabaseManager
			::begin_transaction()
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
						transaction
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			transaction = transaction_db->BeginTransaction(
				write_options
			);

			return
				transaction != nullptr;
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

	bool
		RocksDbDatabaseManager
			::commit_transaction()
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
						!transaction
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			auto string = transaction->Commit();
			delete transaction;
			transaction = nullptr;

			return
				string.ok();
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

	bool
		RocksDbDatabaseManager
			::rollback_transaction()
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
						!transaction
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			auto string = transaction->Rollback();
			delete transaction;
			transaction = nullptr;

			return
				string.ok();
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

	bool
		RocksDbDatabaseManager
			::terminate()
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
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			return
				close();
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

	bool
		RocksDbDatabaseManager
			::clear()
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
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_2
					);
			}			

			close();

			rocksdb::Options options;
			rocksdb::Status status = rocksdb::DestroyDB(file_path, options);

			if (!status.ok())
			{
				return
					false;
			}			

			return
				open();
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

	bool
		RocksDbDatabaseManager
			::open()
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
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_2
					);
			}			

			if (!std::filesystem::exists(file_path))
            {
                std::filesystem::create_directories(file_path);
            }

            status = rocksdb::TransactionDB::Open(
                options, txn_db_options, file_path, &transaction_db);

            if (!status.ok())
            {                                
                return
					false;
            }

            object = transaction_db;

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

	bool
		RocksDbDatabaseManager
			::close()
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
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_3
					);
			}			

			if (object != nullptr)
            {
                for (auto& [name, handle] : column_families)
                {
                    if (handle != nullptr)
                    {
                        object->DestroyColumnFamilyHandle(handle);
                    }
                }
            }
            column_families.clear();

            if (transaction != nullptr)
            {
                delete transaction;
                transaction = nullptr;
            }
            if (transaction_db != nullptr)
            {
                delete transaction_db;
                transaction_db = nullptr;
            }
            object = nullptr;

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

	rocksdb::ColumnFamilyHandle*
		RocksDbDatabaseManager
			::get_cf_handle(
				const std::string&
					name
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
					nullptr;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

            auto iterator = column_families.find(name);
            if (iterator != column_families.end())
            {
                return iterator->second;
            }
            if (object != nullptr)
            {
                return object->DefaultColumnFamily();
            }

			return
				nullptr;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs<rocksdb::ColumnFamilyHandle*>(
					exception
				);
        }
	}
}
