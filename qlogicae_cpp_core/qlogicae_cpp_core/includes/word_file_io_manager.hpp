#pragma once

#include "abstract_class.hpp"
#include "word_file_io_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    class
		WordFileIoManager :
			public AbstractClass<WordFileIoManagerConfigurations>
    {
    public:		
		WordFileIoManager();
    };
}
