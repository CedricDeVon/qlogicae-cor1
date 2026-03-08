#include "pch.hpp"

#include "../includes/text_file_io_manager.hpp"

namespace
	QLogicaeCppCore
{        
	TextFileIoManager&
		TextFileIoManager
			::singleton = 
				SingletonManager
					::get_singleton<TextFileIoManager>();	


	
	TextFileIoManager
		::TextFileIoManager() :
			AbstractClass<TextFileIoManagerConfigurations>()
    {
        
    }

	
	std::string
		TextFileIoManager
			::read_text(
				const std::string
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

			fast_io::native_file_loader
				file_loader(
					file_path
				);

            return
				file_loader
					.data();
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

	bool
		TextFileIoManager
			::write_text(
				const std::string
					file_path,
				const std::string&
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
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						text.empty()
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
		TextFileIoManager
			::append_text(
				const std::string
					file_path,
				const std::string&
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
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						text.empty()
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

	std::string
		TextFileIoManager
			::get_text(
				const std::string
					file_path,
				const size_t&
					line_number
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
						std::filesystem::is_directory(file_path) ||
						line_number < 1
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

			fast_io::native_file_loader f(file_path);
			std::string_view content(f.data(), f.size());
			size_t i = 0;
			size_t pos = 0;
			while (pos < content.size()) {
				size_t end = content.find('\n', pos);
				if (end == std::string_view::npos) end = content.size();
				if (++i == line_number)
					return std::string(content.substr(pos, end - pos));
				pos = end + 1;
			}

            return
				"";
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

	bool
		TextFileIoManager
			::set_text(
				const std::string
					file_path,
				const std::string&
					text,
				const size_t&
					line_number
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
						std::filesystem::is_directory(file_path) ||
						line_number < 1
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

			std::vector<std::string> lines;
			{
				fast_io::native_file_loader f(file_path);
				std::string_view content(f.data(), f.size());
				size_t pos = 0;
				while (pos < content.size()) {
					size_t end = content.find('\n', pos);
					if (end == std::string_view::npos) end = content.size();
					lines.emplace_back(content.substr(pos, end - pos));
					pos = end + 1;
				}
			}
			if (line_number > lines.size()) return false;
			lines[line_number - 1] = text;
			fast_io::native_file o(file_path, fast_io::open_mode::out | fast_io::open_mode::trunc);
			for (auto& l : lines) fast_io::io::print(o, l, '\n');

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
		TextFileIoManager
			::insert_text(
				const std::string
					file_path,
				const std::string&
					text,
				const size_t&
					line_number
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
						std::filesystem::is_directory(file_path) ||
						line_number < 1
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

			std::vector<std::string> lines;
			{
				fast_io::native_file_loader f(file_path);
				std::string_view content(f.data(), f.size());
				size_t pos = 0;
				while (pos < content.size()) {
					size_t end = content.find('\n', pos);
					if (end == std::string_view::npos) end = content.size();
					lines.emplace_back(content.substr(pos, end - pos));
					pos = end + 1;
				}
			}
			if (line_number > lines.size() + 1) return false;
			lines.insert(lines.begin() + (line_number - 1), text);
			fast_io::native_file o(file_path, fast_io::open_mode::out | fast_io::open_mode::trunc);
			for (auto& l : lines) fast_io::io::print(o, l, '\n');

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
		TextFileIoManager
			::remove_text(
				const std::string
					file_path,
				const size_t&
					line_number
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
						std::filesystem::is_directory(file_path) ||
						line_number < 1
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

			std::vector<std::string> lines;
			{
				fast_io::native_file_loader f(file_path);
				std::string_view content(f.data(), f.size());
				size_t pos = 0;
				while (pos < content.size()) {
					size_t end = content.find('\n', pos);
					if (end == std::string_view::npos) end = content.size();
					lines.emplace_back(content.substr(pos, end - pos));
					pos = end + 1;
				}
			}
			if (line_number > lines.size()) return false;
			lines.erase(lines.begin() + (line_number - 1));
			fast_io::native_file o(file_path, fast_io::open_mode::out | fast_io::open_mode::trunc);
			for (auto& l : lines) fast_io::io::print(o, l, '\n');

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

	std::string
		TextFileIoManager
			::read_text()
	{
		return
			read_text(
				configurations
					.file_path
			);
	}

	bool
		TextFileIoManager
			::write_text(
				const std::string&
					text
			)
	{
		return
			write_text(
				configurations
					.file_path,
				text
			);
	}

	bool
		TextFileIoManager
			::append_text(
				const std::string&
					text
			)
	{
		return
			append_text(
				configurations
					.file_path,
				text
			);
	}

	std::string
		TextFileIoManager
			::get_text(
				const size_t&
					line_number
			)
	{
		return
			get_text(
				configurations
					.file_path,
				line_number
			);
	}

	bool
		TextFileIoManager
			::set_text(
				const std::string&
					text,
				const size_t&
					line_number
			)
	{
		return
			set_text(
				configurations
					.file_path,
				text,
				line_number
			);
	}

	bool
		TextFileIoManager
			::insert_text(
				const std::string&
					text,
				const size_t&
					line_number
			)
	{
		return
			insert_text(
				configurations
					.file_path,
				text,
				line_number
			);
	}

	bool
		TextFileIoManager
			::remove_text(
				const size_t&
					line_number
			)
	{
		return
			remove_text(
				configurations
					.file_path,
				line_number
			);
	}
}
