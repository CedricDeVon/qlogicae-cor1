#include "pch.hpp"

#include "../includes/random_character_generation_manager.hpp"

namespace
	QLogicaeCppCore
{	
	RandomCharacterGenerationManager&
		RandomCharacterGenerationManager
			::singleton =
				SingletonManager
					::get_singleton<RandomCharacterGenerationManager>();



	RandomCharacterGenerationManager
		::RandomCharacterGenerationManager() :
			AbstractClass<RandomCharacterGenerationManagerConfigurations>()
	{
		
	}
}

