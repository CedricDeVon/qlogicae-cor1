#include "pch.hpp"

#include "../includes/rocksdb_database_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	RocksDbDatabaseManagerConfigurations
		::RocksDbDatabaseManagerConfigurations() :
			AbstractConfigurations<RocksDbDatabaseManagerConfigurations>()
	{
		file_path =
			"data.db";

		is_feature_thread_safety_handling_enabled =
			true;

		create_if_missing =
			true;

		max_open_files =
			-1;

		use_fsync =
			false;

		use_direct_reads =
			true;

		use_direct_io_for_flush_and_compaction =
			true;

		max_background_flushes =
			1;

		base_max_background_jobs =
			4;

		compaction_style =
			rocksdb::kCompactionStyleLevel;

		level0_file_num_compaction_trigger =
			10;

		level0_slowdown_writes_trigger =
			20;

		level0_stop_writes_trigger =
			40;

		write_buffer_size =
			128 * 1024 * 1024;

		base_write_buffer_size =
			64 * 1024 * 1024;

		max_write_buffer_number =
			6;

		min_write_buffer_number_to_merge =
			2;

		target_file_size_base =
			64 * 1024 * 1024;

		max_bytes_for_level_base =
			512 * 1024 * 1024;

		bytes_per_sync =
			1 << 20;

		base_block_cache_size =
			64 * 1024 * 1024;

		compression =
			rocksdb::kNoCompression;

		write_sync =
			false;

		write_disable_wal =
			true;

		no_block_cache =
			true;

		block_restart_interval =
			4;

		block_size =
			4 * 1024;

		background_threads =
			4;

		new_bloom_filter_policy =
			10;
	}

	RocksDbDatabaseManagerConfigurations
		RocksDbDatabaseManagerConfigurations
			::initial_configurations;

	RocksDbDatabaseManagerConfigurations
		RocksDbDatabaseManagerConfigurations
			::default_configurations =
				RocksDbDatabaseManagerConfigurations
					::initial_configurations;
}
