#include "pch.hpp"

#include "../includes/error_manager.hpp"

namespace
	QLogicaeCppCore
{        
    ErrorManager&
        ErrorManager
			::singleton =
				ErrorManager
					::get_this_singleton();



	ErrorManager
		::ErrorManager()
	{
		try
		{
			construct();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);
		}		
	}
	
	ErrorManager
		::~ErrorManager()
	{
		try
		{
			destruct();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			handle_error_outputs(
				exception
			);
		}		
	}

	bool
		ErrorManager
			::construct()
	{
		try
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_override_enabled ||
				configurations
					.is_method_execution_thread_safety_enabled
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
						(
							method_handling_layer_mutex_1
						);
			}

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
		ErrorManager
			::destruct()
	{
		try
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_override_enabled ||
				configurations
					.is_method_execution_thread_safety_enabled
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
						(
							method_handling_layer_mutex_1
						);
			}

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
		ErrorManager
			::setup(
				const ErrorManagerConfigurations&
					new_configurations
			)
	{
		try
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_override_enabled ||
				configurations
					.is_method_execution_thread_safety_enabled
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
						(
							method_handling_layer_mutex_1
						);
			}

			configurations =
				new_configurations;

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
		ErrorManager
			::reset()
	{
		try
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_override_enabled ||
				configurations
					.is_method_execution_thread_safety_enabled
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
						(
							method_handling_layer_mutex_1
						);
			}

			configurations =
				{};

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
		ErrorManager
			::handle_error_outputs(
				const std::string&
					title,
				const std::string&
					message
			)
	{
		return
			handle_error_output_conditions(
				transform_to_error_log(
					title,
					message
				)
			);
	}
	
	bool
		ErrorManager
			::handle_error_outputs(
				const std::string&
					message
			)
	{
		return
			handle_error_output_conditions(
				transform_to_error_log(
					message
				)
			);
	}

	bool
		ErrorManager
			::handle_error_outputs(
				const std::exception&
					exception
			)
	{
		return
			handle_error_output_conditions(
				transform_to_error_log(
					exception
				)
			);
	}

	bool
		ErrorManager
			::handle_error_output_conditions(
				const std::string&
					error_log	
			)
	{
		if
		(
			configurations
				.is_asynchronous_output_enabled
		)
		{
			handle_error_outputs_asynchronously(
				error_log
			);
		}
		else
		{
			handle_error_outputs_synchronously(
				error_log
			);
		}

		return
			false;
	}

	std::string
		ErrorManager
			::transform_to_error_log(
				const std::string&
					title,
				const std::string&
					message
			)
	{
		return
			title +
			configurations.title_message_separator +
			message;
	}


	std::string
		ErrorManager
			::transform_to_error_log(
				const std::string&
					message
			)
	{
		return
			configurations.default_title +
			configurations.title_message_separator +
			message;
	}

	std::string
		ErrorManager
			::transform_to_error_log(
				const std::exception&
					exception
				)
	{
		return
			configurations.default_title +
			configurations.title_message_separator +
			exception.what();
	}

	bool
		ErrorManager
			::handle_error_outputs_synchronously(
				const std::string&
					error_log
			)
	{
		boost::unique_lock<boost::mutex>
			mutex_lock;
		if
		(
			configurations
				.is_thread_safety_override_enabled ||
			configurations
				.is_method_execution_thread_safety_enabled
		)
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					method_handling_layer_mutex_1
				);
		}

		if
		(
			configurations
				.is_enable_output_override_enabled ||
			configurations
				.is_console_output_enabled
		)
		{
			fast_io::io::println(
				fast_io::out(),
				error_log
			);
		}

		if
		(
			configurations
				.is_enable_output_override_enabled ||
			configurations
				.is_file_output_enabled
		)
		{		
			for
			(
				const std::string&
					full_file_output_path :
					configurations
	
						.full_file_output_paths
			)
			{
				if (!std::filesystem::exists(full_file_output_path))
				{
					continue;
				}

				fast_io::native_file
					fast_io_native_file(
						full_file_output_path,
						fast_io::open_mode::app
					);

				fast_io::io::println(
					fast_io_native_file,
					error_log
				);
			}
		}

		if
		(
			configurations
				.is_enable_output_override_enabled ||
			configurations
				.is_gui_output_enabled
		)
		{

		}

		if
		(
			configurations
				.is_enable_output_override_enabled ||
			configurations
				.is_runtime_throw_output_enabled
		)
		{
			throw
				std::runtime_error(
					error_log
				);
		}

		return
			false;
	}

	bool
		ErrorManager
			::handle_error_outputs_asynchronously(
				const std::string&
					error_log
			)
	{
		boost::unique_lock<boost::mutex>
			mutex_lock;
		if
		(
			configurations
				.is_thread_safety_override_enabled ||
			configurations
				.is_method_execution_thread_safety_enabled
		)
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					method_handling_layer_mutex_1
				);
		}

		std::vector<std::future<void>>
			futures;

		if
		(
			configurations
				.is_asynchronous_console_output_enabled &&
			(configurations
				.is_enable_output_override_enabled ||
			configurations
				.is_console_output_enabled)
		)
		{
			futures.push_back(
				std::async(
					std::launch::async,
					[&]()
					{
						fast_io::io::println(
							fast_io::out(),
							error_log
						);
					}
				)
			);
		}

		if
		(
			configurations
				.is_asynchronous_file_output_enabled &&
			(configurations
				.is_enable_output_override_enabled ||
			configurations
				.is_file_output_enabled)
		)
		{
			for
			(
				const std::string&
					full_file_output_path :
					configurations
	
						.full_file_output_paths
			)
			{
				if (!std::filesystem::exists(full_file_output_path))
				{
					continue;
				}

				futures.push_back(
					std::async(
						std::launch::async,
						[&]()
						{						
							fast_io::native_file
								fast_io_native_file(
									full_file_output_path,
									fast_io::open_mode::app
								);

							fast_io::io::println(
								fast_io_native_file,
								error_log
							);
						}
					)
				);
			}
		}

		if
		(
			configurations
				.is_asynchronous_runtime_throw_output_enabled &&
			(configurations
				.is_enable_output_override_enabled ||
			configurations
				.is_gui_output_enabled)
		)
		{
			futures.push_back(
				std::async(
					std::launch::async,
					[&]()
					{
						
					}
				)
			);
		}

		if
		(
			configurations
				.is_asynchronous_runtime_throw_output_enabled &&
			(configurations
				.is_enable_output_override_enabled ||
			configurations
				.is_runtime_throw_output_enabled)
		)
		{
			futures.push_back(
				std::async(
					std::launch::async,
					[&]()
					{
						throw
							std::runtime_error(
								error_log
							);
					}
				)
			);
		}

		for
		(
			std::future<void>&
				future :
				futures
		)
		{
			future.get();
		}

		return
			false;
	}	

	ErrorManager&
		ErrorManager
		::get_this_singleton()
	{
		static ErrorManager
			singleton;

		return
			singleton;
	}
}
