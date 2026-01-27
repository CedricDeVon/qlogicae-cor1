#pragma once

#include "uuid.hpp"
#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "uuid_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		UuidManager :
			public AbstractClass<UuidManagerConfigurations>
    {
    public:
		static UuidManager&
			singleton;

		UuidManager();

		~UuidManager();

		bool
			construct();

		bool
			destruct();		

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
