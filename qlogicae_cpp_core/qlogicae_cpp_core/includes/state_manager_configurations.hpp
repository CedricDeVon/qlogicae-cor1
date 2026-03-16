#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		StateManagerConfigurations :
			AbstractConfigurations<StateManagerConfigurations>
	{
	public:
		static StateManagerConfigurations
			initial_configurations;

		static StateManagerConfigurations
			default_configurations;

		StateManagerConfigurations();
	};
}

