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
				const size_t&
					line_number,
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
			std::ifstream input(file_path);
			std::string line;
			while (std::getline(input, line))
				lines.push_back(line);
			input.close();

			if (line_number > lines.size()) return false;
			lines[line_number - 1] = text;

			std::ofstream output(file_path, std::ios::binary | std::ios::trunc);
			for (const auto& l : lines)
				output << l << '\n';

			return true;
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
				const size_t&
					line_number,
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
			std::ifstream input(file_path);
			std::string line;
			while (std::getline(input, line))
				lines.push_back(line);
			input.close();

			if (line_number > lines.size() + 1) return false;
			lines.insert(lines.begin() + (line_number - 1), text);

			std::ofstream output(file_path, std::ios::binary | std::ios::trunc);
			for (const auto& l : lines)
				output << l << '\n';

			return true;
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
			std::ifstream input(file_path);
			std::string line;
			while (std::getline(input, line))
				lines.push_back(line);
			input.close();

			if (line_number > lines.size()) return false;
			lines.erase(lines.begin() + (line_number - 1));

			std::ofstream output(file_path, std::ios::binary | std::ios::trunc);
			for (const auto& l : lines)
				output << l << '\n';

			return true;
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
				const std::vector<std::string>&
					texts
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
						!texts.size()
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

			std::string
				output = "";

			fast_io::obuf_file
				file(
					file_path,		
					fast_io::open_mode::app
				);

			for (const std::string& text : texts)
			{
				output += text + "\n";				
			}

			fast_io::io::print(
				file,
				output
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

	std::unordered_map<size_t, std::string>
		TextFileIoManager
			::get_text(
				const std::string
					file_path,
				const std::vector<size_t>&
					line_numbers
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
						!line_numbers.size()
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

			std::unordered_map<size_t, std::string> result;
			std::unordered_set<size_t> targets(line_numbers.begin(), line_numbers.end());

			std::ifstream file(file_path);
			if (!file.is_open()) return {};

			std::string line;
			size_t index{ 1 };

			while (std::getline(file, line))
			{
				if (targets.contains(index))
				{
					result.emplace(index, line);
				}
				++index;
			}

			return result;
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs<std::unordered_map<size_t, std::string>>(
					exception
				);
        }
	}

	std::unordered_map<size_t, std::string>
		TextFileIoManager
			::get_text(
				const std::string
					file_path,
				const size_t&
					starting_line_number,
				const size_t&
					ending_line_number
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
						starting_line_number > ending_line_number ||
						ending_line_number < starting_line_number
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

			std::unordered_map<size_t, std::string> result;
			std::ifstream file(file_path);
			if (!file.is_open()) return {};

			std::string line;
			size_t index{ 1 };

			while (std::getline(file, line))
			{
				if (index >= starting_line_number && index <= ending_line_number)
				{
					result.emplace(index, line);
				}

				if (index > ending_line_number)
				{
					break;
				}

				++index;
			}

			return result;
        }
        catch
        (
			const std::exception&
                exception
        )
        {
            return
				handle_error_outputs<std::unordered_map<size_t, std::string>>(
					exception
				);
        }
	}

	bool
		TextFileIoManager
			::set_text(
				const std::string
					file_path,
				const std::unordered_map<size_t, std::string>&
					line_number_and_text
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
						!line_number_and_text.size()
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
			std::ifstream input(file_path);
			std::string line;
			while (std::getline(input, line))
				lines.push_back(line);
			input.close();

			for (const auto& [num, text] : line_number_and_text)
			{
				if (num == 0) continue;
				size_t index = num - 1;
				if (index < lines.size())
					lines[index] = text;
			}

			std::ofstream output(file_path, std::ios::binary | std::ios::trunc);
			for (const auto& l : lines)
				output << l << '\n';

			return true;
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
				const std::unordered_map<size_t, std::string>&
					line_number_and_text
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
						!line_number_and_text.size()
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
			std::ifstream input(file_path);
			std::string line;

			while (std::getline(input, line))
			{
				lines.push_back(line);
			}

			input.close();

			std::vector<std::pair<size_t, std::string>> entries(
				line_number_and_text.begin(),
				line_number_and_text.end()
			);

			std::sort(
				entries.begin(),
				entries.end(),
				[](const auto& a, const auto& b)
				{
					return a.first < b.first;
				}
			);

			std::vector<std::string> result;

			size_t entry_index = 0;

			for (size_t i = 0; i < lines.size(); ++i)
			{
				size_t current_line = i + 1;

				while
					(
						entry_index < entries.size() &&
						entries[entry_index].first == current_line
						)
				{
					result.push_back(entries[entry_index].second);
					entry_index++;
				}

				result.push_back(lines[i]);
			}

			while (entry_index < entries.size())
			{
				result.push_back(entries[entry_index].second);
				entry_index++;
			}

			std::ofstream output(file_path, std::ios::binary | std::ios::trunc);

			for (const auto& l : result)
			{
				output << l << '\n';
			}

			return true;
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
				const std::vector<size_t>&
					line_numbers
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
						!line_numbers.size()
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
			std::ifstream input(file_path);
			std::string line;
			while (std::getline(input, line))
				lines.push_back(line);
			input.close();

			std::vector<size_t> indices(line_numbers.begin(), line_numbers.end());
			std::sort(indices.begin(), indices.end(), std::greater<size_t>());

			for (size_t num : indices)
			{
				if (num == 0) continue;
				size_t index = num - 1;
				if (index < lines.size())
					lines.erase(lines.begin() + index);
			}

			std::ofstream output(file_path, std::ios::binary | std::ios::trunc);
			for (const auto& l : lines)
				output << l << '\n';

			return true;
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
				const size_t&
					line_number,
				const std::string&
					text
			)
	{
		return
			set_text(
				configurations
					.file_path,
				line_number,
				text
			);
	}

	bool
		TextFileIoManager
			::insert_text(
				const size_t&
					line_number,
				const std::string&
					text
			)
	{
		return
			insert_text(
				configurations
					.file_path,
				line_number,
				text
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

	bool
		TextFileIoManager
			::append_text(
				const std::vector<std::string>&
					texts
			)
	{
		return
			append_text(
				configurations
					.file_path,
				texts
			);
	}

	std::unordered_map<size_t, std::string>
		TextFileIoManager
			::get_text(
				const std::vector<size_t>&
					line_numbers
			)
	{
		return
			get_text(
				configurations
					.file_path,
				line_numbers
			);
	}

	std::unordered_map<size_t, std::string>
		TextFileIoManager
			::get_text(
				const size_t&
					starting_line_number,
				const size_t&
					ending_line_number
			)
	{
		return
			get_text(
				configurations
					.file_path,
				starting_line_number,
				ending_line_number
			);
	}

	bool
		TextFileIoManager
			::set_text(
				const std::unordered_map<size_t, std::string>&
					line_number_and_text
			)
	{
		return
			set_text(
				configurations
					.file_path,
				line_number_and_text
			);
	}

	bool
		TextFileIoManager
			::insert_text(
				const std::unordered_map<size_t, std::string>&
					line_number_and_text
			)
	{
		return
			insert_text(
				configurations
					.file_path,
				line_number_and_text
			);
	}

	bool
		TextFileIoManager
			::remove_text(
				const std::vector<size_t>&
					line_numbers
			)
	{
		return
			remove_text(
				configurations
					.file_path,
				line_numbers
			);
	}
}
