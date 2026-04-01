#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
