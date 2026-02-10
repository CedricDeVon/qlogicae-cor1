#pragma once

#include "abstract_enum.hpp"

namespace
	QLogicaeCppCore
{
	enum class
		FileSystemEntity :
			uint8_t
	{
		ALL,

		FOLDER,
	
		FILE,

		NONE
	};
}
