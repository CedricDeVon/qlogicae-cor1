#include "pch.hpp"

#include "../includes/uri_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	UriFileIoManagerConfigurations
		::UriFileIoManagerConfigurations() :
			AbstractConfigurations<UriFileIoManagerConfigurations>()
	{
		file_path =
			"";
	
		mime_type =
			"application/octet-stream";
	}

	UriFileIoManagerConfigurations
		UriFileIoManagerConfigurations
			::initial_configurations;

	UriFileIoManagerConfigurations
		UriFileIoManagerConfigurations
			::default_configurations =
				UriFileIoManagerConfigurations
					::initial_configurations;
}
