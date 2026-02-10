#include "pch.hpp"

#include "../includes/xchacha20_poly1305_cipher_cryptography_manager.hpp"

namespace
	QLogicaeCppCore
{
	XChaCha20Poly1305CipherCryptographyManager&
        XChaCha20Poly1305CipherCryptographyManager
			::singleton =
				SingletonManager
					::get_singleton<XChaCha20Poly1305CipherCryptographyManager>();



    XChaCha20Poly1305CipherCryptographyManager
		::XChaCha20Poly1305CipherCryptographyManager() :
			AbstractClass<XChaCha20Poly1305CipherCryptographyManagerConfigurations>()
	{
			
	}

	std::string
		XChaCha20Poly1305CipherCryptographyManager
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						text.empty() ||
						private_key.size() != crypto_aead_xchacha20poly1305_ietf_KEYBYTES ||
						nonce.size() != crypto_aead_xchacha20poly1305_ietf_NPUBBYTES
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

			std::vector<unsigned char>
				ciphertext(
					text.size() +
					crypto_aead_xchacha20poly1305_ietf_ABYTES
				);

			unsigned long long
				ciphertext_length =
				0;

			if (
				crypto_aead_xchacha20poly1305_ietf_encrypt(
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
				return
					text;
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

			return
				encoded;
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
				text;
        }
	}

	std::string
		XChaCha20Poly1305CipherCryptographyManager
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						text.empty() ||
						private_key.size() != crypto_aead_xchacha20poly1305_ietf_KEYBYTES ||
						nonce.size() != crypto_aead_xchacha20poly1305_ietf_NPUBBYTES
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
				return
					text;
			}

			if (decoded_length < crypto_aead_xchacha20poly1305_ietf_ABYTES)
			{
				return
					text;
			}

			std::vector<unsigned char>
				plaintext(
					decoded_length -
					crypto_aead_xchacha20poly1305_ietf_ABYTES
				);

			unsigned long long
				plaintext_length =
					0;

			if (
				crypto_aead_xchacha20poly1305_ietf_decrypt(
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
				return
					text;
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
				text;
        }
	}
}
