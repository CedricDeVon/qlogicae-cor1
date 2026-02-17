#include "pch.hpp"

#include "../includes/random_number_generation_manager.hpp"

namespace
	QLogicaeCppCore
{	
	RandomNumberGenerationManager&
		RandomNumberGenerationManager
			::singleton =
				SingletonManager
					::get_singleton<RandomNumberGenerationManager>();



	RandomNumberGenerationManager
		::RandomNumberGenerationManager() :
			AbstractClass<RandomNumberGenerationManagerConfigurations>()
	{
		
	}
}

