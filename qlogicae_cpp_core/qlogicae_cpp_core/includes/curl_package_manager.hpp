#pragma once

#include "abstract_class.hpp"
#include "curl_package_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
