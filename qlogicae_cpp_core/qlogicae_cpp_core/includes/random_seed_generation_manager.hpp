#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "random_seed_generation_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		RandomSeedGenerationManager :
			public AbstractClass<RandomSeedGenerationManagerConfigurations>
    {
    public:
		boost::mutex
			feature_handling_mutex_2;

		std::mt19937
			random_indeterministic_seed_engine;

		std::mt19937
			random_deterministic_seed_engine;

		std::mt19937
			random_cryptography_seed_engine;

		static RandomSeedGenerationManager&
			singleton;

		RandomSeedGenerationManager();

		~RandomSeedGenerationManager();

		bool
			construct();

		bool
			destruct();

		bool
			setup_indeterministic_seed();

		bool
			setup_deterministic_seed(
				const std::uint64_t&
					value
			);

		bool
			setup_cryptography_seed();

		uint64_t
			generate_indeterministic_seed();

		uint64_t
			generate_deterministic_seed(
				const std::uint64_t&
					value
			);

		uint64_t
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
