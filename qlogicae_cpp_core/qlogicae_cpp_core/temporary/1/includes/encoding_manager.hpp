#pragma once

#include "result.hpp"
#include "instance_manager.hpp"

namespace QLogicaeCppCore
{
    class EncodingManager
    {
    public:
        EncodingManager();

        ~EncodingManager();

        EncodingManager(
            const EncodingManager& instance
        ) = delete;

        EncodingManager(
            EncodingManager&& instance
        ) noexcept = delete;

        EncodingManager& operator = (
            EncodingManager&& instance
        ) = delete;

        EncodingManager& operator = (
            const EncodingManager& instance
        ) = delete;

        void construct(
            Result<bool>& result
        );

        void destruct(
            Result<bool>& result
        );

        void from_utf8_to_hex(
            Result<std::string>& result,
            const std::string_view& text
        );

        void from_hex_to_utf8(
            Result<std::string>& result,
            const std::string_view& text
        );

        void from_hex_to_base64(
            Result<std::string>& result,
            const std::string_view& text
        );

        void from_base64_to_hex(
            Result<std::string>& result,
            const std::string_view& text
        );

        void from_utf8_to_utf16(
            Result<std::wstring>& result,
            const std::string_view& text
        );

        void from_utf16_to_utf8(
            Result<std::string>& result,
            const std::wstring_view& text
        );

        void from_base64_to_utf8(
            Result<std::string>& result,
            const std::string_view& text
        );

        void from_utf8_to_base64(
            Result<std::string>& result,
            const std::string_view& text
        );

        void from_bytes_to_hex(
            Result<std::string>& result,
            const unsigned char* bytes,
            const size_t& length
        );

        void from_hex_to_bytes(
            Result<std::vector<unsigned char>>& result,
            const std::string_view& text
        );

        void from_bytes_to_base64(
            Result<std::string>& result,
            const unsigned char* bytes,
            const size_t& length
        );

        void from_base64_to_bytes(
            Result<std::vector<unsigned char>>& result,
            const std::string_view& text
        );

        void _to_hex(
            Result<std::string>& result,
            const std::string_view& text
        );

        void _to_base64(
            Result<std::string>& result,
            const std::string_view& text
        );    
    };

    inline static EncodingManager& ENCODING_MANAGER =
        INSTANCE_MANAGER.get_instance<EncodingManager>();
}
