#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	struct
		RestApiManagerConfigurations :
			AbstractConfigurations<RestApiManagerConfigurations>
	{
	public:	
		std::string
			base_url;

		long 
			connect_timeout_seconds =
				default_configurations
					.connect_timeout_seconds;

		long 
			request_timeout_seconds =
				default_configurations
					.request_timeout_seconds;

		bool 
			follow_redirects =
				default_configurations
					.follow_redirects;

		bool 
			enable_http2 =
				default_configurations
					.enable_http2;

		std::vector<std::string>
			default_headers =
				default_configurations
					.default_headers;

		std::string
			bearer_token =
				default_configurations
					.bearer_token;

		std::string
			pinned_cert_file =
				default_configurations
					.pinned_cert_file;

		std::string
			trusted_ca_bundle_file =
				default_configurations
					.trusted_ca_bundle_file;

		bool 
			wait_forever =
				default_configurations
					.wait_forever;

		bool 
			suppress_exceptions =
				default_configurations
					.suppress_exceptions;

		bool 
			capture_body =
				default_configurations
					.capture_body;

		bool 
			capture_headers =
				default_configurations
					.capture_headers;

		bool 
			capture_telemetry =
				default_configurations
					.capture_telemetry;

		static RestApiManagerConfigurations
			initial_configurations;

		static RestApiManagerConfigurations
			default_configurations;

		RestApiManagerConfigurations();
	};
}
