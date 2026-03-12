#pragma once

#include "uuid.hpp"
#include "text_case.hpp"
#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_case_manager.hpp"
#include "uuid_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		UuidManager :
			public AbstractClass<UuidManagerConfigurations>
    {
    public:
		static UuidManager&
			singleton;

		UuidManager();

		bool
			is_valid(
				const Uuid&
					type,
				const std::string&
					value
			);

		bool
			is_valid(
				const std::string&
					value
			);

		std::string
			generate_uuid(
				const Uuid&
					type
			);

		std::string
			generate_uuid();
	};
}

