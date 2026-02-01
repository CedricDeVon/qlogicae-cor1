#include "pch.hpp"

#include "../includes/text_encoding_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{	
	TextEncodingManagerConfigurations
		::TextEncodingManagerConfigurations() :
			AbstractConfigurations<TextEncodingManagerConfigurations>()
	{
		original_type =
			TextEncoding::NONE;

		target_type =
			TextEncoding::NONE;
	}

	TextEncodingManagerConfigurations
		TextEncodingManagerConfigurations
			::initial_configurations;

	TextEncodingManagerConfigurations
		TextEncodingManagerConfigurations
			::default_configurations =
				TextEncodingManagerConfigurations
					::initial_configurations;
}
