#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
