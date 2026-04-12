#pragma once

#include "qlogicae_cpp_core/macros/all.hpp"

#include "framework.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4244)
#endif

#include <jwt-cpp/jwt.h> // 2

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include <pcre2.h> // 2
#include <sodium.h> // 2
#include <argon2.h> // 2
#include <oqs/oqs.h> // 2
#include <sqlite3.h> // 2
#include <rapidcsv.h> // 2
#include <pugixml.hpp> // 2
#include <nanobench.h> // 2
#include <curl/curl.h> // 2
#include <toml++/toml.h> // 2
#include <xlnt/xlnt.hpp> // 2
#include <cppcodec/base32_rfc4648.hpp> // 2

#ifdef _M_X64

#include <onnxruntime/onnxruntime_cxx_api.h> // 1
#include <folly/init/Init.h> // 1
#include <folly/synchronization/MicroSpinLock.h> // 1

#endif

#include <fast_io.h> // 2
#include <fast_io_device.h> // 2
#include <fast_io_legacy.h> // 2

#include <rapidjson/writer.h> // 2
#include <rapidjson/pointer.h> // 2
#include <rapidjson/document.h> // 2
#include <rapidjson/allocators.h> // 2
#include <rapidjson/prettywriter.h> // 2
#include <rapidjson/stringbuffer.h> // 2
#include <rapidjson/ostreamwrapper.h> // 2

#include <absl/time/time.h> // 2
#include <absl/time/clock.h> // 2
#include <absl/strings/ascii.h> // 2
#include <absl/strings/str_cat.h> // 2
#include <absl/strings/str_join.h> // 2
#include <absl/strings/str_split.h> // 2
#include <absl/strings/str_replace.h> // 2

#include <boost/asio.hpp> // 2
#include <boost/locale.hpp> // 2
#include <boost/uuid/uuid.hpp> // 2
#include <boost/uuid/uuid_io.hpp> // 2
#include <boost/thread/mutex.hpp> // 2
#include <boost/thread/locks.hpp> // 2
#include <boost/thread/mutex.hpp> // 2
#include <boost/locale/boundary.hpp> // 2
#include <boost/thread/shared_mutex.hpp> // 2
#include <boost/uuid/uuid_generators.hpp> // 2
#include <boost/uuid/string_generator.hpp> // 2
#include <boost/thread/recursive_mutex.hpp> // 2

#include <rocksdb/db.h> // 2
#include <rocksdb/slice.h> // 2
#include <rocksdb/table.h> // 2
#include <rocksdb/options.h> // 2
#include <rocksdb/iterator.h> // 2
#include <rocksdb/listener.h> // 2
#include <rocksdb/convenience.h> // 2
#include <rocksdb/write_batch.h> // 2
#include <rocksdb/filter_policy.h> // 2
#include <rocksdb/compaction_filter.h> // 2
#include <rocksdb/utilities/checkpoint.h> // 2
#include <rocksdb/utilities/backup_engine.h> // 2
#include <rocksdb/utilities/transaction_db.h> // 2

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

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{

}

/*



relative_private_qlogicae_folder_path =
	".qlogicae";
		
relative_public_qlogicae_folder_path =
	"qlogicae";
		
relative_application_name_folder_path =
	"qlogicae";
		
relative_application_version_name_folder_path =
	"v1.0.0";
		
relative_application_environment_name_folder_path =
	"development";
		
relative_log_folder_path =
	"log";
		
relative_log_date_folder_path =
	"date";
		
relative_log_level_folder_path =
	"level";
		
relative_all_log_file_path =
	"all.log";
		
relative_info_log_file_path =
	"info.log";
		
relative_debug_log_file_path =
	"debug.log";
		
relative_warning_log_file_path =
	"warning.log";
		
relative_success_log_file_path =
	"success.log";
		
relative_critical_log_file_path =
	"critical.log";
		
relative_error_log_file_path =
	"error.log";
		
relative_cache_folder_path =
	"cache";
		
relative_main_folder_path =
	"main";
		
relative_assets_folder_path =
	"assets";
		
relative_documentation_folder_path =
	"documentation";
		
relative_environment_json_file_path =
	"environment.json";
		
relative_license_txt_file_path =
	"LICENSE.txt";
		
relative_application_folder_path =
	"application";
		
relative_application_icon_file_path =
	"application.ico";
		
relative_qlogicae_json_file_path =
	"qlogicae.json";
		
relative_configurations_folder_path =
	"configurations";
		
relative_development_folder_path =
	"development";
		
relative_debug_folder_path =
	"debug";
		
relative_test_folder_path =
	"test";
		
relative_release_folder_path =
	"release";
		


std::string
	relative_windows_registry_software_qlogicae_folder_path;

relative_windows_registry_software_qlogicae_folder_path =
	"Software\\QLogicae";

std::string
	relative_private_qlogicae_folder_path;

std::string
	relative_public_qlogicae_folder_path;

std::string
	relative_application_name_folder_path;

std::string
	relative_application_version_name_folder_path;

std::string
	relative_application_environment_name_folder_path;

std::string
	relative_log_folder_path;

std::string
	relative_log_date_folder_path;

std::string
	relative_log_level_folder_path;

std::string
	relative_all_log_file_path;

std::string
	relative_info_log_file_path;

std::string
	relative_debug_log_file_path;

std::string
	relative_warning_log_file_path;

std::string
	relative_success_log_file_path;

std::string
	relative_critical_log_file_path;

std::string
	relative_error_log_file_path;

std::string
	relative_cache_folder_path;

std::string
	relative_main_folder_path;

std::string
	relative_assets_folder_path;

std::string
	relative_documentation_folder_path;

std::string
	relative_environment_json_file_path;

std::string
	relative_license_txt_file_path;

std::string
	relative_application_folder_path;

std::string
	relative_application_icon_file_path;

std::string
	relative_qlogicae_json_file_path;

std::string
	relative_configurations_folder_path;

std::string
	relative_development_folder_path;

std::string
	relative_debug_folder_path;

std::string
	relative_test_folder_path;

std::string
	relative_release_folder_path;



*/
 