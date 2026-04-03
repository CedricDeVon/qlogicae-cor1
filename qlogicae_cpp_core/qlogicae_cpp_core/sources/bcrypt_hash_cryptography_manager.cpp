#include "pch.hpp"

#include "../includes/bcrypt_hash_cryptography_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    BcryptHashCryptographyManager
		::BcryptHashCryptographyManager() :
			AbstractClass<BcryptHashCryptographyManagerConfigurations>()
	{
		construct();	
	}

	BcryptHashCryptographyManager
		::~BcryptHashCryptographyManager()
	{
		destruct();		
	}
    
    bool
        BcryptHashCryptographyManager
			::construct()
    {
        try
        {			
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			return
				!(sodium_init() > 1);
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

    bool
        BcryptHashCryptographyManager
			::destruct()
    {
        try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			return
				true;
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
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
						feature_handling_mutex_1
					);
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
					text;
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
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

			return
				crypto_pwhash_str_verify(
					hash.c_str(),
					text.c_str(),
					text.size()
				) == 0;
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {			
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
	}
}
