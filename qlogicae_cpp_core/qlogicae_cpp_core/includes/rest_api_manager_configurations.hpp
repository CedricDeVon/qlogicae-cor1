#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	struct
		RestApiManagerConfigurations :
			AbstractConfigurations<RestApiManagerConfigurations>
	{
	public:	
		std::string
			base_url =
				"http://127.0.0.1";

		long 
			connect_timeout_seconds =
				30;
		long 
			request_timeout_seconds =
				30;

		bool 
			follow_redirects = 
				true;

		bool 
			enable_http2 =
				true;

		std::vector<std::string>
			default_headers =
				{};

		std::string
			bearer_token =
				"";

		std::string
			pinned_cert_file =
				"";

		std::string
			trusted_ca_bundle_file =
				"";

		bool 
			wait_forever =
				false;

		bool 
			suppress_exceptions =
				false;

		bool 
			capture_body =
				true;

		bool 
			capture_headers =
				true;

		bool 
			capture_telemetry =
				true;

		RestApiManagerConfigurations();
	};
}
