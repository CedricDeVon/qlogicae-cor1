#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "random_seed_generation_manager.hpp"
#include "random_enum_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		RandomEnumGenerationManager :
			public AbstractClass<RandomEnumGenerationManagerConfigurations>
    {
    public:
		static RandomEnumGenerationManager&
			singleton;

		RandomEnumGenerationManager();

		template <typename Type> Type
			generate_enum(
				const Type&
					minimum,
				const Type&
					maximum,
				const std::unordered_set<Type>&
					excluded
			);

		template <typename Type> Type
			generate_enum(
				const Type&
					minimum,
				const Type&
					maximum
			);

		template <typename Type> Type
			generate_enum(
				const Type&
					maximum,
				const std::unordered_set<Type>&
					excluded
			);

		template <typename Type> Type
			generate_enum(
				const Type&
					maximum
			);

		template <typename Type> Type
			generate_enum(
				const std::unordered_set<Type>&
					excluded
			);

		template <typename Type> Type
			generate_enum();
	};

	template <typename Type> Type
		RandomEnumGenerationManager
			::generate_enum(
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
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					Type::NONE;
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

			std::optional<std::underlying_type_t<Type>>
				last =
					std::nullopt;

			std::underlying_type_t<Type> min_value =
				static_cast<std::underlying_type_t<Type>>(
					minimum
				);

			std::underlying_type_t<Type> max_value =
				static_cast<std::underlying_type_t<Type>>(
					maximum
				);

			std::underlying_type_t<Type> next;

			if (!last.has_value())
			{
				next = min_value;

			}
			else
			{
				next = last.value() + 1;

				if (next > max_value)
				{
					next = min_value;
				}
			}

			std::underlying_type_t<Type> start = next;

			do
			{
				Type candidate = static_cast<Type>(next);
				if (excluded.find(candidate) == excluded.end())
				{
					last = next;

					return
						candidate;
				}

				next++;

				if (next > max_value)
				{
					next = min_value;
				}

			}
			while
			(
				next != start
			); 

			return
				Type::NONE;
        }
        catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs<Type>(
				exception
			);

			return
				Type::NONE;
		}
	}    

	template <typename Type> Type
		RandomEnumGenerationManager
			::generate_enum(
				const Type&
					minimum,
				const Type&
					maximum
			)
    {
        return
			generate_enum<Type>(
				minimum,
				maximum,
				{}
			);
    }

    template <typename Type> Type
		RandomEnumGenerationManager
			::generate_enum(
				const Type&
					maximum,
				const std::unordered_set<Type>&
					excluded
			)
    {
        return
			generate_enum<Type>(
				static_cast<Type>(0),
				maximum,
				excluded
			);
    }

    template <typename Type> Type
		RandomEnumGenerationManager
			::generate_enum(
				const Type&
					maximum
			)
    {
        return
			generate_enum<Type>(
				static_cast<Type>(0),
				maximum,
				{}
			);
    }

    template <typename Type> Type
		RandomEnumGenerationManager
			::generate_enum(
				const std::unordered_set<Type>&
					excluded
			)
    {
        return
			generate_enum<Type>(
				static_cast<Type>(0),
				static_cast<Type>(Type::NONE),
				excluded
			);
    }

	template <typename Type> Type
		RandomEnumGenerationManager
			::generate_enum()
	{
		return
			generate_enum<Type>(
				static_cast<Type>(0),
				static_cast<Type>(Type::NONE),
				{}
			);
	}
}

