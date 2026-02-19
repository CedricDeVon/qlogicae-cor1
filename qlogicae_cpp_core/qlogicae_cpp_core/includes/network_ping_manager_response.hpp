#pragma once

namespace
	QLogicaeCppCore
{
	struct
		NetworkPingManagerResponse
	{
		double
			sent_duration;

		double
			receive_duration;

		double
			roundtrip_duration;
	};
}
