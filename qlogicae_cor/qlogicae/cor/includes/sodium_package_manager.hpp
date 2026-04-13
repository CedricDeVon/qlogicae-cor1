#pragma once

#include "abstract_class.hpp"
#include "sodium_package_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		SodiumPackageManager :
			public QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<SodiumPackageManagerConfigurations>
    {
    public:        
		SodiumPackageManager();

		bool
			setup();
    };
}
