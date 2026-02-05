#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		RocksDbDatabaseManagerConfigurations :
			AbstractConfigurations<RocksDbDatabaseManagerConfigurations>
    {
	public:
			bool
				create_if_missing =
					default_configurations
						.create_if_missing;

			int
				max_open_files =
					default_configurations
						.max_open_files;

			bool
				use_fsync =
					default_configurations
						.use_fsync;

			bool
				use_direct_reads =
					default_configurations
						.use_direct_reads;

			bool
				use_direct_io_for_flush_and_compaction =
					default_configurations
						.use_direct_io_for_flush_and_compaction;

			int
				max_background_flushes =
					default_configurations
						.max_background_flushes;

			int
				base_max_background_jobs =
					default_configurations
						.base_max_background_jobs;

			rocksdb::CompactionStyle
				compaction_style =
					default_configurations
						.compaction_style;

			int
				level0_file_num_compaction_trigger =
					default_configurations
						.level0_file_num_compaction_trigger;

			int
				level0_slowdown_writes_trigger =
					default_configurations
						.level0_slowdown_writes_trigger;

			int
				level0_stop_writes_trigger =
					default_configurations
						.level0_stop_writes_trigger;

			size_t
				write_buffer_size =
					default_configurations
						.write_buffer_size;

			size_t
				base_write_buffer_size =
					default_configurations
						.base_write_buffer_size;

			int
				max_write_buffer_number =
					default_configurations
						.max_write_buffer_number;

			int
				min_write_buffer_number_to_merge =
					default_configurations
						.min_write_buffer_number_to_merge;

			size_t
				target_file_size_base =
					default_configurations
						.target_file_size_base;

			size_t
				max_bytes_for_level_base =
					default_configurations
						.max_bytes_for_level_base;

			size_t
				bytes_per_sync =
					default_configurations
						.bytes_per_sync;

			size_t
				base_block_cache_size =
					default_configurations
						.base_block_cache_size;

			rocksdb::CompressionType
				compression =
					default_configurations
						.compression;

			bool
				write_sync =
					default_configurations
						.write_sync;

			bool
				write_disable_wal =
					default_configurations
						.write_disable_wal;

			bool
				no_block_cache =
					default_configurations
						.no_block_cache;

			int
				block_restart_interval =
					default_configurations
						.block_restart_interval;

			size_t
				block_size =
					default_configurations
						.block_size;

			size_t
				background_threads =
					default_configurations
						.background_threads;

			double
				new_bloom_filter_policy =
					default_configurations
						.new_bloom_filter_policy;

		static RocksDbDatabaseManagerConfigurations
			initial_configurations;

		static RocksDbDatabaseManagerConfigurations
			default_configurations;

		RocksDbDatabaseManagerConfigurations();
    };
}

