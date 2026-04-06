#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		TextKeyPathManagerConfigurations :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<TextKeyPathManagerConfigurations>
	{
	public:
		std::string
			delimeter =
				".";

		TextKeyPathManagerConfigurations();
	};
}
