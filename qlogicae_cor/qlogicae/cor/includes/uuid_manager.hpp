#pragma once

#include "uuid.hpp"
#include "text_case.hpp"
#include "enum_manager.hpp"
#include "abstract_class.hpp"
#include "text_case_manager.hpp"
#include "uuid_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		UuidManager :
			public QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<UuidManagerConfigurations>
    {
    public:
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
