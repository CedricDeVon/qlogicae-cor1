#pragma once

#include "file_entity.hpp"
#include "abstract_class.hpp"
#include "curl_package_manager.hpp"
#include "gmail_api_manager_response.hpp"
#include "gmail_api_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		GmailApiManager :
			public QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<GmailApiManagerConfigurations>
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
