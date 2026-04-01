#pragma once

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	enum class
		ResultsStatus :
			uint8_t
	{
		GOOD,

		BAD,

		INFO,

		DEBUG,

		WARNING,

		EXCEPTION,

		ERROR_TYPE,

		NONE
	};
}
