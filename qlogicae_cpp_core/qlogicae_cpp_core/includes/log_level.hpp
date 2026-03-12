#pragma once

namespace
	QLogicae::Cor::V1
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
