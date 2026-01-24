#include "pch.hpp"

#include "../includes/text_encoding_manager.hpp"

namespace
	QLogicaeCppCore
{	
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
						feature_handling_mutex_2
					);
			}			

			if (input.size() % 2 != 0)
			{
				return {};
			}

			std::string output;
			output.resize(input.size() / 2);

			if (sodium_hex2bin(
				reinterpret_cast<unsigned char*>(&output[0]),
				output.size(),
				input.data(),
				input.size(),
				nullptr,
				nullptr,
				nullptr) != 0)
			{
				return {};
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
						feature_handling_mutex_2
					);
			}			

			std::string output;
			output.resize(input.size() * 2 + 1);
			sodium_bin2hex(&output[0], output.size(),
				reinterpret_cast<const unsigned char*>(input.data()),
				input.size());
			output.pop_back();
			std::transform(output.begin(), output.end(), output.begin(),
				[](unsigned char c) { return std::toupper(c); });

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
						feature_handling_mutex_2
					);
			}			

			using base32_codec = cppcodec::base32_rfc4648;
			std::vector<uint8_t> decoded_bytes =
				base32_codec::decode(input);

			return std::string(
				decoded_bytes.begin(),
				decoded_bytes.end());
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
						feature_handling_mutex_2
					);
			}			
			
			using base32_codec = cppcodec::base32_rfc4648;
			std::vector<uint8_t> binary_data(
				input.begin(), input.end());

			return base32_codec::encode(binary_data);
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
						feature_handling_mutex_2
					);
			}			

			std::string output = input;
			size_t padding_needed = (4 - (output.size() % 4)) % 4;
			output.append(padding_needed, '=');

			size_t written = 0;
			if (sodium_base642bin(
				reinterpret_cast<unsigned char*>(&output[0]),
				output.size(),
				output.data(),
				output.size(),
				nullptr,
				&written,
				nullptr,
				sodium_base64_VARIANT_ORIGINAL) != 0)
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
						feature_handling_mutex_2
					);
			}			

			size_t encoded_size = sodium_base64_encoded_len(input.size(), sodium_base64_VARIANT_ORIGINAL);
			std::string output;
			output.resize(encoded_size);

			sodium_bin2base64(
				&output[0],
				output.size(),
				reinterpret_cast<const unsigned char*>(input.data()),
				input.size(),
				sodium_base64_VARIANT_ORIGINAL);

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

			if (original_type == target_type)
			{
				return text;
			}

			if (
				text.empty() ||
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
