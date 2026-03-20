#pragma once

#include "framework.hpp"

#include <gtest/gtest.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4244)
#endif

#include <jwt-cpp/jwt.h>

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include <pcre2.h>
#include <sodium.h>
#include <argon2.h>
#include <sqlite3.h>
#include <rapidcsv.h>
#include <pugixml.hpp>
#include <nanobench.h>
#include <curl/curl.h>
#include <toml++/toml.h>
#include <xlnt/xlnt.hpp>
#include <cppcodec/base32_rfc4648.hpp>
#include <onnxruntime/onnxruntime_cxx_api.h>

#include <folly/init/Init.h>
#include <folly/synchronization/MicroSpinLock.h>

#include <fast_io.h>
#include <fast_io_device.h>
#include <fast_io_legacy.h>

#include <rapidjson/writer.h>
#include <rapidjson/pointer.h>
#include <rapidjson/document.h>
#include <rapidjson/allocators.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/ostreamwrapper.h>

#include <absl/time/time.h>
#include <absl/time/clock.h>
#include <absl/strings/ascii.h>
#include <absl/strings/str_cat.h>
#include <absl/strings/str_join.h>
#include <absl/strings/str_split.h>
#include <absl/strings/str_replace.h>

#include <boost/asio.hpp>
#include <boost/locale.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/locale/boundary.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/thread/recursive_mutex.hpp>

#include <rocksdb/db.h>
#include <rocksdb/slice.h>
#include <rocksdb/table.h>
#include <rocksdb/options.h>
#include <rocksdb/iterator.h>
#include <rocksdb/listener.h>
#include <rocksdb/convenience.h>
#include <rocksdb/write_batch.h>
#include <rocksdb/filter_policy.h>
#include <rocksdb/compaction_filter.h>
#include <rocksdb/utilities/checkpoint.h>
#include <rocksdb/utilities/backup_engine.h>
#include <rocksdb/utilities/transaction_db.h>

#include <any>
#include <compare>
#include <variant>
#include <optional>
#include <typeinfo>
#include <typeindex>
#include <type_traits>
#include <source_location>

#include <bit>
#include <limits>
#include <bitset>
#include <cstddef>
#include <cstdint>
#include <climits>

#include <regex>
#include <string>
#include <format>
#include <cctype>
#include <cwctype>
#include <charconv>
#include <string_view>

#include <set>
#include <map>
#include <list>
#include <span>
#include <array>
#include <deque>
#include <tuple>
#include <stack>
#include <queue>
#include <vector>
#include <ranges>
#include <iterator>
#include <unordered_set>
#include <unordered_map>

#include <new>
#include <memory>
#include <memory_resource>

#include <mutex>
#include <latch>
#include <thread>
#include <future>
#include <atomic>
#include <barrier>
#include <semaphore>
#include <stop_token>
#include <shared_mutex>
#include <condition_variable>

#include <ratio>
#include <chrono>
#include <random>
#include <numbers>

#include <fstream>
#include <filesystem>

#include <ios>
#include <cstdio>
#include <istream>
#include <ostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <iostream>

#include <cmath>
#include <cerrno>
#include <cassert>
#include <complex>
#include <csignal>
#include <valarray>
#include <stdexcept>

#include <locale>
#include <execution>
#include <algorithm>
#include <functional>

#include <version>

#include <concepts>
#include <coroutine>

#include <cfenv>
#include <cfloat>

#include <ctime>
#include <cstdarg>
#include <csetjmp>
#include <cstring>

#include <codecvt>
#include <shlobj.h>

#include <winnt.h>
#include <aclapi.h>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <shellapi.h>

#include <immintrin.h>

