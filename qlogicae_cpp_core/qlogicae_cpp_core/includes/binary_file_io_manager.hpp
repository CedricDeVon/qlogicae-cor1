#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "text_encoding_manager.hpp"
#include "binary_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		BinaryFileIoManager :
			public AbstractClass<BinaryFileIoManagerConfigurations>
    {
    public:		
        static BinaryFileIoManager&
            singleton;

		BinaryFileIoManager();

		std::vector<std::byte>
			read_raw_bytes(
				const std::string&
					file_path
			);

		bool
			write_raw_bytes(
				const std::string&
					file_path,
				const std::vector<std::byte>&
					text
			);

		bool
			append_raw_bytes(
				const std::string&
					file_path,
				const std::vector<std::byte>&
					text
			);

		std::string
			read_raw_text(
				const std::string&
					file_path
			);

		bool
			write_raw_text(
				const std::string&
					file_path,
				const std::string&
					text
			);

		bool
			append_raw_text(
				const std::string&
					file_path,
				const std::string&
					text
			);

		std::vector<std::byte>
			read_raw_bytes();

		bool
			write_raw_bytes(
				const std::vector<std::byte>&
					text
			);

		bool
			append_raw_bytes(
				const std::vector<std::byte>&
					text
			);

		std::string
			read_raw_text();

		bool
			write_raw_text(
				const std::string&
					text
			);

		bool
			append_raw_text(
				const std::string&
					text
			);
    };
}
