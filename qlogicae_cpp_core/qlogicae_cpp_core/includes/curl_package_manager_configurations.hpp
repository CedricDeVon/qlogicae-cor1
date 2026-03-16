#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		CurlPackageManagerConfigurations :
			AbstractConfigurations<CurlPackageManagerConfigurations>
	{
	public:		
		static CurlPackageManagerConfigurations
			initial_configurations;

		static CurlPackageManagerConfigurations
			default_configurations;

		CurlPackageManagerConfigurations();
	};
}
