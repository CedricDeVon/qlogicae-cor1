#pragma once

namespace
	QLogicae::Cor::V1
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
