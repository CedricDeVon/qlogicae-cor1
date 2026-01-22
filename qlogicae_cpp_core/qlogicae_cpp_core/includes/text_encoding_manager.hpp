#pragma once

#include "text_encoding.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_encoding_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    class
		TextEncodingManager :
			public AbstractClass<TextEncodingManagerConfigurations>
    {
    public:        
		static const char
			decode_base_16_table[];

		static const int8_t
			decode_base_32_table[];

		static const char
			encode_base_32_table[];

		static const int8_t
			decode_base_64_table[];

		static const char
			encode_base_64_table[];

        static TextEncodingManager&
            singleton;

		TextEncodingManager();

		~TextEncodingManager();

		bool
			construct();

		bool
			destruct();

		std::string
			convert_text(
				const std::string&
					text,
				const TextEncoding&
					original_type,
				const TextEncoding&
					target_type
			);

		std::string
			convert_text(
				const std::string&
					text
			);

		std::string
			decode_base16(
				const std::string&
					input
			);

		std::string
			encode_base16(
				const std::string&
					input
			);

		std::string
			decode_base32(
				const std::string&
					input
			);

		std::string
			encode_base32(
				const std::string&
					input
			);

		std::string
			decode_base64(
				const std::string&
					input
			);

		std::string
			encode_base64(
				const std::string&
					input
			);
    };    
}
