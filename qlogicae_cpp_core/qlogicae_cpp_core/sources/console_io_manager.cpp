#include "pch.hpp"

#include "../includes/console_io_manager.hpp"

namespace
	QLogicaeCppCore
{
    ConsoleIoManager&
        ConsoleIoManager
			::singleton =
				SingletonManager
					::singleton
						.get_singleton<ConsoleIoManager>();



	ConsoleIoManager
		::ConsoleIoManager() :
			AbstractClass<ConsoleIoManagerConfigurations>()
	{

	}

	std::string
		ConsoleIoManager
			::scan()
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					"";
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			std::string
				output;

			std::getline(
				std::cin,
				output
			);
			
			if (!output.empty() && output.back() == '\r')
			{
				output.pop_back();
			}

			return
				output;
		}
		catch
		(
			const std::exception&
				exception
		)
		{			
			return
				handle_error_outputs<std::string>(
					exception
				);
		}
	}

	std::string
		ConsoleIoManager
			::builtin_scan()
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					"";
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			std::string output;
			std::cin >> output;

			return
				output;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs<std::string>(
					exception
				);
		}
	}

	bool
		ConsoleIoManager
			::print(
				const std::string&
					text
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			fast_io::io::print(
				fast_io::out(),
				text
			);

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs(
					exception
				);
		}
	}

	bool
		ConsoleIoManager
			::builtin_print(
				const std::string&
					text
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			std::cout << text;

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs(
					exception
				);
		}
	}

	bool
		ConsoleIoManager
			::print_with_new_line(
				const std::string&
					text
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			fast_io::io::println(
				fast_io::out(),
				text
			);

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs(
					exception
				);
		}
	}

	bool
		ConsoleIoManager
			::builtin_print_with_new_line(
				const std::string&
					text
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			std::cout << text << "\n";

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs(
					exception
				);
		}
	}
}
 