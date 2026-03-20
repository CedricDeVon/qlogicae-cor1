#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		OnnxApiManagerConfigurations :
			AbstractConfigurations<OnnxApiManagerConfigurations>
    {
	public:
		std::string
			model_path =
				"";

		bool
			enable_cuda =
				false;

		int
			device_id =
				1;

		OnnxApiManagerConfigurations();
    };    
}
