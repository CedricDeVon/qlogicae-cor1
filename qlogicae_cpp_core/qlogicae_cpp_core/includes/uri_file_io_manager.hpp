#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "uri_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		UriFileIoManager :
			public AbstractClass<UriFileIoManagerConfigurations>
    {
    public:		
        static UriFileIoManager&
            singleton;

		UriFileIoManager();
	
		std::string
			get_uri(
				const std::string&
					file_path,
				const std::string&
					mime_type
			);

		std::string
			get_uri();
    };
}
