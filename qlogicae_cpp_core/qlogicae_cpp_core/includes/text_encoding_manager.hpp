#pragma once

#include "text_case.hpp"
#include "enum_manager.hpp"
#include "text_encoding.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_case_manager.hpp"
#include "text_encoding_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    class
		TextEncodingManager :
			public AbstractClass<TextEncodingManagerConfigurations>
    {
    public:
		boost::mutex
			feature_handling_mutex_2;

        static TextEncodingManager&
            singleton;

		TextEncodingManager();

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

		std::string
			convert_enum_to_string(
				const TextEncoding&
					value,
				const TextCase&
					text_case
			);

		std::string
			convert_enum_to_string(
				const TextEncoding&
					value
			);

		std::string
			convert_enum_to_string();

		TextEncoding
			convert_string_to_enum(
				const std::string&
					value
			);

		TextEncoding
			convert_string_to_enum();
    };    
}

