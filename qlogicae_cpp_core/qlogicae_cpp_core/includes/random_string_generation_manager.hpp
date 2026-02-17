#pragma once

#include "abstract_class.hpp"
#include "character_domain.hpp"
#include "singleton_manager.hpp"
#include "text_encoding_manager.hpp"
#include "character_domain_manager.hpp"
#include "random_seed_generation_manager.hpp"
#include "random_string_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		RandomStringGenerationManager :
			public AbstractClass<RandomStringGenerationManagerConfigurations>
    {
    public:
		static RandomStringGenerationManager&
			singleton;

		RandomStringGenerationManager();

		template <typename Type> Type
			generate_string(
				const CharacterDomain&
					character_domain,
				const size_t&
					length,
				const std::unordered_set<Type>&
					excluded
			);

		template <typename Type> Type
			generate_string(
				const CharacterDomain&
					character_domain,
				const size_t&
					length
			);

		template <typename Type> Type
			generate_string(
				const CharacterDomain&
					character_domain
			);		

		template <typename Type> Type
			generate_string(
				const Type&
					character_domain,
				const size_t&
					length
			);		

		template <typename Type> Type
			generate_string(
				const Type&
					character_domain
			);

		template <typename Type> Type
			generate_string();		
	};

	template <typename Type> Type
		RandomStringGenerationManager
			::generate_string(
				const CharacterDomain&
					character_domain,
				const size_t&
					length,
				const std::unordered_set<Type>&
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
					Type {};
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

			Type
				result;

			result.reserve
			(
				length
			);

			const std::string
				domain =
					CharacterDomainManager
						::singleton
							.get_value
							(
								character_domain
							);

			std::vector<Type>
				filtered;

			filtered.reserve
			(
				domain.size()
			);

			for
			(
				const char
					character :
						domain
			)
			{
				const Type
					converted =
						static_cast<Type>
						(
							character
						);

				if
				(
					excluded
						.find
						(
							converted
						)
					==
					excluded
						.end()
				)
				{
					filtered.push_back
					(
						converted
					);
				}
			}

			if
			(
				filtered
					.empty()
			)
			{
				return
					static_cast<Type>(0);
			}

			std::uniform_int_distribution<std::size_t>
				distribution
				(
					0,
					filtered.size() - 1
				);

			for
			(
				size_t index = 0;
				index < length;
				++index
			)
			{				
				result.push_back
				(
					filtered
					[
						distribution
						(
							RandomSeedGenerationManager
								::singleton
									.random_indeterministic_seed_engine
						)
					]
				);
			}

			return
				result;
        }
        catch
        (
            const std::exception&
                exception
        )
        {			
			return
				handle_error_outputs<Type>(
					exception
				);
        }
	}

	template <typename Type> Type
		RandomStringGenerationManager
			::generate_string(
				const CharacterDomain&
					character_domain,
				const size_t&
					length
			)
	{
		return
			generate_string<Type>
			(
				character_domain,
				length,
				{}
			);
	}


	template <typename Type> Type
		RandomStringGenerationManager
			::generate_string(
				const CharacterDomain&
					character_domain
			)
	{
		return
			generate_string<Type>
			(
				character_domain,
				configurations
					.length
			);
	}

	template <typename Type> Type
		RandomStringGenerationManager
			::generate_string(
				const Type&
					character_domain,
				const size_t&
					length
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
					Type {};
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

			Type
				result;

			result.reserve
			(
				length
			);


			std::uniform_int_distribution<std::size_t>
				distribution
				(
					0,
					length - 1
				);

			for
			(
				size_t index = 0;
				index < length;
				++index
			)
			{
				result.push_back
				(
					character_domain
					[
						distribution
						(
							RandomSeedGenerationManager
								::singleton
									.random_indeterministic_seed_engine
						)
					]
				);
			}

			return
				result;
        }
        catch
        (
            const std::exception&
                exception
        )
        {			
			return
				handle_error_outputs<Type>(
					exception
				);
        }
	}

	template <typename Type> Type
		RandomStringGenerationManager
			::generate_string(
				const Type&
					character_domain
			)
	{
		return
			generate_string<Type>
			(
				character_domain,
				configurations
					.length
			);
	}

	template <typename Type> Type
		RandomStringGenerationManager
			::generate_string()
	{
		return
			generate_string<Type>
			(
				configurations
					.character_domain,
				configurations
					.length
			);
	}
}
