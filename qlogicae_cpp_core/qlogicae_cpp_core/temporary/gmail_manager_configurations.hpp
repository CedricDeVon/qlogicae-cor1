#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		GmailManagerConfigurations :
			AbstractConfigurations<GmailManagerConfigurations>
	{
	public:
		static GmailManagerConfigurations
			initial_configurations;

		static GmailManagerConfigurations
			default_configurations;
	};
}
