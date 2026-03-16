#pragma once

#include "abstract_class.hpp"
#include "curl_package_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		CurlPackageManager :
			public AbstractClass<CurlPackageManagerConfigurations>
    {
    public:        
		CurlPackageManager();

		bool
			setup();
    };
}