#include "qlogicae_cpp_core/includes/abstract_class.hpp"
#include "qlogicae_cpp_core/includes/aes256_cipher_cryptography_manager.hpp"
#include "qlogicae_cpp_core/includes/argon2id_hash_cryptography_manager.hpp"
#include "qlogicae_cpp_core/includes/asynchronous_manager.hpp"
#include "qlogicae_cpp_core/includes/asynchronous_batch_manager.hpp"
#include "qlogicae_cpp_core/includes/bcrypt_hash_cryptography_manager.hpp"
#include "qlogicae_cpp_core/includes/character_domain_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/character_domain_manager.hpp"
#include "qlogicae_cpp_core/includes/configuration_manager.hpp"
#include "qlogicae_cpp_core/includes/console_io_manager.hpp"
#include "qlogicae_cpp_core/includes/console_log_manager.hpp"
#include "qlogicae_cpp_core/includes/enum_manager.hpp"
#include "qlogicae_cpp_core/includes/error_manager.hpp"
#include "qlogicae_cpp_core/includes/edsca_signature_cryptography_manager.hpp"
#include "qlogicae_cpp_core/includes/excel_file_io_manager.hpp"
#include "qlogicae_cpp_core/includes/gmail_api_manager.hpp"
#include "qlogicae_cpp_core/includes/curl_package_manager.hpp"
#include "qlogicae_cpp_core/includes/sodium_package_manager.hpp"
#include "qlogicae_cpp_core/includes/email_body_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/email_security_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/entity_activation_status_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/json_text_manager.hpp"
#include "qlogicae_cpp_core/includes/jsonwebtoken_cryptography_manager.hpp"
#include "qlogicae_cpp_core/includes/entity_activation_manager.hpp"
#include "qlogicae_cpp_core/includes/file_system_entity_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/file_log_manager.hpp"
#include "qlogicae_cpp_core/includes/function_wrapper.hpp"
#include "qlogicae_cpp_core/includes/json_file_io_manager.hpp"
#include "qlogicae_cpp_core/includes/interval_clock.hpp"
#include "qlogicae_cpp_core/includes/log_format_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/log_level_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/log_medium_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/log_output_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/mutex_manager.hpp"
#include "qlogicae_cpp_core/includes/network_ping_manager.hpp"
#include "qlogicae_cpp_core/includes/random_enum_generation_manager.hpp"
#include "qlogicae_cpp_core/includes/random_number_generation_manager.hpp"
#include "qlogicae_cpp_core/includes/random_seed_generation_manager.hpp"
#include "qlogicae_cpp_core/includes/random_character_generation_manager.hpp"
#include "qlogicae_cpp_core/includes/random_string_generation_manager.hpp"
#include "qlogicae_cpp_core/includes/random_value_generation_manager.hpp"
#include "qlogicae_cpp_core/includes/regular_expression_manager.hpp"
#include "qlogicae_cpp_core/includes/rest_api_manager.hpp"
#include "qlogicae_cpp_core/includes/results.hpp"
#include "qlogicae_cpp_core/includes/results_status_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/rocksdb_database_manager.hpp"
#include "qlogicae_cpp_core/includes/toml_file_io_manager.hpp"
#include "qlogicae_cpp_core/includes/runtime_execution_manager.hpp"
#include "qlogicae_cpp_core/includes/sha256_hash_cryptography_manager.hpp"
#include "qlogicae_cpp_core/includes/singleton_manager.hpp"
// #include "qlogicae_cpp_core/includes/sqlite_backend.hpp"
// #include "qlogicae_cpp_core/includes/sqlite_database_manager.hpp"
// #include "qlogicae_cpp_core/includes/sqlite_database_manager_configurations.hpp"
// #include "qlogicae_cpp_core/includes/sqlite_exception.hpp"
// #include "qlogicae_cpp_core/includes/sqlite_row.hpp"
// #include "qlogicae_cpp_core/includes/sqlite_statement.hpp"
// #include "qlogicae_cpp_core/includes/sqlite_statement_data.hpp"
// #include "qlogicae_cpp_core/includes/sqlite_transaction.hpp"
#include "qlogicae_cpp_core/includes/onnx_api_manager.hpp"
#include "qlogicae_cpp_core/includes/temperature_manager.hpp"
#include "qlogicae_cpp_core/includes/temperature_unit_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/text_case_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/text_case_manager.hpp"
#include "qlogicae_cpp_core/includes/text_encoding_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/text_encoding_manager.hpp"
#include "qlogicae_cpp_core/includes/text_error_manager.hpp"
#include "qlogicae_cpp_core/includes/text_log_manager.hpp"
#include "qlogicae_cpp_core/includes/text_key_path_manager.hpp"
#include "qlogicae_cpp_core/includes/text_file_io_manager.hpp"
#include "qlogicae_cpp_core/includes/text_manager.hpp"
#include "qlogicae_cpp_core/includes/text_placeholder_manager.hpp"
#include "qlogicae_cpp_core/includes/time_format_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/time_manager.hpp"
#include "qlogicae_cpp_core/includes/time_scale_unit_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/time_zone_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/timeout_clock.hpp"
#include "qlogicae_cpp_core/includes/uuid_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/uuid_manager.hpp"
#include "qlogicae_cpp_core/includes/validation_manager.hpp"
#include "qlogicae_cpp_core/includes/value_extractor_manager.hpp"
#include "qlogicae_cpp_core/includes/windows_environment_variable_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/windows_environment_variable_manager.hpp"
#include "qlogicae_cpp_core/includes/windows_registry_manager.hpp"
#include "qlogicae_cpp_core/includes/windows_registry_root_path_enum_manager.hpp"
#include "qlogicae_cpp_core/includes/windows_system_access_manager.hpp"
#include "qlogicae_cpp_core/includes/xchacha20_poly1305_cipher_cryptography_manager.hpp"
#include "qlogicae_cpp_core/includes/xml_file_io_manager.hpp"
#include "qlogicae_cpp_core/includes/binary_file_io_manager.hpp"
#include "qlogicae_cpp_core/includes/csv_file_io_manager.hpp"

namespace
	QLogicae::Cor::V1::Tests
{

}


