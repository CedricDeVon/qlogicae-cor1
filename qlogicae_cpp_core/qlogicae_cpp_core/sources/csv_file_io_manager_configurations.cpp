#include "pch.hpp"

#include "../includes/csv_file_io_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	CsvFileIoManagerConfigurations
		::CsvFileIoManagerConfigurations() :
			AbstractConfigurations<CsvFileIoManagerConfigurations>()
	{
		file_path =
			"";

		delimeter =
			",";	
	}

	CsvFileIoManagerConfigurations
		CsvFileIoManagerConfigurations
			::initial_configurations;

	CsvFileIoManagerConfigurations
		CsvFileIoManagerConfigurations
			::default_configurations =
				CsvFileIoManagerConfigurations
					::initial_configurations;
}
