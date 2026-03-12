#pragma once

namespace
	QLogicae::Cor::V1
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
