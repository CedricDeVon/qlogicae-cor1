#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "gmail_api_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		GmailApiManager :
			public AbstractClass<GmailApiManagerConfigurations>
    {
    public:
		static GmailApiManager&
			singleton;

		GmailApiManager();

		~GmailApiManager();

		bool
			construct();

		bool
			destruct();
	};
}
