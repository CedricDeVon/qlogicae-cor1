#include "pch.hpp"

#include "../includes/edsca_signature_cryptography_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    EdscaSignatureCryptographyManager
		::EdscaSignatureCryptographyManager() :
			AbstractClass<EdscaSignatureCryptographyManagerConfigurations>()
	{
		construct();	
	}

	bool
		EdscaSignatureCryptographyManager
			::construct()
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					{};
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

	std::vector<std::uint8_t>
		EdscaSignatureCryptographyManager
			::sign(
				const std::vector<std::uint8_t>&
					text,
				const std::vector<std::uint8_t>&
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
						!text.size() ||
						!private_key.size() ||
						private_key.size() != crypto_sign_SECRETKEYBYTES
					)
				)
			)
			{
				return
					{};
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

			std::vector<std::uint8_t>
				signature(
					crypto_sign_BYTES
				);
        
			crypto_sign_detached(
				signature.data(), nullptr,
				text.data(), text.size(),
				private_key.data()
			);

			return
				signature;
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
		EdscaSignatureCryptographyManager
			::verify(
				const std::vector<std::uint8_t>&
					text,
				const std::vector<std::uint8_t>&
					public_key,
				const std::vector<std::uint8_t>&
					signature
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
						!text.size() ||
						!public_key.size() ||
						!signature.size() ||
						public_key.size() != crypto_sign_PUBLICKEYBYTES ||
						signature.size() != crypto_sign_BYTES	
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
				crypto_sign_verify_detached(
					signature.data(),
					text.data(), text.size(),
					public_key.data()
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

	std::string
		EdscaSignatureCryptographyManager
			::sign(
				const std::string&
					text,
				const std::string&
					private_key
			)
	{
		auto sig_vec = sign(
            std::vector<std::uint8_t>(text.begin(), text.end()),
            std::vector<std::uint8_t>(private_key.begin(), private_key.end())
        );

        return
			std::string(sig_vec.begin(), sig_vec.end());
	}

	bool
		EdscaSignatureCryptographyManager
			::verify(
				const std::string&
					text,
				const std::string&
					public_key,
				const std::string&
					signature
			)
	{
		return
			verify(
				std::vector<std::uint8_t>(text.begin(), text.end()),
				std::vector<std::uint8_t>(public_key.begin(), public_key.end()),
				std::vector<std::uint8_t>(signature.begin(), signature.end())
			);
	}
}

