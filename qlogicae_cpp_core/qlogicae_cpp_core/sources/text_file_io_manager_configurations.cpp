#include "pch.hpp"

#include "../includes/text_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	TextFileIoManagerConfigurations
		::TextFileIoManagerConfigurations() :
			AbstractConfigurations<TextFileIoManagerConfigurations>()
	{
		file_path =
			"";
	}

	TextFileIoManagerConfigurations
		TextFileIoManagerConfigurations
			::initial_configurations;

	TextFileIoManagerConfigurations
		TextFileIoManagerConfigurations
			::default_configurations =
				TextFileIoManagerConfigurations
					::initial_configurations;
}
