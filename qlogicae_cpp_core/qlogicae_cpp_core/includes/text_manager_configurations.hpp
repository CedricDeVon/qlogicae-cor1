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
				",";

		bool
			is_specified_length_enabled =
				false;

		size_t
			specified_length =
				128;

		TextManagerConfigurations();
    };    
}

