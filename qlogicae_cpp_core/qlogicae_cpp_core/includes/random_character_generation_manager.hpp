#pragma once

#include "abstract_class.hpp"
#include "character_domain.hpp"
#include "singleton_manager.hpp"
#include "text_encoding_manager.hpp"
#include "character_domain_manager.hpp"
#include "random_seed_generation_manager.hpp"
#include "random_character_generation_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		RandomCharacterGenerationManager :
			public AbstractClass<RandomCharacterGenerationManagerConfigurations>
    {
    public:
		static RandomCharacterGenerationManager&
			singleton;

		RandomCharacterGenerationManager();

		template <typename Type> Type
			generate_character(
				const CharacterDomain&
					character_domain,
				const std::unordered_set<Type>&
					xdz
			);

		template <typename Type> Type
			generate_character(
				const CharacterDomain&
					character_domain
			);

		template <typename Type> Type
			generate_character(
				const std::string&
					character_domain,
				const std::unordered_set<Type>&
					excluded
			);

		template <typename Type> Type
			generate_character(
				const std::string&
					character_domain
			);
	};

	template <typename Type> Type
		RandomCharacterGenerationManager
			::generate_character(
				const CharacterDomain&
					character_domain,
				const std::unordered_set<Type>&
					excluded
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
					Type{};
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;

			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			const std::string
				domain =
					CharacterDomainManager
						::singleton
							.get_value
							(
								character_domain
							);

			if
			(
				domain
					.empty()
			)
			{
				return
					Type{};
			}

			std::size_t eligible_count = 0;
			for (const char c : domain)
			{
				if (excluded.find(static_cast<Type>(c)) == excluded.end())
				{
					++eligible_count;
				}
			}

			if (eligible_count == 0)
			{
				return Type{};
			}
				
			std::uniform_int_distribution<std::size_t> distribution(0, eligible_count - 1);
			std::size_t target_index =
				distribution(RandomSeedGenerationManager::singleton.random_indeterministic_seed_engine);
				
			for (const char c : domain)
			{
				const Type converted = static_cast<Type>(c);

				if (excluded.find(converted) == excluded.end())
				{
					if (target_index == 0)
					{
						return converted;
					}
					--target_index;
				}
			}

			return
				Type{}; 
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs
			(
				exception
			);

			return
				Type {};
		}
    }

    template <typename Type> Type
		RandomCharacterGenerationManager
			::generate_character(
				const CharacterDomain&
					character_domain
			)
    {
        return
            generate_character<Type>
            (
                character_domain,
                {}
            );
    }

	template <typename Type> Type
		RandomCharacterGenerationManager
			::generate_character(
				const std::string&
					character_domain,
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
						character_domain.empty()
					)
				)

			)
			{
				return
					Type{};
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;

			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			std::vector<Type> candidates;
			candidates.reserve(character_domain.size());

			for (const auto& ch : character_domain)
			{
				if (excluded.find(static_cast<Type>(ch)) == excluded.end())
					candidates.push_back(static_cast<Type>(ch));
			}

			if (candidates.empty())
			{
				return
					Type{};
			}

			const std::size_t index =
				std::uniform_int_distribution<std::size_t>(
					0,
					candidates.size() - 1
				)(RandomSeedGenerationManager::singleton.random_indeterministic_seed_engine);

			return
				candidates[index];
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs
			(
				exception
			);

			return
				Type {};
		}
	}

	template <typename Type> Type
		RandomCharacterGenerationManager
			::generate_character(
				const std::string&
					character_domain
			)
	{
		return
			generate_character<Type>(
				character_domain,
				{}
			);
	}
}

