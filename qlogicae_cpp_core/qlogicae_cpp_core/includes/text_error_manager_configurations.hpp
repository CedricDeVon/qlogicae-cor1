#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
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

