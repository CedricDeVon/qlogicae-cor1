#include "pch.hpp"

#include "../includes/xml_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	XmlFileIoManagerConfigurations
		::XmlFileIoManagerConfigurations() :
			AbstractConfigurations<XmlFileIoManagerConfigurations>()
	{
		file_path =
			"";

		indentation_count =
			1;
	}

	XmlFileIoManagerConfigurations
		XmlFileIoManagerConfigurations
			::initial_configurations;

	XmlFileIoManagerConfigurations
		XmlFileIoManagerConfigurations
			::default_configurations =
				XmlFileIoManagerConfigurations
					::initial_configurations;
}
