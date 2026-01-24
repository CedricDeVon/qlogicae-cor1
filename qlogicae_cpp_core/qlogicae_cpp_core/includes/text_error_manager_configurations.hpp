#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TextErrorManagerConfigurations :
			AbstractConfigurations<TextErrorManagerConfigurations>
	{
	public:
		bool
			is_specified_length_enabled =
				default_configurations.is_specified_length_enabled;			

		size_t
			specified_length =
				default_configurations.specified_length;

		std::string
			title =
				default_configurations.title;
				
		std::string
			origin =
				default_configurations.origin;

		std::string
			separator =
				default_configurations.separator;



		static TextErrorManagerConfigurations
			initial_configurations;

		static TextErrorManagerConfigurations
			default_configurations;
	};
}

