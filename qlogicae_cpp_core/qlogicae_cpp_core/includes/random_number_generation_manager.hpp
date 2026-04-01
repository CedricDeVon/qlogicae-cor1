#pragma once

#include "abstract_class.hpp"
#include "random_seed_generation_manager.hpp"
#include "random_number_generation_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		RandomNumberGenerationManager :
			public AbstractClass<RandomNumberGenerationManagerConfigurations>
    {
    public:
		RandomNumberGenerationManager();

		template <typename Type = int> Type
			generate_number(
				const Type&
					minimum,
				const Type&
					maximum,
				const std::unordered_set<Type>&
					excluded
			);

		template <typename Type = int> Type
			generate_number(
				const Type&
					minimum,
				const Type&
					maximum
			);

		template <typename Type = int> Type
			generate_number(
				const Type&
					maximum,
				const std::unordered_set<Type>&
					excluded
			);

		template <typename Type = int> Type
			generate_number(
				const Type&
					maximum
			);

		template <typename Type = int> Type
			generate_number(
				const std::unordered_set<Type>&
					included
			);
	};

	template <typename Type> Type
        RandomNumberGenerationManager
            ::generate_number(
                const Type&
					minimum,
                const Type&
					maximum,
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
						minimum > maximum ||
						(minimum == 0 && maximum == 0)
					)
				)
			)
            {
                return
					minimum;
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

			const int maximum_attempt_limit = 1000;

            if constexpr (std::is_integral_v<Type>)
            {
                std::uniform_int_distribution<Type> distribution(minimum, maximum);
				for
				(
					size_t
						attempt_number = 0;
						attempt_number < maximum_attempt_limit;
						++attempt_number
				)
				{
					const Type candidate =
						distribution(SingletonManager::get_singleton<RandomSeedGenerationManager>()
										 .random_indeterministic_seed_engine);

					if (excluded.find(candidate) == excluded.end())
					{
						return
							candidate;
					}						
				}
				
				for
				(
					Type
						val = minimum;
						val <= maximum;
						++val
				)
				{
					if (excluded.find(val) == excluded.end())
					{
						return
							val;
					}						
				}

				return minimum;
            }
            else if constexpr (std::is_floating_point_v<Type>)
            {
				std::uniform_real_distribution<Type> distribution(minimum, maximum);
				constexpr Type epsilon = std::numeric_limits<Type>::epsilon();

				for
				(
					size_t
						attempt_number = 0;
						attempt_number < maximum_attempt_limit;
						++attempt_number
				)
				{
					const Type candidate =
						distribution(SingletonManager::get_singleton<RandomSeedGenerationManager>()
							.random_indeterministic_seed_engine);

					bool is_excluded = false;
					for
					(
						const auto&
							value :
							excluded
					)
					{
						if (std::fabs(candidate - value) <= epsilon)
						{
							is_excluded = true;
							break;
						}
					}

					if (!is_excluded)
					{
						return
							candidate;
					}
				}

				return
					minimum;
            }
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
        RandomNumberGenerationManager
            ::generate_number(
                const Type&
					minimum,
                const Type&
					maximum
            )
    {
        return
			generate_number<Type>(
				minimum,
				maximum,
				{}
			);
    }

    template <typename Type> Type
        RandomNumberGenerationManager
            ::generate_number(
                const Type&
					maximum,
                const std::unordered_set<Type>&
				excluded
			)
	{
		return
			generate_number<Type>(
				static_cast<Type>(0),
				maximum,
				excluded
			);
	}

	template <typename Type> Type
		RandomNumberGenerationManager
		::generate_number(
			const Type&
			maximum
		)
	{
		return
			generate_number<Type>(
				static_cast<Type>(0),
				maximum,
				{}
			);
	}

	template <typename Type> Type
		RandomNumberGenerationManager
		::generate_number(
			const std::unordered_set<Type>&
					included
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
						included.empty()
					)
				)
			)
			{
				return
					Type{};
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

			std::uniform_int_distribution<std::size_t> distribution(0, included.size() - 1);
			std::size_t index = distribution(SingletonManager::get_singleton<RandomSeedGenerationManager>().random_indeterministic_seed_engine);

			auto it = included.begin();
			std::advance(it, index);
			return *it;
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
}
