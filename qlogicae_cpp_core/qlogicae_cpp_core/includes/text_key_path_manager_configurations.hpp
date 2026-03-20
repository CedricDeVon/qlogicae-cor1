#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		TextKeyPathManagerConfigurations :
			AbstractConfigurations<TextKeyPathManagerConfigurations>
	{
	public:
		std::string
			delimeter =
				".";

		TextKeyPathManagerConfigurations();
	};
}

