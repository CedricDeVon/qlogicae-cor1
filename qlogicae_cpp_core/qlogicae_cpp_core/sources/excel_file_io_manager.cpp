#include "pch.hpp"

#include "../includes/excel_file_io_manager.hpp"

namespace
	QLogicaeCppCore
{        
	ExcelFileIoManager&
		ExcelFileIoManager
			::singleton = 
				SingletonManager
					::get_singleton<ExcelFileIoManager>();	


	
	ExcelFileIoManager
		::ExcelFileIoManager() :
			AbstractClass<ExcelFileIoManagerConfigurations>()
    {
        
    }

	
	std::string
		ExcelFileIoManager
			::get_cell_value(
				const std::string&
					file_path,
				const std::string&
					worksheet_name,
				const std::string&
					column_name,
				const size_t&
					row_index
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
						worksheet_name.empty() ||
						column_name.empty() ||
						row_index < 0
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
		ExcelFileIoManager
			::set_cell_value(
				const std::string&
					file_path,
				const std::string&
					worksheet_name,
				const std::string&
					column_name,
				const size_t&
					row_index,
				const std::string&
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
						file_path.empty() ||
						!std::filesystem::exists(file_path) ||
						std::filesystem::is_directory(file_path) ||
						worksheet_name.empty() ||
						column_name.empty() ||
						row_index < 0
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
		ExcelFileIoManager
			::get_cell_value(
				const std::string&
					column_name,
				const size_t&
					row_index
			)
	{
		return
			get_cell_value(
				configurations
					.file_path,
				configurations
					.worksheet_name,
				column_name,
				row_index
			);
	}

	bool
		ExcelFileIoManager
			::set_cell_value(
				const std::string&
					column_name,
				const size_t&
					row_index,
				const std::string&
					value
			)
	{
		return
			set_cell_value(
				configurations
					.file_path,
				configurations
					.worksheet_name,
				column_name,
				row_index,
				value
			);
	}
}

/*

#pragma once

#include <string>
#include <vector>
#include <optional>
#include <future>
#include <unordered_map>
#include <cstdint>

namespace xint
{

	enum class ExcelCellType
	{
		Empty,
		String,
		Integer,
		Floating,
		Boolean,
		Error
	};

	enum class ExcelOpenMode
	{
		Create,
		OpenExisting,
		OpenOrCreate
	};

	struct ExcelCellPosition
	{
		std::size_t row;
		std::size_t column;
	};

	struct ExcelColumnInfo
	{
		std::size_t index;
		std::string name;
	};

	class ExcelDocument
	{
	public:

		ExcelDocument();

		explicit
		ExcelDocument(
			const std::string&
				file_path,
			const ExcelOpenMode&
				mode = ExcelOpenMode::OpenExisting
		);

		~ExcelDocument();

		ExcelDocument(
			const ExcelDocument&
		) = delete;

		ExcelDocument&
		operator=(
			const ExcelDocument&
		) = delete;

		ExcelDocument(
			ExcelDocument&&
		) noexcept;

		ExcelDocument&
		operator=(
			ExcelDocument&&
		) noexcept;

	public:

		bool
		open(
			const std::string&
				file_path,
			const ExcelOpenMode&
				mode = ExcelOpenMode::OpenExisting
		);

		bool
		save() const;

		bool
		save_as(
			const std::string&
				file_path
		) const;

		void
		close();

		bool
		is_open() const noexcept;

		std::string
		get_file_path() const;

	public:

		std::vector<std::string>
		get_worksheet_names() const;

		bool
		worksheet_exists(
			const std::string&
				worksheet_name
		) const;

		bool
		create_worksheet(
			const std::string&
				worksheet_name
		);

		bool
		delete_worksheet(
			const std::string&
				worksheet_name
		);

		bool
		rename_worksheet(
			const std::string&
				old_name,
			const std::string&
				new_name
		);

	public:

		std::size_t
		get_row_count(
			const std::string&
				worksheet_name
		) const;

		std::size_t
		get_column_count(
			const std::string&
				worksheet_name
		) const;

		std::vector<ExcelColumnInfo>
		get_columns(
			const std::string&
				worksheet_name
		) const;

		std::optional<std::size_t>
		get_column_index(
			const std::string&
				worksheet_name,
			const std::string&
				column_name
		) const;

	public:

		std::optional<std::string>
		get_cell_string(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				position
		) const;

		std::optional<std::string>
		get_cell_string(
			const std::string&
				worksheet_name,
			const std::string&
				column_name,
			const std::size_t&
				row_index
		) const;

		std::optional<std::int64_t>
		get_cell_integer(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				position
		) const;

		std::optional<double>
		get_cell_floating(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				position
		) const;

		std::optional<bool>
		get_cell_boolean(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				position
		) const;

		ExcelCellType
		get_cell_type(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				position
		) const;

	public:

		bool
		set_cell(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				position,
			const std::string&
				value
		);

		bool
		set_cell(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				position,
			const std::int64_t&
				value
		);

		bool
		set_cell(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				position,
			const double&
				value
		);

		bool
		set_cell(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				position,
			const bool&
				value
		);

		bool
		set_cell(
			const std::string&
				worksheet_name,
			const std::string&
				column_name,
			const std::size_t&
				row_index,
			const std::string&
				value
		);

	public:

		bool
		clear_cell(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				position
		);

		bool
		clear_row(
			const std::string&
				worksheet_name,
			const std::size_t&
				row_index
		);

		bool
		clear_column(
			const std::string&
				worksheet_name,
			const std::size_t&
				column_index
		);

	public:

		std::vector<std::vector<std::string>>
		read_range(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				top_left,
			const ExcelCellPosition&
				bottom_right
		) const;

		bool
		write_range(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				top_left,
			const std::vector<std::vector<std::string>>&
				data
		);

	public:

		std::unordered_map<std::string, std::string>
		read_row_as_map(
			const std::string&
				worksheet_name,
			const std::size_t&
				row_index
		) const;

		bool
		append_row(
			const std::string&
				worksheet_name,
			const std::vector<std::string>&
				values
		);

	public:

		std::future<std::optional<std::string>>
		get_cell_string_async(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				position
		) const;

		std::future<bool>
		set_cell_async(
			const std::string&
				worksheet_name,
			const ExcelCellPosition&
				position,
			const std::string&
				value
		);

		std::future<bool>
		save_async() const;

	private:

		void*
			internal_document;

		std::string
			current_file_path;

		bool
			document_open;
	};

}

*/ 
