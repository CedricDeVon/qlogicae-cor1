#include "pch.hpp"

#include "../includes/gmail_api_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	GmailApiManagerConfigurations
		GmailApiManagerConfigurations
			::initial_configurations =
				[]()
				{
					GmailApiManagerConfigurations
						configurations;

					return
						configurations;
				}();

	GmailApiManagerConfigurations
		GmailApiManagerConfigurations
			::default_configurations =
				GmailApiManagerConfigurations
					::initial_configurations;
}
