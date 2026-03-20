#pragma once

#include "text_encoding.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		TextEncodingEnumManagerConfigurations :
			AbstractConfigurations<TextEncodingEnumManagerConfigurations>
	{
	public:
		TextEncoding
			type =
				TextEncoding
					::NONE;

		TextEncodingEnumManagerConfigurations();
	};
}

