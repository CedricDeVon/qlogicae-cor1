#pragma once

namespace QLogicaeCppCore
{
    template <typename T>
    struct is_duration : std::false_type {};

    template <typename Rep, typename Period>
    struct is_duration<std::chrono::duration<Rep, Period>> : std::true_type {};

    template <typename T>
    inline constexpr bool is_duration_v = is_duration<T>::value;

    template <typename T>
    struct is_time_point : std::false_type {};

    template <typename Clock, typename Duration>
    struct is_time_point<std::chrono::time_point<Clock, Duration>> : std::true_type {};

    template <typename T>
    inline constexpr bool is_time_point_v = is_time_point<T>::value;
}

