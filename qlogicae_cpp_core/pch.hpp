#pragma once

#include "framework.hpp"

#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>

#include <nanobench.h>

#include <curl/curl.h>

#include <sodium.h>

#include <argon2.h>

#include <fast_io.h>
#include <fast_io_device.h>
#include <fast_io_legacy.h>

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

#include <absl/time/time.h>
#include <absl/time/clock.h>
#include <absl/strings/ascii.h>
#include <absl/strings/str_cat.h>
#include <absl/strings/str_split.h>
#include <absl/strings/str_replace.h>

#include <folly/init/Init.h>
#include <folly/synchronization/MicroSpinLock.h>

#include <cppcodec/base32_rfc4648.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4244)
#endif

#include <jwt-cpp/jwt.h>

#ifdef _MSC_VER
#pragma warning(pop)
#endif

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


namespace QLogicaeCppCore
{

}
