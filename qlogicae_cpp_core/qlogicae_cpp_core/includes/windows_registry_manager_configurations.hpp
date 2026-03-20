#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		WindowsRegistryManagerConfigurations :
			AbstractConfigurations<WindowsRegistryManagerConfigurations>
	{
	public:	
		HKEY
			root_key =
				HKEY_CURRENT_USER;

		std::wstring
			sub_key =
				L"Software\\App";

		std::wstring
			name_key =
				L"Data";

		WindowsRegistryManagerConfigurations();
	};
}
