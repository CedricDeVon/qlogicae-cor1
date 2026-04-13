#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		SQLiteDatabaseManagerConfigurations :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<SQLiteDatabaseManagerConfigurations>
	{
	public:		
		std::string
			file_path =
				"";

		SQLiteDatabaseManagerConfigurations();
	};
}
