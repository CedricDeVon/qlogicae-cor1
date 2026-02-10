#include "pch.hpp"

#include "../includes/sha256_hash_cryptography_manager.hpp"

namespace
	QLogicaeCppCore
{
	Sha256HashCryptographyManager&
        Sha256HashCryptographyManager
			::singleton =
				SingletonManager
					::get_singleton<Sha256HashCryptographyManager>();



    Sha256HashCryptographyManager
		::Sha256HashCryptographyManager() :
			AbstractClass<Sha256HashCryptographyManagerConfigurations>()
	{

	}

	std::string
		Sha256HashCryptographyManager
			::hash_text(
				const std::string&
					text
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
						text.empty()
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
						feature_handling_mutex_2
					);
			}			

			unsigned char
				hash[crypto_hash_sha256_BYTES];

			crypto_hash_sha256(
				hash,
				reinterpret_cast<const unsigned char*>(text.data()),
				static_cast<unsigned long long>(text.size())
			);

			std::string
				hex(
					crypto_hash_sha256_BYTES * 2,
					'\0'
				);

			sodium_bin2hex(
				hex.data(),
				hex.size() + 1,
				hash,
				crypto_hash_sha256_BYTES
			);

			return
				hex;
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

	bool
		Sha256HashCryptographyManager
			::verify_text(
				const std::string&
					text,
				const std::string&
					hash
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
						hash.empty()
					)
				)
			)
			{
				return
					false;
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

			const std::string computed_hash = hash_text(text);

			if (computed_hash.empty())
				return false;

			return computed_hash == hash;
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
}
