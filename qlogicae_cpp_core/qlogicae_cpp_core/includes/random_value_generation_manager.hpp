#pragma once

#include "abstract_class.hpp"
#include "random_value_generation_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
