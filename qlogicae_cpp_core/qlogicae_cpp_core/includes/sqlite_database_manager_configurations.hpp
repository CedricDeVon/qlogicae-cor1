#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		SQLiteDatabaseManagerConfigurations :
			AbstractConfigurations<SQLiteDatabaseManagerConfigurations>
	{
	public:		
		std::string
			file_path =
				"";

		SQLiteDatabaseManagerConfigurations();
	};
}
