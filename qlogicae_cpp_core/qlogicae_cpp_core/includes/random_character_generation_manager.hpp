#pragma once

#include "abstract_class.hpp"
#include "character_domain.hpp"
#include "singleton_manager.hpp"
#include "text_encoding_manager.hpp"
#include "character_domain_manager.hpp"
#include "random_seed_generation_manager.hpp"
#include "random_character_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
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
					excluded
			);

		template <typename Type> Type
			generate_character(
				const CharacterDomain&
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
						static_cast<Type>(0);
				}

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

				return
					filtered
						[
							distribution
							(
								RandomSeedGenerationManager
									::singleton
										.random_indeterministic_seed_engine
							)
						];
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
}

