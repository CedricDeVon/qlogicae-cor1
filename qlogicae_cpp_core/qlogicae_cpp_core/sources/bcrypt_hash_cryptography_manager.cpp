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
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
			);		

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
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
			);			

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
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				text,
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				text.empty()
			);		

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
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				text.empty() ||
				hash.empty()
			);		

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
