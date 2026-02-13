#pragma once

namespace
	QLogicaeCppCore
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
