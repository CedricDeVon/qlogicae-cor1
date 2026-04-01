#pragma once

#include "abstract_class.hpp"
#include "validation_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	class
		ValidationManager :
			public AbstractClass<ValidationManagerConfigurations>
	{
	public:
		ValidationManager();

		bool
			validate(
				const std::function<bool()>&
					conditional_callback
			);

		bool
			validate();
	};
}
