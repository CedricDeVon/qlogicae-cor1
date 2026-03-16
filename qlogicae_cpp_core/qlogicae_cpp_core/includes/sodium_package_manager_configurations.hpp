#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		SodiumPackageManagerConfigurations :
			AbstractConfigurations<SodiumPackageManagerConfigurations>
	{
	public:		
		static SodiumPackageManagerConfigurations
			initial_configurations;

		static SodiumPackageManagerConfigurations
			default_configurations;

		SodiumPackageManagerConfigurations();
	};
}
