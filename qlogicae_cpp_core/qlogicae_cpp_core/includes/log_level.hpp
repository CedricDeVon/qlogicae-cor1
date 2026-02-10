#pragma once

namespace
	QLogicaeCppCore
{
    enum class
		LogLevel :
			uint8_t
    {
		ALL,

		INFO,

		DEBUG,

		WARNING,

		SUCCESS,

		CRITICAL,

		ERROR_TYPE,

		HIGHLIGHTED_INFO,

		NONE
    };
}
