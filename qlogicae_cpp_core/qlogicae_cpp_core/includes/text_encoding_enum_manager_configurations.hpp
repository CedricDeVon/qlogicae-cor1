#pragma once

#include "text_encoding.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		TextEncodingEnumManagerConfigurations :
			AbstractConfigurations<TextEncodingEnumManagerConfigurations>
	{
	public:
		TextEncoding
			type =
				default_configurations
					.type;

		static TextEncodingEnumManagerConfigurations
			initial_configurations;

		static TextEncodingEnumManagerConfigurations
			default_configurations;

		TextEncodingEnumManagerConfigurations();
	};
}

