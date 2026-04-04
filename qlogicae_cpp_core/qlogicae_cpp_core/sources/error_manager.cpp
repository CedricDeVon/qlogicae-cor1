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
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
			);

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
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
			);

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
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
			);

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
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
			);

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
		QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__EDGE_CASE_GUARD_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
		);

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
		QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__EDGE_CASE_GUARD_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
		);

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
		QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__EDGE_CASE_GUARD_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_EDGE_CASES
		);

		return
			configurations.default_title +
			configurations.title_message_separator +
			exception.what();
	}
}

