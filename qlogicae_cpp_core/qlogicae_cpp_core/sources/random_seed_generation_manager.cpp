#include "pch.hpp"

#include "../includes/random_seed_generation_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{				
	RandomSeedGenerationManager
		::RandomSeedGenerationManager() :
			AbstractClass<RandomSeedGenerationManagerConfigurations>()
	{
		construct();
	}

	RandomSeedGenerationManager
		::~RandomSeedGenerationManager()
	{
		destruct();
	}

	bool
		RandomSeedGenerationManager
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

			setup_indeterministic_seed();
			setup_deterministic_seed(
				mix_entropy()
			);
			setup_cryptography_seed();

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
		RandomSeedGenerationManager
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

	uint64_t
		RandomSeedGenerationManager
			::generate_indeterministic_seed()
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
					random_indeterministic_seed_engine();
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

			random_indeterministic_seed_engine
				.seed(
					static_cast<std::uint32_t>(
						mix_split_64(
							mix_entropy()
						)
					)
				);

			return
				random_indeterministic_seed_engine();
		}
		catch
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{		
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE
			(
				random_indeterministic_seed_engine()
			);
		}
	}

    uint64_t
		RandomSeedGenerationManager
			::generate_cryptography_seed()
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
					random_cryptography_seed_engine();
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

			std::random_device rd;

			if (rd.entropy() == 0.0)
			{
				return
					random_cryptography_seed_engine();
			}

			std::array<std::uint32_t, 2>
				buffer
			{
				rd(),
				rd()
			};

			std::uint64_t seed = 0;

			std::memcpy(
				&seed,
				buffer.data(),
				sizeof(seed)
			);

			random_cryptography_seed_engine
				.seed(
					static_cast<std::uint32_t>(
						mix_split_64(
							seed
						)
					)
			);

			return
				random_cryptography_seed_engine();
		}
		catch
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{		
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE
			(
				random_cryptography_seed_engine()
			);
		}
	}

	uint64_t
		RandomSeedGenerationManager
			::generate_deterministic_seed(
				const std::uint64_t&
					value
			)
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
					random_deterministic_seed_engine();
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

			random_deterministic_seed_engine
				.seed(
					static_cast<std::uint32_t>(
						mix_split_64(
							value
						)
					)
				);

			return
				random_deterministic_seed_engine();
		}
		catch
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{		
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE
			(
				random_deterministic_seed_engine()
			);
		}		
	}

	bool
		RandomSeedGenerationManager
			::setup_indeterministic_seed()
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
					false;
			}

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

			random_indeterministic_seed_engine
				.seed(
					static_cast<std::uint32_t>(
						mix_split_64(
							mix_entropy()
						)
					)
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

    bool
		RandomSeedGenerationManager
			::setup_cryptography_seed()
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
					false;
			}

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

			std::random_device rd;

			if (rd.entropy() == 0.0)
			{
				return
					false;
			}

			std::array<std::uint32_t, 2>
				buffer
			{
				rd(),
				rd()
			};

			std::uint64_t seed = 0;

			std::memcpy(
				&seed,
				buffer.data(),
				sizeof(seed)
			);

			random_cryptography_seed_engine
				.seed(
					static_cast<std::uint32_t>(
						mix_split_64(
							seed
						)
					)
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

	bool
		RandomSeedGenerationManager
			::setup_deterministic_seed(
				const std::uint64_t&
					value
			)
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
					false;
			}

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

			random_deterministic_seed_engine
				.seed(
					static_cast<std::uint32_t>(
						mix_split_64(
							value
						)
					)
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

	std::uint64_t
		RandomSeedGenerationManager
			::mix_entropy()
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
					0;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_3
					);
			}

			std::random_device rd;

			const std::uint64_t rd_part =
				(static_cast<std::uint64_t>(rd()) << 32)
				^ static_cast<std::uint64_t>(rd());

			const std::uint64_t time_part =
				static_cast<std::uint64_t>(
					std::chrono::
					high_resolution_clock::
					now().time_since_epoch().count()
					);

			return
				rd_part ^ time_part;
		}
		catch
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
		}
	}

	std::uint64_t
		RandomSeedGenerationManager
			::mix_split_64(
				const std::uint64_t&
					value
			)
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
					value;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_3
					);
			}

			std::uint64_t
				output = value;

			output +=
				0x9E3779B97F4A7C15ULL;

			output =
				(output ^ (output >> 30))
				* 0xBF58476D1CE4E5B9ULL;

			output =
				(output ^ (output >> 27))
				* 0x94D049BB133111EBULL;

			return
				output ^ (output >> 31);
		}
		catch
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE
			(
				value
			);
		}
	}
}
