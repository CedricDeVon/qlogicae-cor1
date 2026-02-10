#include "pch.hpp"

#include "../includes/jsonwebtoken_cryptography_manager.hpp"

namespace
	QLogicaeCppCore
{
	JsonWebTokenCryptographyManager&
        JsonWebTokenCryptographyManager
			::singleton =
				SingletonManager
					::get_singleton<JsonWebTokenCryptographyManager>();



    JsonWebTokenCryptographyManager
		::JsonWebTokenCryptographyManager() :
			AbstractClass<JsonWebTokenCryptographyManagerConfigurations>()
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

	JsonWebTokenCryptographyManager
		::~JsonWebTokenCryptographyManager()
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
        JsonWebTokenCryptographyManager
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
        JsonWebTokenCryptographyManager
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
		JsonWebTokenCryptographyManager
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
			
			auto now = std::chrono::system_clock::now();

            auto builder = jwt::create()
                .set_type("JWT")
                .set_issuer(configurations.issuer)
                .set_subject(text)
                .set_issued_at(now);

            if (configurations.lifetime.count() > 0)
			{
                builder.set_expires_at(now + configurations.lifetime);
			}

            for (const auto& [k, v] : configurations.claims)
			{
                builder.set_payload_claim(k, jwt::claim(v));
			}

			const jwt::algorithm::es256k signer(
				public_key, private_key, "", ""
			);

            return
				builder.sign(				
					signer
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

	std::string
		JsonWebTokenCryptographyManager
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

			auto decoded =
				jwt::decode(
					text
				);

			const jwt::algorithm::es256k
				verifier_algorithm(
					public_key,
					"",
					"",
					""
				);

			auto verifier =
				jwt::verify()
					.allow_algorithm(
						verifier_algorithm
					)
					.with_issuer(
						configurations.issuer
					);

			verifier.verify(
				decoded
			);

			return
				decoded.get_payload();
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
