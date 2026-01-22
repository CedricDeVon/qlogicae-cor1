#pragma once

#include "text_encoding.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TextEncodingManagerConfigurations :
			AbstractConfigurations<TextEncodingManagerConfigurations>
	{
	public:
		bool
			is_specified_length_enabled =
				default_configurations.is_specified_length_enabled;			

		size_t
			specified_length =
				default_configurations.specified_length;

		TextEncoding
			original_type =
				default_configurations.original_type;

		TextEncoding
			target_type =
				default_configurations.target_type;


		static TextEncodingManagerConfigurations
			initial_configurations;

		static TextEncodingManagerConfigurations
			default_configurations;
	};
}
