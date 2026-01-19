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

        EXCEPTION,

        HIGHLIGHTED_INFO,

		NONE
    };
}
