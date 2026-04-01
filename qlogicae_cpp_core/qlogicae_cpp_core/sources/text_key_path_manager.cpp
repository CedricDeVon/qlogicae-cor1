#include "pch.hpp"

#include "../includes/text_key_path_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{        	
	TextKeyPathManager
		::TextKeyPathManager() :
			AbstractClass<TextKeyPathManagerConfigurations>()
    {
        
    }

	std::vector<std::string>
		TextKeyPathManager
			::convert_key_path(
				const std::string&
					key_path,
				const std::string&
					delimeter
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
						key_path.empty()
					)
				)
			)
			{
				return
					{};
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
				(delimeter != "") ?
					absl::StrSplit(
						key_path,
						delimeter
					) :
					std::vector<std::string> { key_path };
        }
        catch
        (
            const std::exception&
                exception
        )
        {				
			return
				handle_error_outputs<std::vector<std::string>>(
					exception
				);
        }
	}

	std::string
		TextKeyPathManager
			::convert_key_path(
				const std::vector<std::string>&
					key_path,
				const std::string&
					delimeter
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
						!key_path.size() ||
						delimeter.empty()
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
				absl::StrJoin(
					key_path,
					delimeter
				);
        }
        catch
        (
            const std::exception&
                exception
        )
        {				
			return
				handle_error_outputs<std::string>(
					exception
				);
        }
	}

	std::vector<std::string>
		TextKeyPathManager
			::convert_key_path(
				const std::string&
					key_path
			)
	{
		return
			convert_key_path(
				key_path,
				configurations
					.delimeter
			);
	}

	std::string
		TextKeyPathManager
			::convert_key_path(
				const std::vector<std::string>&
					key_path
			)
	{
		return
			convert_key_path(
				key_path,
				configurations
					.delimeter
			);
	}
}
