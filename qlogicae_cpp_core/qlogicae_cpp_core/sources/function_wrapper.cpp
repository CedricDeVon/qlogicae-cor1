#include "pch.hpp"

#include "../includes/function_wrapper.hpp"

namespace
	QLogicaeCppCore
{    
    FunctionWrapper&
        FunctionWrapper::singleton =
            SingletonManager::get_singleton<FunctionWrapper>();



	FunctionWrapper
		::FunctionWrapper()
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
			ErrorManager::singleton
				.handle_error_outputs(
					exception
				);
		}		
	}

	FunctionWrapper
		::~FunctionWrapper()
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
			ErrorManager::singleton
				.handle_error_outputs(
					exception
				);
		}		
	}

	bool
		FunctionWrapper
			::construct()
	{
		try
		{
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
				ErrorManager::singleton
					.handle_error_outputs(
						exception
				);
		}
	}

	bool
		FunctionWrapper
			::destruct()
	{
		try
		{
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
				ErrorManager::singleton
					.handle_error_outputs(
						exception
				);
		}
	}

	bool
		FunctionWrapper
			::setup(
				const FunctionWrapperConfigurations&
					new_configurations
			)
	{
		try
		{
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
				ErrorManager::singleton
					.handle_error_outputs(
						exception
				);
		}
	}

	bool
		FunctionWrapper
			::reset()
	{
		try
		{
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
				ErrorManager::singleton
					.handle_error_outputs(
						exception
				);
		}
	}
}

