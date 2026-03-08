#include "pch.hpp"

#include "../includes/onnx_api_manager.hpp"

namespace
	QLogicaeCppCore
{        
	OnnxApiManager&
		OnnxApiManager
			::singleton = 
				SingletonManager
					::get_singleton<OnnxApiManager>();	


	
	OnnxApiManager
		::OnnxApiManager() :
			AbstractClass<OnnxApiManagerConfigurations>()
    {
        
    }
}
