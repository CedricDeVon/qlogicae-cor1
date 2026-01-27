#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    struct
		GmailApiManagerConfigurations :
			AbstractConfigurations<GmailApiManagerConfigurations>
    {
	public:			
		static GmailApiManagerConfigurations
			initial_configurations;

		static GmailApiManagerConfigurations
			default_configurations;
    };
}
