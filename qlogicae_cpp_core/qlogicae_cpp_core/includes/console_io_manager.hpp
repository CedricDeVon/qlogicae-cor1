#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "console_io_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
    class
		ConsoleIoManager :
			public AbstractClass<ConsoleIoManagerConfigurations>
    {
    public:
		static ConsoleIoManager&
			singleton;

		ConsoleIoManager();

		std::string
			scan();

		std::string
			builtin_scan();

		bool
			print(
				const std::string&
					text
			);

		bool
			builtin_print(
				const std::string&
					text
			);

		bool
			print_with_new_line(
				const std::string&
					text
			);

		bool
			builtin_print_with_new_line(
				const std::string&
					text
			);
	};
}

