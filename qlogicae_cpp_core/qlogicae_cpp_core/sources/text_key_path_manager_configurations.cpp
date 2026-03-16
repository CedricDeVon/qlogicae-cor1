#include "pch.hpp"

#include "../includes/text_key_path_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	TextKeyPathManagerConfigurations
		::TextKeyPathManagerConfigurations() :
			AbstractConfigurations<TextKeyPathManagerConfigurations>()
	{
		delimeter =
			".";	
	}

	TextKeyPathManagerConfigurations
		TextKeyPathManagerConfigurations
			::initial_configurations;

	TextKeyPathManagerConfigurations
		TextKeyPathManagerConfigurations
			::default_configurations =
				TextKeyPathManagerConfigurations
					::initial_configurations;
}
