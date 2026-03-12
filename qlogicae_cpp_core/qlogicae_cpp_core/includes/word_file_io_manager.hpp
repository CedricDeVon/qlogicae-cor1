#pragma once

#include "abstract_class.hpp"
#include "word_file_io_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		WordFileIoManager :
			public AbstractClass<WordFileIoManagerConfigurations>
    {
    public:		
		WordFileIoManager();
    };
}
