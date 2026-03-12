#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "validation_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	class
		ValidationManager :
			public AbstractClass<ValidationManagerConfigurations>
	{
	public:
		static ValidationManager&
			singleton;

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
