#include "pch.hpp"

#include "../includes/jsonwebtoken_cryptography_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    JsonWebTokenCryptographyManager
		::JsonWebTokenCryptographyManager() :
			AbstractClass<JsonWebTokenCryptographyManagerConfigurations>()
	{
			
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						text.empty() ||
						public_key.empty() ||
						private_key.empty()
					)
				)
			)
			{
				return
					"";
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

			try
			{
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
			catch (...)
			{
				return
					"";
			}           			
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						text.empty() ||
						public_key.empty()
					)
				)
			)
			{
				return
					"";
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

			try
			{
				auto decoded =
					jwt::decode(
						text
					);

				if (decoded.get_issuer() != configurations.issuer)
				{
					return
						"";
				}

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
						)
						.leeway(0);

				verifier.verify(
					decoded
				);

				return
					decoded.get_payload();
			}
			catch (...)
			{
				return
					"";
			}			
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
