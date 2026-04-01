#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		TextErrorManagerConfigurations :
			AbstractConfigurations<TextErrorManagerConfigurations>
	{
	public:
		bool
			is_specified_length_enabled =
				false;			

		size_t
			specified_length =
				128;

		std::string
			title =
				"Exception";
				
		std::string
			origin =
				"";

		std::string
			separator =
				"-";

		TextErrorManagerConfigurations();
	};
}
