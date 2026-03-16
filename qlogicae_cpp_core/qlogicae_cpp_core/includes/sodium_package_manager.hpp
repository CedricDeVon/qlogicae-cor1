#pragma once

#include "abstract_class.hpp"
#include "sodium_package_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		SodiumPackageManager :
			public AbstractClass<SodiumPackageManagerConfigurations>
    {
    public:        
		SodiumPackageManager();

		bool
			setup();
    };
}
