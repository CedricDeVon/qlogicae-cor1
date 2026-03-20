#pragma once

#include "log_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    struct
		FileLogManagerConfigurations :
			LogManagerConfigurations<FileLogManagerConfigurations>
    {
	public:
		std::unordered_map<std::string, std::function<std::string()>>
			file_output_paths =
				{};

		FileLogManagerConfigurations();
    };
}
