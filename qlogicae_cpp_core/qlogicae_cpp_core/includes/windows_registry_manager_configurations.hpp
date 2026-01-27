#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		WindowsRegistryManagerConfigurations :
			AbstractConfigurations<WindowsRegistryManagerConfigurations>
	{
	public:	
		HKEY
			root_key =
				default_configurations
					.root_key;

		std::wstring
			sub_key =
				default_configurations
					.sub_key;

		std::wstring
			name_key =
				default_configurations
					.name_key;



		static WindowsRegistryManagerConfigurations
			initial_configurations;

		static WindowsRegistryManagerConfigurations
			default_configurations;
	};
}
