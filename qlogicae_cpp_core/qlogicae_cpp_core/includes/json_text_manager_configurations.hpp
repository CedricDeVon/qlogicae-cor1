#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		JsonTextManagerConfigurations :
			AbstractConfigurations<JsonTextManagerConfigurations>
    {
	public:
		std::string
			json_text =
				default_configurations
					.json_text;

		static JsonTextManagerConfigurations
			initial_configurations;

		static JsonTextManagerConfigurations
			default_configurations;

		JsonTextManagerConfigurations();
    };    
}
