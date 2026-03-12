#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	template <typename OutputType> struct
		ValueExtractorManagerConfigurations :
			AbstractConfigurations<ValueExtractorManagerConfigurations<OutputType>>
	{
	public:	
		std::function<OutputType()>
			callback =
				default_configurations
					.callback;

		static ValueExtractorManagerConfigurations<OutputType>
			initial_configurations;

		static ValueExtractorManagerConfigurations<OutputType>
			default_configurations;

		ValueExtractorManagerConfigurations();
	};

	template <typename OutputType>
		ValueExtractorManagerConfigurations<OutputType>
			::ValueExtractorManagerConfigurations() :
				AbstractConfigurations<ValueExtractorManagerConfigurations>()
	{
		callback =
			[]() { return OutputType{}; };
	}

	template <typename OutputType> ValueExtractorManagerConfigurations<OutputType>
		ValueExtractorManagerConfigurations<OutputType>
			::initial_configurations;

	template <typename OutputType> ValueExtractorManagerConfigurations<OutputType>
		ValueExtractorManagerConfigurations<OutputType>
			::default_configurations =
				ValueExtractorManagerConfigurations<OutputType>
					::initial_configurations;
}
