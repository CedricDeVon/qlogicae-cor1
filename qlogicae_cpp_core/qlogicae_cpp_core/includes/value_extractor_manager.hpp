#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "value_extractor_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	template <typename OutputType> class
		ValueExtractorManager :
			public AbstractClass<ValueExtractorManagerConfigurations<OutputType>>
	{
	public:
		ValueExtractorManager();

		~ValueExtractorManager();

		bool
			construct();

		bool
			destruct();

		OutputType
			execute();
	};

	template <typename OutputType> OutputType
		ValueExtractorManager<OutputType>
			::execute()
	{
		try
		{
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
		try
		{
			construct();
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
		}
	}

	template <typename OutputType>
		ValueExtractorManager<OutputType>
			::~ValueExtractorManager()
	{
		try
		{
			destruct();
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
		}
	}

	template <typename OutputType> bool
		ValueExtractorManager<OutputType>
			::construct()
	{
		try
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (this->configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						this->utility_handling_mutex_1
					);
			}

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				this->handle_error_outputs(
					exception
				);
		}
	}

	template <typename OutputType> bool
		ValueExtractorManager<OutputType>
			::destruct()
	{
		try
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (this->configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						this->utility_handling_mutex_1
					);
			}

			return
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				this->handle_error_outputs(
					exception
				);
		}
	}
}
