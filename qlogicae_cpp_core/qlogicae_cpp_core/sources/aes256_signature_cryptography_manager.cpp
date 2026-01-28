#include "pch.hpp"

#include "../includes/aes256_signature_cryptography_manager.hpp"

namespace
	QLogicaeCppCore
{
	Aes256SignatureCryptographyManager&
        Aes256SignatureCryptographyManager
			::singleton =
				SingletonManager
					::get_singleton<Aes256SignatureCryptographyManager>();



    Aes256SignatureCryptographyManager
		::Aes256SignatureCryptographyManager() :
			AbstractClass<Aes256SignatureCryptographyManagerConfigurations>()
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

	Aes256SignatureCryptographyManager
		::~Aes256SignatureCryptographyManager()
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
        Aes256SignatureCryptographyManager
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
        Aes256SignatureCryptographyManager
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
		Aes256SignatureCryptographyManager
			::sign_text(
				const std::string&
					text,
				const std::string&
					public_key,
				const std::string&
					private_key
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
			
			unsigned char
				signature[crypto_sign_BYTES];

			unsigned long long
				signature_length =
				0;

			if (
				crypto_sign_detached(
					signature,
					&signature_length,
					reinterpret_cast<const unsigned char*>(text.data()),
					static_cast<unsigned long long>(text.size()),
					reinterpret_cast<const unsigned char*>(private_key.data())
				) != 0
				)
			{
				return {};
			}

			std::string
				encoded(
					sodium_base64_ENCODED_LEN(
						signature_length,
						sodium_base64_VARIANT_ORIGINAL
					),
					'\0'
				);

			sodium_bin2base64(
				encoded.data(),
				encoded.size(),
				signature,
				signature_length,
				sodium_base64_VARIANT_ORIGINAL
			);

			encoded.resize(std::strlen(encoded.c_str()));

			return encoded;
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
		Aes256SignatureCryptographyManager
			::verify_text(
				const std::string&
					text,
				const std::string&
					public_key
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

			
			std::vector<unsigned char>
				signature(crypto_sign_BYTES);

			unsigned long long
				signature_length =
					0;

			if (
				sodium_base642bin(
					signature.data(),
					signature.size(),
					text.c_str(),
					text.size(),
					nullptr,
					&signature_length,
					nullptr,
					sodium_base64_VARIANT_ORIGINAL
				) != 0
			)
			{
				return {};
			}

			if (signature_length != crypto_sign_BYTES)
			{
				return {};
			}

			if (
				crypto_sign_verify_detached(
					signature.data(),
					reinterpret_cast<const unsigned char*>(text.data()),
					static_cast<unsigned long long>(text.size()),
					reinterpret_cast<const unsigned char*>(public_key.data())
				) != 0
			)
			{
				return {};
			}

			return text;
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
