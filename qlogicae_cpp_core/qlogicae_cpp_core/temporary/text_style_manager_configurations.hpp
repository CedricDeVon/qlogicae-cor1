#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TextStyleManagerConfigurations :
			AbstractConfigurations<TextStyleManagerConfigurations>
	{
	public:
		bool
			is_specified_length_enabled =
				default_configurations.is_specified_length_enabled;			

		size_t
			specified_length =
				default_configurations.specified_length;



		static TextStyleManagerConfigurations
			initial_configurations;

		static TextStyleManagerConfigurations
			default_configurations;
	};
}
