#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TextLogManagerConfigurations :
			AbstractConfigurations<TextLogManagerConfigurations>
	{
	public:
		bool
			is_specified_length_enabled =
				default_configurations.is_specified_length_enabled;			

		size_t
			specified_length =
				default_configurations.specified_length;

		

		static TextLogManagerConfigurations
			initial_configurations;

		static TextLogManagerConfigurations
			default_configurations;
	};
}
