#pragma once

#include "text_case.hpp"
#include "text_encoding.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
