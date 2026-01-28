#include "pch.hpp"

#include "../includes/argon2id_hash_cryptography_manager.hpp"

namespace
	QLogicaeCppCore
{
	Argon2idHashCryptographyManager&
        Argon2idHashCryptographyManager
			::singleton =
				SingletonManager
					::get_singleton<Argon2idHashCryptographyManager>();



    Argon2idHashCryptographyManager
		::Argon2idHashCryptographyManager() :
			AbstractClass<Argon2idHashCryptographyManagerConfigurations>()
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

	Argon2idHashCryptographyManager
		::~Argon2idHashCryptographyManager()
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
        Argon2idHashCryptographyManager
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
        Argon2idHashCryptographyManager
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
		Argon2idHashCryptographyManager
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

			std::array<char, 512> vb{};
			int vc = argon2id_hash_encoded(
				3,
				1 << 16,
				2,
				text.data(),
				text.size(),
				RandomValueGenerationManager::singleton.generate_random_salt().data(),
				16,
				32,
				vb.data(), vb.size());
			if (vc != ARGON2_OK)
			{
				return "";
			}

			return vb.data();
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
		Argon2idHashCryptographyManager
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
				argon2id_verify(
					hash.data(), text.data(), text.size()
				) == ARGON2_OK;
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
