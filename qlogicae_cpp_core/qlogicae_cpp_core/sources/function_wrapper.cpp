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

    }
}
