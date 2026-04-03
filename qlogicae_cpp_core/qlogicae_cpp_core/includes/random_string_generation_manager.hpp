#pragma once

#include "abstract_class.hpp"
#include "character_domain.hpp"
#include "singleton_manager.hpp"
#include "text_encoding_manager.hpp"
#include "character_domain_manager.hpp"
#include "random_seed_generation_manager.hpp"
#include "random_string_generation_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		RandomStringGenerationManager :
			public AbstractClass<RandomStringGenerationManagerConfigurations>
    {
    public:
		RandomStringGenerationManager();

		template <typename OutputType = std::string, typename ExcludedType = char> OutputType
			generate_string(
				const CharacterDomain&
					character_domain,
				const size_t&
					length,
				const std::unordered_set<ExcludedType>&
					excluded
			);

		template <typename OutputType = std::string, typename ExcludedType = char> OutputType
			generate_string(
				const OutputType&
					character_domain,
				const size_t&
					length,
				const std::unordered_set<ExcludedType>&
					excluded
			);

		template <typename OutputType = std::string, typename ExcludedType = char> OutputType
			generate_string(
				const CharacterDomain&
					character_domain,
				const size_t&
					length
			);

		template <typename OutputType = std::string, typename ExcludedType = char> OutputType
			generate_string(
				const CharacterDomain&
					character_domain
			);		

		template <typename OutputType = std::string, typename ExcludedType = char> OutputType
			generate_string(
				const OutputType&
					character_domain,
				const size_t&
					length
			);		

		template <typename OutputType = std::string, typename ExcludedType = char> OutputType
			generate_string(
				const OutputType&
					character_domain
			);

		template <typename OutputType = std::string, typename ExcludedType = char> OutputType
			generate_string();		
	};

	template <typename OutputType, typename ExcludedType> OutputType
		RandomStringGenerationManager
			::generate_string(
				const CharacterDomain&
					character_domain,
				const size_t&
					length,
				const std::unordered_set<ExcludedType>&
					excluded
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
						character_domain == CharacterDomain::NONE ||
						length < 1
					)
				)
			)
            {
                return
					OutputType {};
            }

            boost::unique_lock<boost::mutex> mutex_lock;
            if (configurations
                .is_thread_safety_enabled_for_feature_handling())
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        feature_handling_mutex_1
                    );
            }

			OutputType result;
			result.reserve(length);

			const std::string domain =
				SingletonManager::get_singleton<CharacterDomainManager>().get_value(character_domain);

			std::vector<typename OutputType::value_type> filtered;
			filtered.reserve(domain.size());

			for (const char c : domain)
			{
				auto converted = static_cast<typename OutputType::value_type>(c);
				if (excluded.find(converted) == excluded.end())
				{
					filtered.push_back(converted);
				}
			}

			if (filtered.empty())
			{
				return OutputType{};
			}

			std::uniform_int_distribution<std::size_t> distribution(0, filtered.size() - 1);
			for (size_t i = 0; i < length; ++i)
			{
				result.push_back(filtered[distribution(SingletonManager::get_singleton<RandomSeedGenerationManager
					>().random_indeterministic_seed_engine)]);
			}

			return result;
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {			
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE
			(
				OutputType {}
			);
        }
	}

	template <typename OutputType, typename ExcludedType> OutputType
		RandomStringGenerationManager
			::generate_string(
				const OutputType&
					character_domain,
				const size_t&
					length,
				const std::unordered_set<ExcludedType>&
					excluded
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
						length < 1
					)
				)
			)
            {
                return
					OutputType {};
            }

            boost::unique_lock<boost::mutex> mutex_lock;
            if (configurations
                .is_thread_safety_enabled_for_feature_handling())
            {
                mutex_lock =
                    boost::unique_lock<boost::mutex>
                    (
                        feature_handling_mutex_1
                    );
            }

			OutputType result;
			result.reserve(length);

			std::vector<typename OutputType::value_type> filtered;
			filtered.reserve(character_domain.size());

			for (const char c : character_domain)
			{
				auto converted = static_cast<typename OutputType::value_type>(c);
				if (excluded.find(converted) == excluded.end())
				{
					filtered.push_back(converted);
				}
			}

			if (filtered.empty())
			{
				return OutputType{};
			}

			std::uniform_int_distribution<std::size_t> distribution(0, filtered.size() - 1);
			for (size_t i = 0; i < length; ++i)
			{
				result.push_back(filtered[distribution(SingletonManager::get_singleton<RandomSeedGenerationManager
					>().random_indeterministic_seed_engine)]);
			}

			return result;
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {			
			QLOGICAE_COR_V1__EXPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE
			(
				OutputType {}
			);
        }
	}

	template <typename OutputType, typename ExcludedType> OutputType
		RandomStringGenerationManager
			::generate_string(
				const CharacterDomain&
					character_domain,
				const size_t&
					length
			)
	{
		return
			generate_string<OutputType, ExcludedType>
			(
				character_domain,
				length,
				std::unordered_set<ExcludedType> {}
			);
	}


	template <typename OutputType, typename ExcludedType> OutputType
		RandomStringGenerationManager
			::generate_string(
				const CharacterDomain&
					character_domain
			)
	{
		return
			generate_string<OutputType, ExcludedType>
			(
				character_domain,
				configurations
					.length,
				std::unordered_set<ExcludedType> {}
			);
	}

	template <typename OutputType, typename ExcludedType> OutputType
		RandomStringGenerationManager
			::generate_string(
				const OutputType&
					character_domain,
				const size_t&
					length
			)
	{
		return
			generate_string<OutputType, ExcludedType>
			(
				character_domain,
				length,
				std::unordered_set<ExcludedType> {}
			);
	}

	template <typename OutputType, typename ExcludedType> OutputType
		RandomStringGenerationManager
			::generate_string(
				const OutputType&
					character_domain
			)
	{
		return
			generate_string<OutputType, ExcludedType>
			(
				character_domain,
				configurations
					.length,
				std::unordered_set<ExcludedType> {}
			);
	}

	template <typename OutputType, typename ExcludedType> OutputType
		RandomStringGenerationManager
			::generate_string()
	{
		return
			generate_string<OutputType, ExcludedType>
			(
				configurations
					.character_domain,
				configurations
					.length,
				std::unordered_set<ExcludedType> {}
			);
	}
}
