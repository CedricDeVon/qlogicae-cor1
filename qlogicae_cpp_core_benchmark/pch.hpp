#pragma once

#include <gtest/gtest.h>

#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>



#include <nanobench.h>

#include <io.h>

#include <fast_io.h>
#include <fast_io_device.h>

#include <absl/synchronization/mutex.h>

#include <folly/File.h>
#include <folly/Conv.h>
#include <folly/Range.h>
#include <folly/Format.h>
#include <folly/init/Init.h>
#include <folly/portability/Unistd.h>
#include <folly/portability/SysTypes.h>
#include <folly/synchronization/MicroSpinLock.h>

#include <boost/asio.hpp>
#include <boost/filesystem.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/iostreams/device/file.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <boost/iostreams/device/mapped_file.hpp>

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

#include <windows.h>
#include <winnt.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include "qlogicae_cpp_core/includes/all.hpp"

namespace QLogicaeCppCoreBenchmark
{

}
