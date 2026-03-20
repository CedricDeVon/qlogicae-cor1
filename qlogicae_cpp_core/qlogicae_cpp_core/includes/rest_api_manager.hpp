#pragma once

#include "abstract_class.hpp"
#include "curl_package_manager.hpp"
#include "rest_api_manager_response.hpp"
#include "rest_api_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{    
    class
		RestApiManager :
			public AbstractClass<RestApiManagerConfigurations>
    {
    public:      
		std::vector<CURL*>
			curl_pool;

		size_t
			pool_next;

		boost::mutex
			feature_handling_mutex_2;

		boost::mutex
			feature_handling_mutex_3;

		RestApiManager();

		~RestApiManager();

		bool
			construct();

		bool
			destruct();

		RestApiManagerResponse
			execute_get_request(
				const std::string&
					path
			);

		RestApiManagerResponse
			execute_post_request(
				const std::string&
					path,
				const std::string&
					body
			);

		RestApiManagerResponse
			execute_put_request(
				const std::string&
					path,
				const std::string&
					body
			);

		RestApiManagerResponse
			execute_del_request(
				const std::string&
					path
			);

		RestApiManagerResponse
			execute_head_request(
				const std::string&
					path
			);

		RestApiManagerResponse
			execute_options_request(
				const std::string&
					path
			);

		RestApiManagerResponse
			execute_raw_request(
				const std::string&
					method,
				const std::string&
					path,
				const std::string&
					body
			);

		bool
			execute_request(
				RestApiManagerResponse&
					response,
				const std::string&
					method,
				const std::string&
					path,
				const std::string&
					body
			);

		CURL*
			acquire_handle();

		bool
			setup_telemetry(
				CURL*
					curl_handler,
				RestApiManagerResponse& 
					response
			);

		std::string
			setup_url(
				const std::string&
					base,
				const std::string&
					path
			);

		size_t
			write_cb(
				void*
					pointer,
				size_t
					size,
				size_t
					nmemb,
				void*
					userdata
			);

		size_t
			header_cb(
				void*
					pointer,
				size_t
					size,
				size_t
					nmemb,
				void*
					userdata
			);
    };    
}

