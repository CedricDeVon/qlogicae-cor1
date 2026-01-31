#include "pch.hpp"

#include "../includes/aes256_cipher_cryptography_manager.hpp"

namespace
	QLogicaeCppCore
{
	Aes256CipherCryptographyManager&
        Aes256CipherCryptographyManager
			::singleton =
				SingletonManager
					::get_singleton<Aes256CipherCryptographyManager>();



    Aes256CipherCryptographyManager
		::Aes256CipherCryptographyManager() :
			AbstractClass<Aes256CipherCryptographyManagerConfigurations>()
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

	Aes256CipherCryptographyManager
		::~Aes256CipherCryptographyManager()
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
        Aes256CipherCryptographyManager
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
        Aes256CipherCryptographyManager
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
		Aes256CipherCryptographyManager
			::encrypt_text(
				const std::string&
					text,
				const std::string&
					private_key,
				const std::string&
					nonce
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

			if (text.empty() || private_key.empty() || nonce.empty())
			{
				return
					"";
			}
			
			std::vector<unsigned char>
				ciphertext(
					text.size() +
					crypto_aead_aes256gcm_ABYTES
				);

			unsigned long long
				ciphertext_length =
					0;

			if (
				crypto_aead_aes256gcm_encrypt(
					ciphertext.data(),
					&ciphertext_length,
					reinterpret_cast<const unsigned char*>(text.data()),
					static_cast<unsigned long long>(text.size()),
					nullptr,
					0,
					nullptr,
					reinterpret_cast<const unsigned char*>(nonce.data()),
					reinterpret_cast<const unsigned char*>(private_key.data())
				) != 0
			)
			{
				return {};
			}

			std::string
				encoded(
					sodium_base64_ENCODED_LEN(
						ciphertext_length,
						sodium_base64_VARIANT_ORIGINAL
					),
					'\0'
				);

			sodium_bin2base64(
				encoded.data(),
				encoded.size(),
				ciphertext.data(),
				ciphertext_length,
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
		Aes256CipherCryptographyManager
			::decrypt_text(
				const std::string&
					text,
				const std::string&
					private_key,
				const std::string&
					nonce
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

			if (text.empty() || private_key.empty() || nonce.empty())
			{
				return
					"";
			}

			std::vector<unsigned char>
				decoded(text.size());

			unsigned long long
				decoded_length =
					0;

			if (
				sodium_base642bin(
					decoded.data(),
					decoded.size(),
					text.c_str(),
					text.size(),
					nullptr,
					&decoded_length,
					nullptr,
					sodium_base64_VARIANT_ORIGINAL
				) != 0
			)
			{
				return {};
			}

			if (decoded_length < crypto_aead_aes256gcm_ABYTES)
			{
				return {};
			}

			std::vector<unsigned char>
				plaintext(
					decoded_length -
					crypto_aead_aes256gcm_ABYTES
				);

			unsigned long long
				plaintext_length =
					0;

			if (
				crypto_aead_aes256gcm_decrypt(
					plaintext.data(),
					&plaintext_length,
					nullptr,
					decoded.data(),
					decoded_length,
					nullptr,
					0,
					reinterpret_cast<const unsigned char*>(nonce.data()),
					reinterpret_cast<const unsigned char*>(private_key.data())
				) != 0
			)
			{
				return {};
			}

			return std::string(
				reinterpret_cast<const char*>(plaintext.data()),
				plaintext_length
			);
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

