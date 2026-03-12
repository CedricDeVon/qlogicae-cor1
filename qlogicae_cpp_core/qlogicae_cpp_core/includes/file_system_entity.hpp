#pragma once

#include "abstract_enum.hpp"

namespace
	QLogicae::Cor::V1
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
