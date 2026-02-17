#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
	struct
		RestApiManagerConfigurations :
			AbstractConfigurations<RestApiManagerConfigurations>
	{
	public:	
		std::string base_url;

		long connect_timeout_seconds = 10;

		long request_timeout_seconds = 30;

		int max_retries = 3;

		long retry_initial_delay_ms = 1000;

		bool follow_redirects = true;

		bool enable_http2 = true;

		std::vector<std::string> default_headers;

		std::string bearer_token;

		int circuit_breaker_threshold = 5;

		long circuit_breaker_cooldown_ms = 10000;

		std::string pinned_cert_file;

		std::string trusted_ca_bundle_file;

		std::function<void(const std::string&)> log_info;

		std::function<void(const std::string&)> log_error;

		bool wait_forever = false;

		bool suppress_exceptions = false;

		bool capture_body = true;

		bool capture_headers = true;

		bool capture_telemetry = true;

		bool default_idempotent = true;

		static RestApiManagerConfigurations
			initial_configurations;

		static RestApiManagerConfigurations
			default_configurations;

		RestApiManagerConfigurations();
	};
}

/*

std::string base_url;

long connect_timeout_seconds = 10;

long request_timeout_seconds = 30;

int max_retries = 3;

long retry_initial_delay_ms = 1000;

bool follow_redirects = true;

bool enable_http2 = true;

std::vector<std::string> default_headers;

std::string bearer_token;

int circuit_breaker_threshold = 5;

long circuit_breaker_cooldown_ms = 10000;

std::string pinned_cert_file;

std::string trusted_ca_bundle_file;

std::function<void(const std::string&)> log_info;

std::function<void(const std::string&)> log_error;

bool wait_forever = false;

bool suppress_exceptions = false;

bool capture_body = true;

bool capture_headers = true;

bool capture_telemetry = true;

bool default_idempotent = true;


*/ 
