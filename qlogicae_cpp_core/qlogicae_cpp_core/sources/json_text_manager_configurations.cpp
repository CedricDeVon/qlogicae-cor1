#include "pch.hpp"

#include "../includes/json_text_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	JsonTextManagerConfigurations
		::JsonTextManagerConfigurations() :
			AbstractConfigurations<JsonTextManagerConfigurations>()
	{
		json_text =
			"";
	}

	JsonTextManagerConfigurations
		JsonTextManagerConfigurations
			::initial_configurations;

	JsonTextManagerConfigurations
		JsonTextManagerConfigurations
			::default_configurations =
				JsonTextManagerConfigurations
					::initial_configurations;
}
