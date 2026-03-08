#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "excel_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		ExcelFileIoManager :
			public AbstractClass<ExcelFileIoManagerConfigurations>
    {
    public:		
        static ExcelFileIoManager&
            singleton;

		ExcelFileIoManager();

		std::string
			get_cell_value(
				const std::string&
					file_path,
				const std::string&
					worksheet_name,
				const std::string&
					column_name,
				const size_t&
					row_index
			);

		bool
			set_cell_value(
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
			);

		std::string
			get_cell_value(
				const std::string&
					column_name,
				const size_t&
					row_index
			);

		bool
			set_cell_value(
				const std::string&
					column_name,
				const size_t&
					row_index,
				const std::string&
					value
			);
    };
}
