#include "pch.hpp"

#include "../includes/regular_expression_manager.hpp"

namespace
	QLogicaeCppCore
{    
	RegularExpressionManager&
        RegularExpressionManager
			::singleton =
				SingletonManager
					::get_singleton<RegularExpressionManager>();



	RegularExpressionManager
		::RegularExpressionManager() :
			AbstractClass<RegularExpressionManagerConfigurations>()
    {
        try
        {
            construct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);
        }
    }

    RegularExpressionManager
		::~RegularExpressionManager()
    {
        try
        {
            destruct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);
        }
    }

    bool
        RegularExpressionManager
			::construct()
    {
        try
        {			
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
    }

    bool
        RegularExpressionManager
			::destruct()
    {
        try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
    }

	bool
		RegularExpressionManager
			::is_direct_pattern_matched(
				const std::string&
					value,
				const std::string&
					pattern
			)
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						value.empty() ||
						pattern.empty() 
					)
				)
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			int
				error_number;
			PCRE2_SIZE
				error_offset;

			pcre2_code*
				regular_expression =
					pcre2_compile(
						(PCRE2_SPTR)pattern.c_str(),
						PCRE2_ZERO_TERMINATED,
						0,
						&error_number,
						&error_offset,
						nullptr
					);

			if (!regular_expression)
			{
				return
					false;
			}

			bool
				result =
					is_pattern_matched(
						value,
						regular_expression
					);

			pcre2_code_free(
				regular_expression
			);

			return
				result;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		RegularExpressionManager
			::is_direct_pattern_matched(
				const std::string&
					value
			)
	{
		try
        {					
			return
				is_direct_pattern_matched(
					value,
					configurations.pattern
				);
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}

	bool
		RegularExpressionManager
			::is_pattern_matched(
				const std::string&
					value,
				pcre2_code*
					error_code
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						value.empty()
					)
				)
			)
			{
				return
					false;
			}

			pcre2_match_data*
				match_data =
					pcre2_match_data_create_from_pattern(
						error_code,
						nullptr
					);

			int
				result =
					pcre2_match(
						error_code,
						(PCRE2_SPTR)value.c_str(),
						value.length(),
						0,
						0,
						match_data,
						nullptr
					);

			pcre2_match_data_free(
				match_data
			);

			return
				result >= 0;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
	}
}
