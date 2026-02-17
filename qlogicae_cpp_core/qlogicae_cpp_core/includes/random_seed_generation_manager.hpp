#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "random_seed_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		RandomSeedGenerationManager :
			public AbstractClass<RandomSeedGenerationManagerConfigurations>
    {
    public:
		boost::mutex
			feature_handling_mutex_2;

		static thread_local std::mt19937
			random_indeterministic_seed_engine;

		static thread_local std::mt19937
			random_deterministic_seed_engine;

		static thread_local std::mt19937
			random_cryptography_seed_engine;

		static RandomSeedGenerationManager&
			singleton;

		RandomSeedGenerationManager();

		~RandomSeedGenerationManager();

		bool
			construct();

		bool
			destruct();

		std::mt19937&
			generate_indeterministic_seed();

		std::mt19937&
			generate_deterministic_seed(
				const std::uint64_t&
					value
			);

		std::mt19937&
			generate_cryptography_seed();

		std::uint64_t
			mix_entropy();

		std::uint64_t
			mix_split_64(
				const std::uint64_t&
					value
			);
	};
}
