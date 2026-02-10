#include "pch.hpp"

#include "../includes/text_log_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{       
	TextLogManagerConfigurations
		::TextLogManagerConfigurations() :
			AbstractConfigurations<TextLogManagerConfigurations>()
	{
		
	}

	TextLogManagerConfigurations
		TextLogManagerConfigurations
			::initial_configurations;

	TextLogManagerConfigurations
		TextLogManagerConfigurations
			::default_configurations =
				TextLogManagerConfigurations
					::initial_configurations;
}
