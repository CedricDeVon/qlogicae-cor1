#pragma once

#include "abstract_class.hpp"
#include "text_key_path_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		TextKeyPathManager :
			public QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<TextKeyPathManagerConfigurations>
    {
    public:		
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
