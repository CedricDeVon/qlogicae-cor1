#pragma once

#include "text_case.hpp"
#include "text_encoding.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		TextEncodingManagerConfigurations :
			AbstractConfigurations<TextEncodingManagerConfigurations>
	{
	public:
		TextEncoding
			original_type =
				TextEncoding::NONE;

		TextEncoding
			target_type =
				TextEncoding::NONE;

		TextEncodingManagerConfigurations();
	};
}
