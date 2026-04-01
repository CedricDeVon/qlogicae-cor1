#pragma once

#include "text_encoding.hpp"
#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
