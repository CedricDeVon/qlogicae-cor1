#include "pch.hpp"

#include "../includes/random_enum_generation_manager.hpp"

namespace
	QLogicaeCppCore
{	
	RandomEnumGenerationManager&
		RandomEnumGenerationManager
			::singleton =
				SingletonManager
					::get_singleton<RandomEnumGenerationManager>();



	RandomEnumGenerationManager
		::RandomEnumGenerationManager() :
			AbstractClass<RandomEnumGenerationManagerConfigurations>()
	{
		
	}
}
