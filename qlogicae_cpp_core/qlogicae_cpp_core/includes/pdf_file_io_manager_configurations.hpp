#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    struct
		PdfFileIoManagerConfigurations :
			AbstractConfigurations<PdfFileIoManagerConfigurations>
    {
	public:
		std::string
			file_path =
				"";

		PdfFileIoManagerConfigurations();
    };    
}
