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
		boost::mutex
			feature_handling_mutex_2;

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

