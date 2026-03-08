#include "pch.hpp"

#include "../includes/word_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	WordFileIoManagerConfigurations
		::WordFileIoManagerConfigurations() :
			AbstractConfigurations<WordFileIoManagerConfigurations>()
	{
		
	}

	WordFileIoManagerConfigurations
		WordFileIoManagerConfigurations
			::initial_configurations;

	WordFileIoManagerConfigurations
		WordFileIoManagerConfigurations
			::default_configurations =
				WordFileIoManagerConfigurations
					::initial_configurations;
}
