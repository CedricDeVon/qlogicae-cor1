#include "pch.hpp"

#include "../includes/bcrypt_hash_cryptography_manager.hpp"

namespace
	QLogicaeCppCore
{
	BcryptHashCryptographyManager&
        BcryptHashCryptographyManager
			::singleton =
				SingletonManager
					::get_singleton<BcryptHashCryptographyManager>();



    BcryptHashCryptographyManager
		::BcryptHashCryptographyManager() :
			AbstractClass<BcryptHashCryptographyManagerConfigurations>()
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

	BcryptHashCryptographyManager
		::~BcryptHashCryptographyManager()
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
        BcryptHashCryptographyManager
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
				!(sodium_init() < 0);
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
        BcryptHashCryptographyManager
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
		BcryptHashCryptographyManager
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
						feature_handling_mutex_1
					);
			}			

			if (text.empty())
			{
				return
					"";
			}

			std::string hash;
			hash.resize(crypto_pwhash_STRBYTES);

			return
				(crypto_pwhash_str(
					hash.data(),
					text.c_str(), text.size(),
					crypto_pwhash_OPSLIMIT_MODERATE,
					crypto_pwhash_MEMLIMIT_MODERATE
				) == 0) ?
					hash :
					"";
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
		BcryptHashCryptographyManager
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

			return
				crypto_pwhash_str_verify(
					hash.c_str(),
					text.c_str(),
					text.size()
				) == 0;
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
