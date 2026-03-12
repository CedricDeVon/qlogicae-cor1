#include "pch.hpp"

#include "../includes/binary_file_io_manager.hpp"

namespace
	QLogicae::Cor::V1
{        	
	BinaryFileIoManager
		::BinaryFileIoManager() :
			AbstractClass<BinaryFileIoManagerConfigurations>()
    {
        
    }

	std::vector<std::byte>
		BinaryFileIoManager
			::read_raw_bytes(
				const std::string&
					file_path
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

            fast_io::native_file_loader
				file_loader(
					file_path
				);

            auto
				span_bytes =
					std::as_bytes(
						std::span(
							file_loader.data(),
							file_loader.size()
						)
					);

            std::vector<std::byte> content(
                span_bytes.begin(),
                span_bytes.end()
            );

            return content;
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs<std::vector<std::byte>>(
					exception
				);
        }
	}

	bool
		BinaryFileIoManager
			::write_raw_bytes(
				const std::string&
					file_path,
				const std::vector<std::byte>&
					text
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
						!text.size()
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

			fast_io::obuf_file
				write_file(
					file_path
				);

			fast_io::write(
				write_file,
				text.begin(),
				text.end()
			);

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
		BinaryFileIoManager
			::append_raw_bytes(
				const std::string&
					file_path,
				const std::vector<std::byte>&
					text
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
						!text.size()
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

			fast_io::obuf_file
				append_file(
					file_path,
					fast_io::open_mode::app
				);

			fast_io::write(
				append_file,
				text.begin(),
				text.end()
			);

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

	std::vector<std::byte>
		BinaryFileIoManager
			::read_raw_bytes()
	{
		return
			read_raw_bytes(
				configurations
					.file_path
			);
	}

	bool
		BinaryFileIoManager
			::write_raw_bytes(
				const std::vector<std::byte>&
					text
			)
	{
		return
			write_raw_bytes(
				configurations
					.file_path,
				text
			);
	}

	bool
		BinaryFileIoManager
			::append_raw_bytes(
				const std::vector<std::byte>&
					text
			)
	{
		return
			append_raw_bytes(
				configurations
					.file_path,
				text
			);
	}

	std::string
		BinaryFileIoManager
			::read_raw_text(
				const std::string&
					file_path
			)
	{
		return
			SingletonManager
				::get_singleton<TextEncodingManager>()				
					.convert_bytes_to_string(
						read_raw_bytes(
							file_path
						)
					);
	}

	std::string
		BinaryFileIoManager
			::read_raw_text()
	{
		return
			SingletonManager
				::get_singleton<TextEncodingManager>()				
					.convert_bytes_to_string(
						read_raw_bytes(
							configurations
								.file_path
						)
					);
	}

	bool
		BinaryFileIoManager
			::write_raw_text(
				const std::string&
					file_path,
				const std::string&
					text
			)
	{
		return
			write_raw_bytes(
				file_path,
				SingletonManager
					::get_singleton<TextEncodingManager>()					
						.convert_string_to_bytes(
							text
						)
			);
	}

	bool
		BinaryFileIoManager
			::write_raw_text(
				const std::string&
					text
			)
	{
		return
			write_raw_bytes(
				configurations
					.file_path,
				SingletonManager
					::get_singleton<TextEncodingManager>()					
						.convert_string_to_bytes(
							text
						)
			);
	}

	bool
		BinaryFileIoManager
			::append_raw_text(
				const std::string&
					file_path,
				const std::string&
					text
			)
	{
		return
			append_raw_bytes(
				file_path,
				SingletonManager
					::get_singleton<TextEncodingManager>()					
						.convert_string_to_bytes(
							text
						)
			);
	}

	bool
		BinaryFileIoManager
			::append_raw_text(
				const std::string&
					text
			)
	{
		return
			append_raw_bytes(
				configurations
					.file_path,
				SingletonManager
					::get_singleton<TextEncodingManager>()					
						.convert_string_to_bytes(
							text
						)
			);
	}
}
