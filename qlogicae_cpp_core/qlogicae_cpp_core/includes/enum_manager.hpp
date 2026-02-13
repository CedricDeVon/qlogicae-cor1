#pragma once

#include "text_case.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_case_manager.hpp"
#include "enum_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		EnumManager :
			public AbstractClass<EnumManagerConfigurations>
    {
    public:
        static EnumManager&
            singleton;

		EnumManager();

		std::string
			convert_enum_string(
				const std::string&
					value,
				const TextCase&
					original_text_case,
				const TextCase&
					target_text_case
			);

		std::string
			convert_enum_string(
				const std::string&
					value,
				const TextCase&
					original_text_case
			);

		std::string
			convert_enum_string(
				const std::string&
					value
			);

		std::string
			convert_default_enum_string(
				const std::string&
					value
			);

		std::string
			get_none_string(
				const TextCase&
					text_case
			);

		std::string
			get_none_string();
    };
}

