#pragma once

#include "abstract_class.hpp"
#include "value_extractor_manager_configurations.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	template <typename OutputType> class
		ValueExtractorManager :
			public AbstractClass<ValueExtractorManagerConfigurations<OutputType>>
	{
	public:
		ValueExtractorManager();

		OutputType
			execute();
	};

	template <typename OutputType> OutputType
		ValueExtractorManager<OutputType>
			::execute()
	{
		try
		{
			if
			(
				this->configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					OutputType{};
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (this->configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						this->feature_handling_mutex_1
					);
			}

			return
				(this->configurations.callback == nullptr) ?
					OutputType{} :
					this->configurations
						.callback();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			this->handle_error_outputs(
				exception
			);

			return
				OutputType{};
		}
	}

	template <typename OutputType>
		ValueExtractorManager<OutputType>
			::ValueExtractorManager() :
				AbstractClass<ValueExtractorManagerConfigurations<OutputType>>()
	{
		
	}
}
