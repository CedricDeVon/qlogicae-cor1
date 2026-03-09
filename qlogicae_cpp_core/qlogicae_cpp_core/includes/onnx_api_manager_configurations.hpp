#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		OnnxApiManagerConfigurations :
			AbstractConfigurations<OnnxApiManagerConfigurations>
    {
	public:
		std::string
			model_path =
				default_configurations
					.model_path;

		bool
			enable_cuda =
				default_configurations
					.enable_cuda;

		int
			device_id =
				default_configurations
					.device_id;

		static OnnxApiManagerConfigurations
			initial_configurations;

		static OnnxApiManagerConfigurations
			default_configurations;

		OnnxApiManagerConfigurations();
    };    
}
