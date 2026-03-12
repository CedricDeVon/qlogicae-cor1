#include "pch.hpp"

#include "../includes/onnx_api_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	OnnxApiManagerConfigurations
		::OnnxApiManagerConfigurations() :
			AbstractConfigurations<OnnxApiManagerConfigurations>()
	{
		
	}

	OnnxApiManagerConfigurations
		OnnxApiManagerConfigurations
			::initial_configurations;

	OnnxApiManagerConfigurations
		OnnxApiManagerConfigurations
			::default_configurations =
				OnnxApiManagerConfigurations
					::initial_configurations;
}
