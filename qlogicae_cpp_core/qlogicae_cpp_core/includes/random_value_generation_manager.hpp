#pragma once

#include "abstract_class.hpp"
#include "random_value_generation_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		RandomValueGenerationManager :
			public AbstractClass<RandomValueGenerationManagerConfigurations>
    {
    public:
		RandomValueGenerationManager();

		~RandomValueGenerationManager();

		bool
			construct();

		bool
			destruct();

		std::array<unsigned char, 16>
			generate_random_salt();

		bool
			generate_random_bytes(
				unsigned char*
					buffer,
				const size_t&
					size
			);	
	};
}
