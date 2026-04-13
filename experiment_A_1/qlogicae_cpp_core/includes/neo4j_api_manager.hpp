#pragma once

#include "abstract_class.hpp"
#include "neo4j_api_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		Neo4jApiManager :
			public QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<Neo4jApiManagerConfigurations>
    {
    public:
		Neo4jApiManager();
	};
}
