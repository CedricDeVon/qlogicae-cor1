#include "pch.hpp"

#include "../includes/text_encoding_manager.hpp"

namespace
	QLogicaeCppCore
{
	const char
		TextEncodingManager
			::decode_base_16_table[] = "0123456789ABCDEF";

	const int8_t
		TextEncodingManager
			::decode_base_32_table[256] =
				{
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,26,27,28,29,30,31,-1,-1,-1,-2,-1,-1,-1,-1,
					-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,
					15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,
					-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,
					15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
				};

	const char
		TextEncodingManager
			::encode_base_32_table[] =
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

	const int8_t
		TextEncodingManager
			::decode_base_64_table[256] =
				{
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,62,-1,-1,-1,63,
					52,53,54,55,56,57,58,59,60,61,-1,-1,-1,-2,-1,-1,
					-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,
					15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,
					-1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
					41,42,43,44,45,46,47,48,49,50,51,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
				};

	const char
		TextEncodingManager
			::encode_base_64_table[] = 
				"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    TextEncodingManager&
        TextEncodingManager
			::singleton =
				SingletonManager
					::get_singleton<TextEncodingManager>();



    TextEncodingManager
		::TextEncodingManager() :
			AbstractClass<TextEncodingManagerConfigurations>()
	{
		try
		{
			construct();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);
		}		
	}

	TextEncodingManager
		::~TextEncodingManager()
	{
		try
		{
			destruct();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);
		}		
	}
    
    bool
        TextEncodingManager
			::construct()
    {
        try
        {			
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
    }

    bool
        TextEncodingManager
			::destruct()
    {
        try
        {		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
    }

	std::string
		TextEncodingManager
			::decode_base16(
				const std::string&
					input
			)
	{
		try
        {		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			if ((input.size() & 1) != 0)
			{
				return {};
			}

			std::string output;
			output.resize(input.size() / 2);

			size_t written = 0;

			if (sodium_hex2bin(
				reinterpret_cast<unsigned char*>(&output[0]),
				output.size(),
				input.data(),
				input.size(),
				nullptr,
				&written,
				nullptr
			) != 0)
			{
				return {};
			}

			output.resize(written);
			return output;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);

			return
				"";				
        }		
	}

	std::string
		TextEncodingManager
			::encode_base16(
				const std::string&
					input
			)
	{
		try
        {		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			std::string output;
			output.resize(input.size() * 2 + 1);

			sodium_bin2hex(
				&output[0],
				output.size(),
				reinterpret_cast<const unsigned char*>(input.data()),
				input.size()
			);

			output.pop_back();
			return output;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);

			return
				"";				
        }		
	}

	std::string
		TextEncodingManager
			::decode_base32(
				const std::string& input
			)
	{
		try
        {		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			std::string output;

			int buffer = 0;
			int bits = 0;

			for (char c : input)
			{
				int8_t v = decode_base_32_table[static_cast<uint8_t>(c)];

				if (v == -1)
				{
					return {};
				}

				if (v == -2)
				{
					break;
				}

				buffer = (buffer << 5) | v;
				bits += 5;

				if (bits >= 8)
				{
					output.push_back(
						static_cast<char>((buffer >> (bits - 8)) & 0xFF)
					);
					bits -= 8;
				}
			}

			return output;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);

			return
				"";				
        }		
	}

	std::string
		TextEncodingManager
			::encode_base32(
				const std::string&
					input
			)
	{
		try
        {		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			
			
			std::string result;
			int buffer = 0;
			int bits = 0;

			for (unsigned char b : input)
			{
				buffer = (buffer << 8) | b;
				bits += 8;

				while (bits >= 5)
				{
					result.push_back(
						encode_base_32_table[(buffer >> (bits - 5)) & 0x1F]
					);
					bits -= 5;
				}
			}

			if (bits > 0)
			{
				result.push_back(
					encode_base_32_table[(buffer << (5 - bits)) & 0x1F]
				);
			}

			while ((result.size() & 7) != 0)
			{
				result.push_back('=');
			}

			return result;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);

			return
				"";				
        }		
	}

	std::string
		TextEncodingManager
			::decode_base64(
				const std::string& input
			)
	{
		try
        {		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			std::string output;
			output.resize(input.size());

			size_t written = 0;

			if (sodium_base642bin(
				reinterpret_cast<unsigned char*>(&output[0]),
				output.size(),
				input.data(),
				input.size(),
				nullptr,
				&written,
				nullptr,
				sodium_base64_VARIANT_ORIGINAL
			) != 0)
			{
				return {};
			}

			output.resize(written);
			return output;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);

			return
				"";				
        }		
	}

	std::string
		TextEncodingManager
			::encode_base64(
				const std::string& input
			)
	{
		try
        {		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			size_t encoded_size =
				sodium_base64_encoded_len(
					input.size(),
					sodium_base64_VARIANT_ORIGINAL
				);

			std::string output;
			output.resize(encoded_size);

			sodium_bin2base64(
				&output[0],
				output.size(),
				reinterpret_cast<const unsigned char*>(input.data()),
				input.size(),
				sodium_base64_VARIANT_ORIGINAL
			);

			output.pop_back();
			return output;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);

			return
				"";				
        }		
	}

	std::string
	TextEncodingManager
		::convert_text(
			const std::string&
				text,
			const TextEncoding&
				original_type,
			const TextEncoding&
				target_type
		)
	{
		try
        {		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			if (text.empty())
			{
				return {};
			}

			if (original_type == target_type)
			{
				return text;
			}

			if (
				original_type == TextEncoding::NONE ||
				target_type == TextEncoding::NONE
			)
			{
				return {};
			}

			std::string
				bytes;

			switch (original_type)
			{
				case TextEncoding::BASE16:
					bytes = decode_base16(text);
					break;

				case TextEncoding::BASE32:
					bytes = decode_base32(text);
					break;

				case TextEncoding::BASE64:
					bytes = decode_base64(text);
					break;

				default:
					return {};
			}

			if (bytes.empty())
			{
				return {};
			}

			switch (target_type)
			{
				case TextEncoding::BASE16:
					return encode_base16(bytes);

				case TextEncoding::BASE32:
					return encode_base32(bytes);

				case TextEncoding::BASE64:
					return encode_base64(bytes);

				default:
					return {};
			}
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);

			return
				"";				
        }		
	}
}
