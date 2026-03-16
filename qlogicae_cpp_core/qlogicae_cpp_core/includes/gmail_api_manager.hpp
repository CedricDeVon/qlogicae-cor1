#pragma once

#include "file_entity.hpp"
#include "abstract_class.hpp"
#include "gmail_api_manager_response.hpp"
#include "gmail_api_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		GmailApiManager :
			public AbstractClass<GmailApiManagerConfigurations>
    {
    public:
		GmailApiManager();

		~GmailApiManager();

		bool
			construct();

		bool
			destruct();

		GmailApiManagerResponse
			send_email();
	};
}
