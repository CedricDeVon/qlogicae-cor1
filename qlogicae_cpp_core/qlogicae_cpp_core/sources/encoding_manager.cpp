#include "pch.hpp"

#include "../includes/encoding_manager.hpp"

namespace QLogicaeCppCore
{
    EncodingManager::EncodingManager()
    {
        Result<bool> result;

        construct(result);
    }

    EncodingManager::~EncodingManager()
    {
        Result<bool> result;

        destruct(result);
    }

    void EncodingManager::construct(
        Result<bool>& result
    )
    {
        if (sodium_init() < 0)
        {            
            throw std::runtime_error(
                "QLogicaeCppCore::EncodingManager::EncodingManager() - Sodium package is not initialized"
            );
        }

        result.set_to_good_status_with_value(
            true
        );
    }

    void EncodingManager::destruct(
        Result<bool>& result
    )
    {
        result.set_to_good_status_with_value(
            true
        );
    }

    void EncodingManager::from_bytes_to_base64(
        Result<std::string>& result,
        const unsigned char* text,
        const size_t& length
    )
    {
        std::string base64(sodium_base64_encoded_len(
            length,
            sodium_base64_VARIANT_ORIGINAL),
            '\0'
        );
        sodium_bin2base64(
            base64.data(),
            base64.size(),
            text,
            length,
            sodium_base64_VARIANT_ORIGINAL
        );

        base64.resize(strlen(base64.data()));

        result.set_to_good_status_with_value(
            base64
        );
    }

    void EncodingManager::from_base64_to_bytes(
        Result<std::vector<unsigned char>>& result,
        const std::string_view& text
    )
    {
        if (text.empty())
        {
            return result.set_to_bad_status_with_value(
                {}, "text is empty"
            );
        }

        std::vector<unsigned char> buffer(text.length());
        size_t actual_len = 0;

        if (sodium_base642bin(
            buffer.data(), buffer.size(),
            text.data(), text.length(),
            nullptr, &actual_len,
            nullptr, sodium_base64_VARIANT_ORIGINAL
        ) != 0)
        {
            return result.set_to_bad_status_with_value(
                {}, "encoding failed"
            );
        }

        buffer.resize(actual_len);

        result.set_to_good_status_with_value(buffer);
    }

    void EncodingManager::from_bytes_to_hex(
        Result<std::string>& result,
        const unsigned char* text,
        const size_t& length
    )
    {
        const char* hex_chars = "0123456789abcdef";
        std::string output;
        output.reserve(length * 2);

        size_t index = 0;
        for (index = 0; index < length; ++index)
        {
            unsigned char byte = text[index];
            output.push_back(hex_chars[(byte >> 4) & 0x0F]);
            output.push_back(hex_chars[byte & 0x0F]);
        }

        result.set_to_good_status_with_value(output);
    }

    void EncodingManager::from_hex_to_bytes(
        Result<std::vector<unsigned char>>& result,
        const std::string_view& text
    )
    {
        if (text.empty())
        {
            return result.set_to_bad_status_with_value(
                {}, "text is empty"
            );
        }

        unsigned int byte;
        std::string va = text.data();
        std::vector<unsigned char> bytes;
        bytes.reserve(text.length() / 2);
        size_t index = 0, text_length = text.length();
        for (index = 0; index < text_length; index += 2)
        {
            std::istringstream(va.substr(index, 2)) >> std::hex >> byte;
            bytes.push_back(static_cast<unsigned char>(byte));
        }

        result.set_to_good_status_with_value(bytes);
    }

    void EncodingManager::from_utf16_to_utf8(
        Result<std::string>& result,
        const std::wstring_view& text
    )
    {
        if (text.empty())
        {
            return result.set_to_bad_status_with_value(
                "", "text is empty"
            );
        }

        int size_needed = WideCharToMultiByte(
            CP_UTF8, 0,
            text.data(), -1,
            nullptr, 0,
            nullptr, nullptr
        );
        std::string data(size_needed, 0);
        WideCharToMultiByte(
            CP_UTF8, 0,
            text.data(), -1,
            &data[0], size_needed,
            nullptr, nullptr
        );
        data.pop_back();

        result.set_to_good_status_with_value(data);
    }

    void EncodingManager::from_utf8_to_utf16(
        Result<std::wstring>& result,
        const std::string_view& text
    )
    {
        if (text.empty())
        {
            return result.set_to_bad_status_with_value(
                L"", "text is empty"
            );
        }

        unsigned int size_needed = MultiByteToWideChar(
            CP_UTF8, 0,
            text.data(), -1,
            nullptr, 0
        );
        std::wstring data(size_needed, 0);
        MultiByteToWideChar(
            CP_UTF8, 0,
            text.data(), -1,
            &data[0], size_needed
        );
        data.pop_back();

        result.set_to_good_status_with_value(data);
    }

