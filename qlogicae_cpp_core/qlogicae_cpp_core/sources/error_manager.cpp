#include "pch.hpp"

#include "../includes/error_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{            
	ErrorManager
		::ErrorManager()
	{
		construct();	
	}
	
	ErrorManager
		::~ErrorManager()
	{
		destruct();		
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
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
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
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
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
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
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
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
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
}

