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

	Sha256HashCryptographyManager
		::~Sha256HashCryptographyManager()
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
        Sha256HashCryptographyManager
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
        Sha256HashCryptographyManager
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
		Sha256HashCryptographyManager
			::hash_text(
				const std::string&
					text
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
				"";
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

			const std::string computed_base64_hash = hash_text(hash);
			if (computed_base64_hash.empty())
			{
				return false;
			}

			return sodium_memcmp(
				computed_base64_hash.data(),
				text.data(),
				text.size()) == 0;
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
