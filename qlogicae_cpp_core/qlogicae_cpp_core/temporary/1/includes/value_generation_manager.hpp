#pragma once

#include "result.hpp"
#include "utilities.hpp"
#include "encoding_manager.hpp"
#include "instance_manager.hpp"
#include "value_generation_manager_types.hpp"

namespace QLogicaeCppCore
{    
    class ValueGenerationManager
    {
    public:
        ValueGenerationManager();

        ~ValueGenerationManager();

        ValueGenerationManager(
            const ValueGenerationManager& instance
        ) = delete;

        ValueGenerationManager(
            ValueGenerationManager&& instance
        ) noexcept = delete;

        ValueGenerationManager& operator = (
            ValueGenerationManager&& instance
        ) = delete;

        ValueGenerationManager& operator = (
            const ValueGenerationManager& instance
        ) = delete;

        void construct(
            Result<bool>& result
        );

        void destruct(
            Result<bool>& result
        );

        void generate_random_boolean(
            Result<bool>& result
        );

        void generate_random_boolean(
            Result<bool>& result,
            const double& true_probability
        );
        
        void generate_random_salt(
            Result<std::array<unsigned char, 16>>& result
        );

        void generate_random_bytes(
            Result<bool>& result,
            unsigned char* buffer,
            const size_t& size
        );

        void generate_random_string(
            Result<std::string>& result,
            const size_t& output_size,
            const std::string_view& character_set
        );

        void generate_random_base8(
            Result<std::string>& result,
            const size_t& output_size
        );
        
        void generate_random_base10(
            Result<std::string>& result,
            const size_t& output_size
        );

        void generate_random_base16(
            Result<std::string>& result,
            const size_t& output_size
        );

        void generate_random_base32(
            Result<std::string>& result,
            const size_t& output_size
        );

        void generate_random_base64(
            Result<std::string>& result,
            const size_t& output_size
        );

        void generate_random_uuid4(
            Result<std::string>& result
        );

        void generate_random_rgb(
            Result<std::string>& result
        );

        void generate_random_rgba(
            Result<std::string>& result
        );

        template <typename Type>
        void generate_random_ranged_value(
            Result<Type>& result,
            const Type& minimum,
            const Type& maximum
        );

        static thread_local std::mt19937 _mt19937_generator;

        static thread_local uuids::uuid_random_generator _uuid_generator;
    };

    template <typename Type>
    void ValueGenerationManager::generate_random_ranged_value(
        Result<Type>& result,
        const Type& minimum,
        const Type& maximum
    )
    {
        if constexpr (std::is_same_v<Type, bool>)
        {
            std::uniform_int_distribution<int> dist(0, 1);
            bool value = dist(_mt19937_generator) != 0;
            result.set_to_good_status_with_value(value);
            return;
        }

        if constexpr (std::is_enum_v<Type>)
        {
            using Underlying = typename std::underlying_type_t<Type>;
            std::uniform_int_distribution<Underlying> dist(
                static_cast<Underlying>(minimum),
                static_cast<Underlying>(maximum)
            );
            Type value = static_cast<Type>(dist(_mt19937_generator));
            result.set_to_good_status_with_value(value);
            return;
        }

        if constexpr (std::is_arithmetic_v<Type>)
        {
            if (minimum > maximum)
            {
                result.set_to_bad_status_without_value();
                return;
            }

            if constexpr (std::is_integral_v<Type> && std::is_unsigned_v<Type> &&
                sizeof(Type) > sizeof(uint64_t))
            {
                std::uniform_int_distribution<uint64_t> dist(
                    static_cast<uint64_t>(minimum),
                    static_cast<uint64_t>(maximum)
                );
                Type value = static_cast<Type>(dist(_mt19937_generator));
                result.set_to_good_status_with_value(value);
            }
            else if constexpr (std::is_integral_v<Type>)
            {
                std::uniform_int_distribution<Type> dist(minimum, maximum);
                Type value = dist(_mt19937_generator);
                result.set_to_good_status_with_value(value);
            }
            else
            {
                std::uniform_real_distribution<Type> dist(minimum, maximum);
                Type value = dist(_mt19937_generator);
                result.set_to_good_status_with_value(value);
            }

            return;
        }

        if constexpr (is_duration_v<Type>)
        {
            using Rep = typename Type::rep;

            if (minimum.count() > maximum.count())
            {
                result.set_to_bad_status_without_value();
                return;
            }

            Type value;
            if constexpr (std::is_integral_v<Rep> && std::is_unsigned_v<Rep> &&
                sizeof(Rep) > sizeof(uint64_t))
            {
                std::uniform_int_distribution<uint64_t> dist(
                    static_cast<uint64_t>(minimum.count()),
                    static_cast<uint64_t>(maximum.count())
                );
                value = Type(dist(_mt19937_generator));
            }
            else if constexpr (std::is_integral_v<Rep>)
            {
                std::uniform_int_distribution<Rep> dist(minimum.count(), maximum.count());
                value = Type(dist(_mt19937_generator));
            }
            else
            {
                std::uniform_real_distribution<Rep> dist(minimum.count(), maximum.count());
                value = Type(dist(_mt19937_generator));
            }

            result.set_to_good_status_with_value(value);
            return;
        }

        if constexpr (is_time_point_v<Type>)
        {
            using Duration = typename Type::duration;
            using Rep = typename Duration::rep;

            auto min_count = minimum.time_since_epoch().count();
            auto max_count = maximum.time_since_epoch().count();

            if (min_count > max_count)
            {
                result.set_to_bad_status_without_value();
                return;
            }

            Duration random_duration;
            if constexpr (std::is_integral_v<Rep> && std::is_unsigned_v<Rep> &&
                sizeof(Rep) > sizeof(uint64_t))
            {
                std::uniform_int_distribution<uint64_t> dist(
                    static_cast<uint64_t>(min_count),
                    static_cast<uint64_t>(max_count)
                );
                random_duration = Duration(dist(_mt19937_generator));
            }
            else if constexpr (std::is_integral_v<Rep>)
            {
                std::uniform_int_distribution<Rep> dist(min_count, max_count);
                random_duration = Duration(dist(_mt19937_generator));
            }
            else
            {
                std::uniform_real_distribution<Rep> dist(min_count, max_count);
                random_duration = Duration(dist(_mt19937_generator));
            }

            Type value(random_duration);
            result.set_to_good_status_with_value(value);
            return;
        }

        result.set_to_bad_status_without_value();
    }    

    inline static ValueGenerationManager& VALUE_GENERATION_MANAGER =
        INSTANCE_MANAGER.get_instance<ValueGenerationManager>();
}

