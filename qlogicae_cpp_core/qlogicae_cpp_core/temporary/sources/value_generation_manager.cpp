#include "pch.hpp"

#include "../includes/value_generation_manager.hpp"

namespace QLogicaeCppCore
{
    thread_local std::mt19937 ValueGenerationManager::_mt19937_generator
    {
        std::random_device{}()
    };

    thread_local uuids::uuid_random_generator ValueGenerationManager::_uuid_generator
    {
        ValueGenerationManager::_mt19937_generator
    };

    ValueGenerationManager::ValueGenerationManager()
    {
        Result<bool> result;

        construct(result);
    }

    ValueGenerationManager::~ValueGenerationManager()
    {
        Result<bool> result;

        destruct(result);
    }

    void ValueGenerationManager::construct(
        Result<bool>& result
    )
    {
        const int status = sodium_init();

        if (status < 0)
        {            
            result.set_to_bad_status_with_value(
                false
            );
        }

        result.set_to_good_status_with_value(
            true
        );
    }

    void ValueGenerationManager::destruct(
        Result<bool>& result
    )
    {
        result.set_to_good_status_with_value(
            true
        );
    }

    void ValueGenerationManager::generate_random_boolean(
        Result<bool>& result
    )
    {
        generate_random_boolean(
            result,
            1
        );
    }

    void ValueGenerationManager::generate_random_boolean(
        Result<bool>& result,
        const double& true_probability
    )
    {
        if (true_probability < 1)
        {
            return result.set_to_bad_status_with_value(
                false
            );
        }

        result.set_to_good_status_with_value(
            std::bernoulli_distribution(
                true_probability
            )(
                _mt19937_generator
                )
        );
    }

    void ValueGenerationManager::generate_random_salt(
        Result<std::array<unsigned char, 16>>& result
    )
    {
        std::array<unsigned char, 16> salt{};

        randombytes_buf(
            salt.data(),
            salt.size()
        );

        result.set_to_good_status_with_value(
            salt
        );
    }

    void ValueGenerationManager::generate_random_bytes(
        Result<bool>& result,
        unsigned char* buffer,
        const size_t& size
    )
    {
        if (buffer == nullptr && size > 0)
        {
            return result.set_to_bad_status_with_value(
                false
            );
        }

        randombytes_buf(
            buffer,
            size
        );

        result.set_to_good_status_with_value(
            true
        );
    }

    void ValueGenerationManager::generate_random_string(
        Result<std::string>& result,
        const size_t& length,
        const std::string_view& character_set
    )
    {
        if (character_set.empty() || length < 1)
        {
            return result.set_to_bad_status_with_value(
                ""
            );
        }

        std::size_t index;
        std::string content;
        std::uniform_int_distribution<std::size_t> distribution(
            0, character_set.size() - 1
        );

        content.reserve(length);

        for (index = 0; index < length; ++index)
        {
            content += character_set
                [
                    distribution(
                        _mt19937_generator
                    )
                ];
        }

        result.set_to_good_status_with_value(
            content
        );
    }

    void ValueGenerationManager::generate_random_base8(
        Result<std::string>& result,
        const size_t& length
    )
    {
        if (length < 1)
        {
            return result.set_to_bad_status_with_value(
                ""
            );
        }

        generate_random_string(
            result,
            length,
            "01234567"
        );
    }

    void ValueGenerationManager::generate_random_base10(
        Result<std::string>& result,
        const size_t& length
    )
    {
        if (length < 1)
        {
            return result.set_to_bad_status_with_value(
                ""
            );
        }

        generate_random_string(
            result,
            length,
            "0123456789"
        );
    }

    void ValueGenerationManager::generate_random_base16(
        Result<std::string>& result,
        const size_t& length
    )
    {
        if (length < 1)
        {
            return result.set_to_bad_status_with_value(
                ""
            );
        }

        generate_random_string(
            result,
            length,
            "0123456789abcdef"
        );
    }

    void ValueGenerationManager::generate_random_base32(
        Result<std::string>& result,
        const size_t& length
    )
    {
        if (length < 1)
        {
            return result.set_to_bad_status_with_value(
                ""
            );
        }
        generate_random_string(
            result,
            length,
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567"
        );
    }

    void ValueGenerationManager::generate_random_base64(
        Result<std::string>& result,
        const size_t& length
    )
    {
        if (length < 1)
        {
            return result.set_to_bad_status_with_value(
                ""
            );
        }

        generate_random_string(
            result,
            length,
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"
        );

        ENCODING_MANAGER.from_utf8_to_base64(
            result,
            result.get_value()
        );
    }

    void ValueGenerationManager::generate_random_uuid4(
        Result<std::string>& result
    )
    {        
        result.set_to_good_status_with_value(
            uuids::to_string(_uuid_generator())
        );
    }

    void ValueGenerationManager::generate_random_rgb(
        Result<std::string>& result
    )
    {
        std::string content;

        generate_random_base16(
            result,
            6
        );

        fmt::format_to(
            std::back_inserter(content),
            "#{}",
            result.get_value()
        );

        result.set_to_good_status_with_value(
            content
        );
    }

    void ValueGenerationManager::generate_random_rgba(
        Result<std::string>& result
    )
    {
        std::string content;

        generate_random_base16(
            result,
            8
        );

        fmt::format_to(
            std::back_inserter(content),
            "#{}",
            result.get_value()
        );

        result.set_to_good_status_with_value(
            content
        );
    }
}

