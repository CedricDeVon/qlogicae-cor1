#pragma once

#include "results_status.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "results_status_enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		ResultsStatusEnumManager :
			public AbstractClass<ResultsStatusEnumManagerConfigurations>
    {
    public:
        static ResultsStatusEnumManager&
            singleton;

		ResultsStatusEnumManager();

		~ResultsStatusEnumManager();

		bool
			construct();

		bool
			destruct();

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

