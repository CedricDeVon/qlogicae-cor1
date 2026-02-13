#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "random_value_generation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		RandomValueGenerationManager :
			public AbstractClass<RandomValueGenerationManagerConfigurations>
    {
    public:
		static RandomValueGenerationManager&
			singleton;

		RandomValueGenerationManager();

		~RandomValueGenerationManager();

		bool
			construct();

		bool
			destruct();

		std::mt19937&
			generate_random_seed();

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

/*

		std::string
			generate_uuid4();

		std::string
			generate_uuid6();

		std::string
			generate_rgb_hexadecimal();

		std::string
			generate_rgba_hexadecimal();


		bool
			generate_bool(
				const double&
					positive_ratio =
						0.5
		);

		template <typename Type> Type
			generate_text(
				const size_t&
					output_length,
				const Type&
					possible_characters
		);

		template <typename Type> Type
			generate_number(
				const int&
					inclusive_minimum =
						std::numeric_limits<Type>::min(),
				const int&
					inclusive_maximum =
						std::numeric_limits<Type>::max()
		);

*/ 