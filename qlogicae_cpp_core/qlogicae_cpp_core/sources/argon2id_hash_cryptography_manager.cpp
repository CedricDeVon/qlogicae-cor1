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
				vb.data(),
				vb.size()
			);

			return
				(vc == ARGON2_OK) ?
					vb.data() :
					text;
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
			return
				handle_error_outputs(
					exception
				);
        }
	}
}
