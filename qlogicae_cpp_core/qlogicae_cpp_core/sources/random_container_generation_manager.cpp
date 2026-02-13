#include "pch.hpp"

#include "../includes/random_container_generation_manager.hpp"

namespace
	QLogicaeCppCore
{	
	RandomContainerGenerationManager&
		RandomContainerGenerationManager
			::singleton =
				SingletonManager
					::get_singleton<RandomContainerGenerationManager>();



	RandomContainerGenerationManager
		::RandomContainerGenerationManager() :
			AbstractClass<RandomContainerGenerationManagerConfigurations>()
	{
		
	}
}
