#pragma once

namespace
	QLogicaeCppCore
{
    struct
		NetworkPingManagerResponse
    {
		int64_t
			round_trip_time_in_milliseconds =
				default_configurations
					.round_trip_time_in_milliseconds;

		static NetworkPingManagerResponse
			initial_configurations;

		static NetworkPingManagerResponse
			default_configurations;

		NetworkPingManagerResponse();
    };
}
