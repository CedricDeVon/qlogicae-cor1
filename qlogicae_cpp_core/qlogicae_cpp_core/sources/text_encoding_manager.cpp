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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						input.size() % 2 != 0
					)
				)
			)
			{
				return
					"";
			}

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
			output.resize(input.size() / 2);

			try
			{
				if (sodium_hex2bin(
					reinterpret_cast<unsigned char*>(&output[0]),
					output.size(),
					input.data(),
					input.size(),
					nullptr,
					nullptr,
					nullptr) != 0)
				{
					return "";
				}
			}
			catch (...)
			{
				return "";
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						input.empty()
					)
				)
			)
			{
				return
					"";
			}

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

			try
			{
				sodium_bin2hex(&output[0], output.size(),
					reinterpret_cast<const unsigned char*>(input.data()),
					input.size());
				output.pop_back();
				std::transform(output.begin(), output.end(), output.begin(),
					[](unsigned char c) { return std::toupper(c); });
			}
			catch (...)
			{
				return "";
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
			::decode_base32(
				const std::string& input
			)
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						input.empty()
					)
				)
			)
			{
				return
					"";
			}

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

			try
			{
				using base32_codec = cppcodec::base32_rfc4648;
				std::vector<uint8_t> decoded_bytes =
					base32_codec::decode(input);

				return
					std::string(
						decoded_bytes.begin(),
						decoded_bytes.end()
					);
			}
			catch (...)
			{
				return "";
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

	std::string
		TextEncodingManager
			::encode_base32(
				const std::string&
					input
			)
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						input.empty()
					)
				)
			)
			{
				return
					"";
			}

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
			
			try
			{
				using base32_codec = cppcodec::base32_rfc4648;
				std::vector<uint8_t> binary_data(
					input.begin(), input.end());

				return
					base32_codec::encode(binary_data);
			}
			catch (...)
			{
				return "";
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

	std::string
		TextEncodingManager
			::decode_base64(
				const std::string& input
			)
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						input.empty()
					)
				)
			)
			{
				return
					"";
			}

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

			try
			{
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
					return "";
				}
			}
			catch (...)
			{
				return "";
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						input.empty()
					)
				)
			)
			{
				return
					"";
			}

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

			try
			{
				sodium_bin2base64(
					&output[0],
					output.size(),
					reinterpret_cast<const unsigned char*>(input.data()),
					input.size(),
					sodium_base64_VARIANT_ORIGINAL);
			}
			catch (...)
			{
				return "";
			}			

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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						text.empty() ||
						original_type == TextEncoding::NONE ||
						target_type == TextEncoding::NONE ||
						original_type == target_type
					)
				)
			)
			{
				return
					text;
			}

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

	std::string
		TextEncodingManager
			::convert_bytes_to_string(
				const std::vector<std::byte>&
					value
			)
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						!value.size()
					)
				)
			)
			{
				return
					"";
			}

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

			return
				{
					reinterpret_cast<const char*>(
						value.data()),
						value.size()
				};
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

	std::vector<std::byte>
		TextEncodingManager
			::convert_string_to_bytes(
				const std::string&
					value
			)
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						value.empty()
					)
				)
			)
			{
				return
					{};
			}

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

			return
				{
					reinterpret_cast<const std::byte*>(value.data()),
					reinterpret_cast<const std::byte*>(value.data()) + value.size()
				};
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
				{};				
        }		
	}
}
