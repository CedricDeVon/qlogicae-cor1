#pragma once

#include "framework.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{

}

/*

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
#include <oqs/oqs.h>
#include <sqlite3.h>
#include <rapidcsv.h>
#include <pugixml.hpp>
#include <nanobench.h>
#include <curl/curl.h>
#include <toml++/toml.h>
#include <xlnt/xlnt.hpp>
#include <cppcodec/base32_rfc4648.hpp>

#ifdef _M_X64

#include <onnxruntime/onnxruntime_cxx_api.h>
#include <folly/init/Init.h>
#include <folly/synchronization/MicroSpinLock.h>

#endif

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
 