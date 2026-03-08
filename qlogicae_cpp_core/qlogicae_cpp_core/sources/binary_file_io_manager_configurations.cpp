#include "pch.hpp"

#include "../includes/binary_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	BinaryFileIoManagerConfigurations
		::BinaryFileIoManagerConfigurations() :
			AbstractConfigurations<BinaryFileIoManagerConfigurations>()
	{
		file_path =
			"";
	}

	BinaryFileIoManagerConfigurations
		BinaryFileIoManagerConfigurations
			::initial_configurations;

	BinaryFileIoManagerConfigurations
		BinaryFileIoManagerConfigurations
			::default_configurations =
				BinaryFileIoManagerConfigurations
					::initial_configurations;
}
