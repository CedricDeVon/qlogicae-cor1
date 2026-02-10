#pragma once

#include "text_case.hpp"
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
		TextEncoding
			original_type =
				default_configurations
					.original_type;

		TextEncoding
			target_type =
				default_configurations
					.target_type;

		static TextEncodingManagerConfigurations
			initial_configurations;

		static TextEncodingManagerConfigurations
			default_configurations;

		TextEncodingManagerConfigurations();
	};
}
