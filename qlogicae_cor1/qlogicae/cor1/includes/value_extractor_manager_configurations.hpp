#pragma once

#include "abstract_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	template <typename OutputType> struct
		ValueExtractorManagerConfigurations :
			QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<ValueExtractorManagerConfigurations<OutputType>>
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
				QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CONFIGURATIONS_NAME<ValueExtractorManagerConfigurations>()
	{
		
	}
}
