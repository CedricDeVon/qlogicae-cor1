#pragma once

#include "results_status.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "results_status_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		ResultsStatusEnumManager :
			public AbstractClass<ResultsStatusEnumManagerConfigurations>
    {
    public:
        static ResultsStatusEnumManager&
            singleton;

		ResultsStatusEnumManager();

		std::string
			convert_enum_to_string(
				const ResultsStatus&
					value
			);

		std::string
			convert_enum_to_string();

		ResultsStatus
			convert_string_to_enum(
				const std::string&
					value
			);

		ResultsStatus
			convert_string_to_enum();
    };
}

