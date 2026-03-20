#include "pch.hpp"

#include "../includes/binary_file_io_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	BinaryFileIoManagerConfigurations
		::BinaryFileIoManagerConfigurations() :
			AbstractConfigurations<BinaryFileIoManagerConfigurations>()
	{
		file_path =
			"";
	}
}
