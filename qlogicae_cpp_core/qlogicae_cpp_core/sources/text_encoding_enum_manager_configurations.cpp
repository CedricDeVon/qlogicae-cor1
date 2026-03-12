#include "pch.hpp"

#include "../includes/text_encoding_enum_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{   
	TextEncodingEnumManagerConfigurations
		::TextEncodingEnumManagerConfigurations() :
			AbstractConfigurations<TextEncodingEnumManagerConfigurations>()
	{
		type =
			TextEncoding
				::NONE;
	}

	TextEncodingEnumManagerConfigurations
		TextEncodingEnumManagerConfigurations
			::initial_configurations;

	TextEncodingEnumManagerConfigurations
		TextEncodingEnumManagerConfigurations
			::default_configurations =
				TextEncodingEnumManagerConfigurations
					::initial_configurations;
}
