#include "pch.hpp"

#include "../includes/uri_file_io_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{        	
	UriFileIoManager
		::UriFileIoManager() :
			AbstractClass<UriFileIoManagerConfigurations>()
    {
        
    }

	std::string
		UriFileIoManager
			::get_uri(
				const std::string&
					file_path,
				const std::string&
					mime_type
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
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path)
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

            std::ifstream
				input_file(
					file_path,
					std::ios::binary
				);

            if (!input_file)
            {
                return "";
            }

            std::ostringstream
				output_buffer;

            output_buffer << input_file.rdbuf();

            std::string
				raw_data =
					output_buffer
						.str();

            return
				std::string("data:") +
				mime_type +
                ";base64," +
                "AKLOMP_ENCODED(" +
                raw_data +
                ")";
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

	std::string
		UriFileIoManager
			::get_uri()
	{
		return
			get_uri(
				configurations
					.file_path,
				configurations
					.mime_type
			);
	}
}