    void EncodingManager::from_utf8_to_hex(
        Result<std::string>& result,
        const std::string_view& text
    )
    {
        if (text.empty())
        {
            return result.set_to_bad_status_with_value(
                "", "text is empty"
            );
        }

        _to_hex(result, text);
    }

    void EncodingManager::from_utf8_to_base64(
        Result<std::string>& result,
        const std::string_view& text
    )
    {
        if (text.empty())
        {
            return result.set_to_bad_status_with_value(
                "", "text is empty"
            );
        }

        _to_base64(result, text);
    }

    void EncodingManager::from_hex_to_utf8(
        Result<std::string>& result,
        const std::string_view& text
    )
    {
        if (text.empty())
        {
            return result.set_to_bad_status_with_value(
                "", "text is empty"
            );
        }

        size_t bin_len = 0;
        std::vector<unsigned char> buffer(text.size() / 2, 0);

        if (sodium_hex2bin(
            buffer.data(), buffer.size(),
            text.data(), text.size(),
            nullptr, &bin_len, nullptr) != 0)
        {
            return result.set_to_bad_status_with_value(
                "", "encoding failed"
            );
        }

        result.set_to_good_status_with_value(
            std::string(reinterpret_cast<const char*>(
                buffer.data()), bin_len
            )
        );
    }

    void EncodingManager::from_hex_to_base64(
        Result<std::string>& result,
        const std::string_view& text
    )
    {
        if (text.empty())
        {
            return result.set_to_bad_status_with_value(
                "", "text is empty"
            );
        }

        from_hex_to_utf8(result, text);
        _to_base64(result, result.get_value());
        result.set_to_good_status_with_value(
            result.get_value()
        );
    }

    void EncodingManager::from_base64_to_utf8(
        Result<std::string>& result,
        const std::string_view& text
    )
    {
        if (text.empty())
        {
            return result.set_to_bad_status_with_value(
                "", "text is empty"
            );
        }

        size_t bin_len = 0;
        std::vector<unsigned char> buffer(text.size(), 0);

        if (sodium_base642bin(buffer.data(), buffer.size(),
            text.data(), text.size(),
            nullptr, &bin_len, nullptr,
            sodium_base64_VARIANT_ORIGINAL) != 0)
        {
            return result.set_to_bad_status_with_value(
                "", "encoding failed"
            );
        }

        result.set_to_good_status_with_value(
            std::string(reinterpret_cast<const char*>(
                buffer.data()), bin_len
            )
        );
    }

    void EncodingManager::from_base64_to_hex(
        Result<std::string>& result,
        const std::string_view& text
    )
    {
        if (text.empty())
        {
            return result.set_to_bad_status_with_value(
                "", "text is empty"
            );
        }

        Result<std::vector<unsigned char>> bytes_result;
        from_base64_to_bytes(bytes_result, text);

        bool is_status_safe_result;

        bytes_result.is_status_safe(
            is_status_safe_result
        );

        if (!is_status_safe_result)
        {
            return result.set_to_bad_status_with_value(
                "", bytes_result.get_message()
            );
        }

        Result<std::string> hex_result;
        from_bytes_to_hex(hex_result,
            bytes_result.get_value().data(),
            bytes_result.get_value().size());

        hex_result.is_status_safe(
            is_status_safe_result
        );

        if (!is_status_safe_result)
        {
            return result.set_to_bad_status_with_value(
                "", hex_result.get_message()
            );
        }

        result.set_to_good_status_with_value(
            hex_result.get_value()
        );
    }

    void EncodingManager::_to_hex(
        Result<std::string>& result,
        const std::string_view& text
    )
    {
        if (text.empty())
        {
            return result.set_to_bad_status_with_value(
                "", "text is empty"
            );
        }

        std::string output(text.size() * 3, '\0');

        sodium_bin2hex(output.data(), output.size(),
            reinterpret_cast<const unsigned char*>(
                text.data()),
            text.size());
        output.resize(std::strlen(output.c_str()));

        result.set_to_good_status_with_value(
            output
        );
    }

    void EncodingManager::_to_base64(
        Result<std::string>& result,
        const std::string_view& text
    )
    {
        if (text.empty())
        {
            return result.set_to_bad_status_with_value(
                "", "text is empty"
            );
        }

        std::string output(sodium_base64_encoded_len(
            text.size(),
            sodium_base64_VARIANT_ORIGINAL),
            '\0'
        );

        sodium_bin2base64(output.data(), output.size(),
            reinterpret_cast<const unsigned char*>(
                text.data()), text.size(),
            sodium_base64_VARIANT_ORIGINAL);
        output.resize(std::strlen(output.c_str()));

        result.set_to_good_status_with_value(
            output
        );
    }
}
