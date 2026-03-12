#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_key_path_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		TextKeyPathManager :
			public AbstractClass<TextKeyPathManagerConfigurations>
    {
    public:		
        static TextKeyPathManager&
            singleton;

		TextKeyPathManager();

		std::vector<std::string>
			convert_key_path(
				const std::string&
					key_path,
				const std::string&
					delimeter
			);

		std::string
			convert_key_path(
				const std::vector<std::string>&
					key_path,
				const std::string&
					delimeter
			);

		std::vector<std::string>
			convert_key_path(
				const std::string&
					key_path
			);

		std::string
			convert_key_path(
				const std::vector<std::string>&
					key_path
			);
    };
}
