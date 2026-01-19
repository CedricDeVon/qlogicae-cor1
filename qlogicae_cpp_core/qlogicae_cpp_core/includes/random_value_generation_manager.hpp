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

		static std::mt19937&
			generate_randomization_seed();

		RandomValueGenerationManager();

		~RandomValueGenerationManager();

		bool
			construct();

		bool
			destruct();

				
	};
}

/*
		std::string random_uuid4();


		std::string random_rgb_hex();


		std::string random_rgba_hex();

		std::array<unsigned char, 16> random_salt();

		void random_bytes(
			unsigned char* buffer,
			size_t size
		);

		bool random_bool(
			const double& = UTILITIES.RANDOM_BOOLEAN_MAXIMUM
		);

		std::string random_hex(
			const size_t&,
			const std::string_view & =
				UTILITIES.FULL_VISIBLE_ASCII_CHARACTERSET
		);

		std::string random_string(
			const size_t&,
			const std::string_view& =
				UTILITIES.FULL_VISIBLE_ASCII_CHARACTERSET
		);


		std::string random_base64(
			const size_t&,
			const std::string_view & =
				UTILITIES.FULL_VISIBLE_ASCII_CHARACTERSET
		);

		int random_int(
			const int& = std::numeric_limits<int>::min(),
			const int& = std::numeric_limits<int>::max()
		);

		double random_double(
			const double& = UTILITIES.RANDOM_DOUBLE_MINIMUM,
			const double& = UTILITIES.RANDOM_DOUBLE_MAXIMUM
		);

		

*/
 