#include "pch.hpp"

#include "../includes/random_enum_generation_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	RandomEnumGenerationManagerConfigurations
		::RandomEnumGenerationManagerConfigurations() :
			AbstractConfigurations<RandomEnumGenerationManagerConfigurations>()
	{
		
	}

	RandomEnumGenerationManagerConfigurations
		RandomEnumGenerationManagerConfigurations
			::initial_configurations;

	RandomEnumGenerationManagerConfigurations
		RandomEnumGenerationManagerConfigurations
			::default_configurations =
				RandomEnumGenerationManagerConfigurations
					::initial_configurations;
}
