#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
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
	};

	template <typename OutputType> ValueExtractorManagerConfigurations<OutputType>
		ValueExtractorManagerConfigurations<OutputType>
			::initial_configurations =
				[]()
				{
					ValueExtractorManagerConfigurations<OutputType>
						configurations;

					configurations
						.callback =
							[]() { return OutputType{}; };

					return
						configurations;
				}();

	template <typename OutputType> ValueExtractorManagerConfigurations<OutputType>
		ValueExtractorManagerConfigurations<OutputType>
			::default_configurations =
				ValueExtractorManagerConfigurations<OutputType>
					::initial_configurations;
}
