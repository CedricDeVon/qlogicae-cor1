#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    struct
		TextManagerConfigurations :
			AbstractConfigurations<TextManagerConfigurations>
    {
	public:
		std::unordered_map<std::string, std::string>
			replace_text_tokens_dictionary =
				{}; // NOTE: Using the 'default_configurations.' strategy will result in google unit test crashes

		std::string
			split_text_delimeter = 
				default_configurations
					.split_text_delimeter;

		bool
			is_specified_length_enabled =
				default_configurations
					.is_specified_length_enabled;

		size_t
			specified_length =
				default_configurations
					.specified_length;

		static TextManagerConfigurations
			initial_configurations;

		static TextManagerConfigurations
			default_configurations;

		TextManagerConfigurations();
    };    
}

