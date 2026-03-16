#pragma once

namespace
	QLogicae::Cor::V1
{
	enum class
		EntityActivationStatus :
			uint8_t
	{
		ACTIVE,

		INACTIVE,

		PENDING,

		NONE
	};
}
