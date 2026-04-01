#pragma once

#include "abstract_enum.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
