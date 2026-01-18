#include "pch.hpp"

#include "../includes/function_wrapper.hpp"

namespace
	QLogicaeCppCore
{    
    FunctionWrapper&
        FunctionWrapper
			::singleton =
				SingletonManager
					::get_singleton<FunctionWrapper>();



	FunctionWrapper
		::FunctionWrapper() :
			AbstractClass<FunctionWrapperConfigurations>()
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
			handle_error_outputs(
				exception
			);
		}		
	}
}

