#include "pch.hpp"

#include "../includes/rest_api_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	RestApiManagerConfigurations
		::RestApiManagerConfigurations() :
			AbstractConfigurations<RestApiManagerConfigurations>()
	{
			base_url =
				"http://127.0.0.1";

			connect_timeout_seconds =
				30;

			request_timeout_seconds =
				30;

			follow_redirects = 
				true;

			enable_http2 =
				true;

			default_headers =
				{};

			bearer_token =
				"";

			pinned_cert_file =
				"";

			trusted_ca_bundle_file =
				"";

			wait_forever =
				false;

			suppress_exceptions =
				false;

			capture_body =
				true;

			capture_headers =
				true;

			capture_telemetry =
				true;
	}

	RestApiManagerConfigurations
		RestApiManagerConfigurations
			::initial_configurations;

	RestApiManagerConfigurations
		RestApiManagerConfigurations
			::default_configurations =
				RestApiManagerConfigurations
					::initial_configurations;
}
