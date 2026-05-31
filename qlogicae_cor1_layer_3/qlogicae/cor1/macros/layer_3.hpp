#pragma once

#include "qlogicae/cor1/macros/layer_2.hpp"

#include "qlogicae/cor1/includes/file_entity.hpp"
#include "qlogicae/cor1/includes/results_status.hpp"
#include "qlogicae/cor1/includes/regular_key_delete_handler.hpp"
#include "qlogicae/cor1/includes/value_enum_key_delete_handler.hpp"

#include "qlogicae/cor1/includes/time_manager.hpp"
#include "qlogicae/cor1/includes/asynchronous_batch_manager.hpp"
#include "qlogicae/cor1/includes/asynchronous_manager.hpp"
#include "qlogicae/cor1/includes/character_domain_manager.hpp"
#include "qlogicae/cor1/includes/configuration_manager.hpp"
#include "qlogicae/cor1/includes/console_io_manager.hpp"
#include "qlogicae/cor1/includes/curl_package_manager.hpp"
#include "qlogicae/cor1/includes/entity_activation_manager.hpp"
#include "qlogicae/cor1/includes/file_system_alias_entity_path_manager.hpp"
#include "qlogicae/cor1/includes/file_system_event_listener_manager.hpp"
#include "qlogicae/cor1/includes/file_system_event_listener_manager_options.hpp"
#include "qlogicae/cor1/includes/file_system_manager.hpp"
#include "qlogicae/cor1/includes/mutex_manager.hpp"
#include "qlogicae/cor1/includes/random_character_generation_manager.hpp"
#include "qlogicae/cor1/includes/random_enum_generation_manager.hpp"
#include "qlogicae/cor1/includes/random_number_generation_manager.hpp"
#include "qlogicae/cor1/includes/random_seed_generation_manager.hpp"
#include "qlogicae/cor1/includes/random_string_generation_manager.hpp"
#include "qlogicae/cor1/includes/random_value_generation_manager.hpp"
#include "qlogicae/cor1/includes/regular_expression_manager.hpp"
#include "qlogicae/cor1/includes/runtime_execution_manager.hpp"
#include "qlogicae/cor1/includes/sodium_package_manager.hpp"
#include "qlogicae/cor1/includes/text_case_manager.hpp"
#include "qlogicae/cor1/includes/text_encoding_manager.hpp"
#include "qlogicae/cor1/includes/text_error_manager.hpp"
#include "qlogicae/cor1/includes/text_key_path_manager.hpp"
#include "qlogicae/cor1/includes/text_manager.hpp"
#include "qlogicae/cor1/includes/text_placeholder_manager.hpp"
#include "qlogicae/cor1/includes/validation_manager.hpp"
#include "qlogicae/cor1/includes/value_extractor_manager.hpp"



#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			BoostVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__BoostVcpkgImports__IS_COMPILATION_ENABLED 1

	#include <boost/uuid/uuid.hpp> 
	#include <boost/uuid/uuid_io.hpp>  
	#include <boost/uuid/uuid_generators.hpp> 
	#include <boost/uuid/string_generator.hpp>

#else
#endif

#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			RapidCsvVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__RapidCsvVcpkgImports__IS_COMPILATION_ENABLED 1

	#include <rapidcsv.h>

#else
#endif

#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			XlntVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__XlntVcpkgImports__IS_COMPILATION_ENABLED 1

	#include <xlnt/xlnt.hpp> 

#else
#endif

#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			LibOqsVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__LibOqsVcpkgImports__IS_COMPILATION_ENABLED 1

	#ifndef ORT_DISABLE_SCHEMA_VALIDATION
		#define ORT_DISABLE_SCHEMA_VALIDATION 1
	#endif

	#include <oqs/oqs.h>

#else
#endif

#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			JwtCppVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__JwtCppVcpkgImports__IS_COMPILATION_ENABLED 1

	#ifdef _MSC_VER
		#pragma warning(push)
		#pragma warning(disable : 4244 4267)
	#endif

		#include <jwt-cpp/jwt.h>

	#ifdef _MSC_VER
		#pragma warning(pop)
	#endif

#else
#endif

#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			OnnxRuntimeVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__OnnxRuntimeVcpkgImports__IS_COMPILATION_ENABLED 1

	#ifdef _M_X64
		#include <onnxruntime/onnxruntime_cxx_api.h> 

	#endif
#else
#endif

#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			RocksDbVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__RocksDbVcpkgImports__IS_COMPILATION_ENABLED 1

	#include <rocksdb/db.h> 
	#include <rocksdb/table.h>  
	#include <rocksdb/filter_policy.h> 
	#include <rocksdb/utilities/checkpoint.h> 
	#include <rocksdb/utilities/backup_engine.h> 
	#include <rocksdb/utilities/transaction_db.h> 

#else
#endif

#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			NanobenchVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__NanobenchVcpkgImports__IS_COMPILATION_ENABLED 1

	#include <nanobench.h>

#else
#endif

#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			Sqlite3VcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__Sqlite3VcpkgImports__IS_COMPILATION_ENABLED 1

	#include <sqlite3.h>

#else
#endif

#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			TomlPlusPlusVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__TomlPlusPlusVcpkgImports__IS_COMPILATION_ENABLED 1

	#include <toml++/toml.h> 

#else
#endif

#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			PugixmlVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__PugixmlVcpkgImports__IS_COMPILATION_ENABLED 1

	#include <pugixml.hpp> 

#else
#endif

#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			Argon2VcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__Argon2VcpkgImports__IS_COMPILATION_ENABLED 1

	#include <argon2.h> 

#else
#endif

#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			RapidJsonVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__RapidJsonVcpkgImports__IS_COMPILATION_ENABLED 1

	#include <rapidjson/writer.h> 
	#include <rapidjson/pointer.h> 

#else
#endif

#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			YamlCppVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__YamlCppVcpkgImports__IS_COMPILATION_ENABLED 1

	#pragma warning(push)
	#pragma warning(disable : 4244 4251 4275)

	#include <yaml-cpp/yaml.h>

	#pragma warning(pop)

#else
#endif



#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			StdImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__StdImports__IS_COMPILATION_ENABLED 1

	#include <regex>
	#include <windows.h>
	#include <shellapi.h>

#else
#endif
