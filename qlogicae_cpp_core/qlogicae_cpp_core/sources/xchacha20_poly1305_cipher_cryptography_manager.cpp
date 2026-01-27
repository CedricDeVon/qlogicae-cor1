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

	XChaCha20Poly1305CipherCryptographyManager
		::~XChaCha20Poly1305CipherCryptographyManager()
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
        XChaCha20Poly1305CipherCryptographyManager
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
        XChaCha20Poly1305CipherCryptographyManager
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
}
