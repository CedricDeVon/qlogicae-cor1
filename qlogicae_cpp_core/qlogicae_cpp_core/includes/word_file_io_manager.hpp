#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "word_file_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		WordFileIoManager :
			public AbstractClass<WordFileIoManagerConfigurations>
    {
    public:		
        static WordFileIoManager&
            singleton;

		WordFileIoManager();
    };
}
