#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "rest_api_manager_response.hpp"
#include "rest_api_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    class
		RestApiManager :
			public AbstractClass<RestApiManagerConfigurations>
    {
    public:      
		std::vector<CURL*>
			curl_pool_;

		size_t
			pool_next_ { 0 };

		int
			failure_count_ { 0 };

		std::chrono::steady_clock::time_point
			last_failure_{};

		boost::mutex
			feature_handling_mutex_2;

		boost::mutex
			feature_handling_mutex_3;

        static RestApiManager&
            singleton;

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

		static size_t
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

		static size_t
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
    };    
}

