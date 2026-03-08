#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		JsonTextManagerConfigurations :
			AbstractConfigurations<JsonTextManagerConfigurations>
    {
	public:
		std::string
			file_path =
				default_configurations
					.file_path;

		static JsonTextManagerConfigurations
			initial_configurations;

		static JsonTextManagerConfigurations
			default_configurations;

		JsonTextManagerConfigurations();
    };    
}
