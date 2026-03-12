#pragma once

namespace
	QLogicae::Cor::V1
{
	struct
		RestApiManagerResponse
	{
	public:	
		double
			total_timestamp_in_nanoseconds =
				0.0;

		double
			dns_timestamp_in_nanoseconds =
				0.0;

		double
			connect_timestamp_in_nanoseconds =
				0.0;

		double
			tls_timestamp_in_nanoseconds =
				0.0;

		double
			start_transfer_timestamp_in_nanoseconds =
				0.0;

		long int
			status_code =
				0;

		std::string
			body =
				"";

		std::multimap<std::string, std::string>
			headers =
				{};
	};
}
