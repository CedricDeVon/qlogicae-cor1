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
				[]() { return OutputType{}; };

		ValueExtractorManagerConfigurations();
	};

	template <typename OutputType>
		ValueExtractorManagerConfigurations<OutputType>
			::ValueExtractorManagerConfigurations() :
				AbstractConfigurations<ValueExtractorManagerConfigurations>()
	{
		
	}
}
