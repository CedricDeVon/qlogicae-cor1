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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_utility_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
						(
							feature_handling_mutex_1
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_utility_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
						(
							feature_handling_mutex_1
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_utility_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
						(
							feature_handling_mutex_1
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_utility_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
						(
							feature_handling_mutex_1
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

	std::string
		ErrorManager
			::transform_to_error_log(
				const std::string&
					title,
				const std::string&
					message
			)
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
		if
		(
			configurations
				.is_runtime_execution_disabled_for_feature_handling()
		)
		{
			return
				"";
		}

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
		if
		(
			configurations
				.is_runtime_execution_disabled_for_feature_handling()
		)
		{
			return
				"";
		}

		return
			configurations.default_title +
			configurations.title_message_separator +
			exception.what();
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
