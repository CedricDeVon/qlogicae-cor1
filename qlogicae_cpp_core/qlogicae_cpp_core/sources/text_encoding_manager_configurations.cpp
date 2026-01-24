#include "pch.hpp"

#include "../includes/text_encoding_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TextEncodingManagerConfigurations
		TextEncodingManagerConfigurations
			::initial_configurations =
				[]()
				{
					TextEncodingManagerConfigurations
						configurations;

					configurations
						.original_type =
							TextEncoding::NONE;

					configurations
						.target_type =
							TextEncoding::NONE;

					return
						configurations;
				}();

	TextEncodingManagerConfigurations
		TextEncodingManagerConfigurations
			::default_configurations =
				TextEncodingManagerConfigurations
					::initial_configurations;
}
