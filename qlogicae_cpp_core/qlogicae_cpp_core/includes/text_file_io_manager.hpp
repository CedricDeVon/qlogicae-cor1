#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		TextFileIoManager :
			public AbstractClass<TextFileIoManagerConfigurations>
    {
    public:		
        static TextFileIoManager&
            singleton;

		TextFileIoManager();

		std::string
			read_text(
				const std::string
					file_path
			);

		bool
			write_text(
				const std::string
					file_path,
				const std::string&
					text
			);

		bool
			append_text(
				const std::string
					file_path,
				const std::string&
					text
			);

		std::string
			get_text(
				const std::string
					file_path,
				const size_t&
					line_number
			);

		bool
			set_text(
				const std::string
					file_path,
				const std::string&
					text,
				const size_t&
					line_number
			);

		bool
			insert_text(
				const std::string
					file_path,
				const std::string&
					text,
				const size_t&
					line_number
			);

		bool
			remove_text(
				const std::string
					file_path,
				const size_t&
					line_number
			);



		std::string
			read_text();

		bool
			write_text(
				const std::string&
					text
			);

		bool
			append_text(
				const std::string&
					text
			);

		std::string
			get_text(
				const size_t&
					line_number
			);

		bool
			set_text(
				const std::string&
					text,
				const size_t&
					line_number
			);

		bool
			insert_text(
				const std::string&
					text,
				const size_t&
					line_number
			);

		bool
			remove_text(
				const size_t&
					line_number
			);
    };
}
