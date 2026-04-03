#include "pch.hpp"

#include "../includes/file_log_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{        	
	FileLogManager
		::FileLogManager() :
			AbstractClass<FileLogManagerConfigurations>()
    {
        
    }

	FileLogManager
		::~FileLogManager()
    {
        destruct();
    }
	
	bool
		FileLogManager
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
						feature_handling_mutex_1
					);
			}

			configurations
				.file_output_paths
					.clear();

			return
				true;
		}
		catch
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
		}
	}

	bool
		FileLogManager
			::reset()
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
						feature_handling_mutex_1
					);
			}

			configurations
				.file_output_paths
					.clear();

			return
				true;
		}
		catch
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
		}
	}

	std::string
		FileLogManager
			::get_file_output_path(
				const std::string&
					key
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
						key
							.empty() ||
						!configurations
							.file_output_paths
								.contains(key) ||
						configurations
							.file_output_paths
								[key] == nullptr
					)
				)
			)
			{
				return
					"";
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

			return
				configurations
					.file_output_paths
						[key]();
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {				
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
	}

	bool
		FileLogManager
			::is_file_output_path_found(
				const std::string&
					key
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
						key
							.empty()
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

			return
				configurations
					.file_output_paths
						.contains(key);
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {				
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
	}

	bool
		FileLogManager
			::set_file_output_path(
				const std::string&
					key,
				const std::function<std::string()>&
					value
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
						key
							.empty() ||
						value == nullptr
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

			configurations
				.file_output_paths
					[key] = value;

			return
				true;
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {				
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
	}

	bool
		FileLogManager
			::remove_file_output_path(
				const std::string&
					key
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
						key
							.empty() ||
						!configurations
							.file_output_paths
								.contains(key)
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

			configurations
				.file_output_paths
					.erase(key);

			return
				true;
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {				
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
	}

	bool
		FileLogManager
			::log_formatted_text(
				const std::string&
					text,
				const LogLevel&
					log_level
			)
	{
		return
			log_raw_text(
				SingletonManager
					::get_singleton<TextLogManager>()					
						.convert_text(
							text,
							log_level
						)
			);
	}

	bool
		FileLogManager
			::log_formatted_text(
				const std::string&
					text
			)
	{
		return
			log_formatted_text(
				text,
				configurations
					.log_level
			);
	}

	bool
		FileLogManager
			::log_formatted_text()
	{
		return
			log_formatted_text(
				configurations
					.text,
				configurations
					.log_level
			);
	}
	
	bool
		FileLogManager
			::log_raw_text(
				const std::string&
					text
			)
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
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

			for
			(
				const auto
					[key, callback] :
				configurations
					.file_output_paths
			)
			{				
				std::string file_path =
					callback();

				if (file_path.empty())
				{
					continue;
				}

				fast_io::io::print(
					fast_io::obuf_file(
						file_path
					),
					text
				);
			}

			return
				true;
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {				
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
	}

	bool
		FileLogManager
			::log_raw_text()
	{
		return
			log_raw_text(
				configurations
					.text
			);
	}
}
