#include "pch.hpp"

#include "../includes/random_string_generation_manager.hpp"

namespace
	QLogicaeCppCore
{	
	RandomStringGenerationManager&
		RandomStringGenerationManager
			::singleton =
				SingletonManager
					::get_singleton<RandomStringGenerationManager>();



	RandomStringGenerationManager
		::RandomStringGenerationManager() :
			AbstractClass<RandomStringGenerationManagerConfigurations>()
	{
		
	}
}
