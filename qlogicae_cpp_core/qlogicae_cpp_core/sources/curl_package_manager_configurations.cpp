#include "pch.hpp"

#include "../includes/curl_package_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
	CurlPackageManagerConfigurations
		::CurlPackageManagerConfigurations() :
			AbstractConfigurations<CurlPackageManagerConfigurations>()
	{
		
	}

	CurlPackageManagerConfigurations
		CurlPackageManagerConfigurations
			::initial_configurations;

	CurlPackageManagerConfigurations
		CurlPackageManagerConfigurations
			::default_configurations =
				CurlPackageManagerConfigurations
					::initial_configurations;
}

