#pragma once

#include "abstract_class.hpp"
#include "function_wrapper_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
	class
		FunctionWrapper :
			public AbstractClass<FunctionWrapperConfigurations>
	{
	public:
		FunctionWrapper();

		template <typename ResultType, typename InputObjectType, typename InputCallback, typename... InputCallbackArguments> ResultType
		call_function(
			InputObjectType&
				input_object,
			const InputCallback&
				input_callback,
			const InputCallbackArguments&...
				input_callback_arguments
		);
	};

	template <typename ResultType, typename InputObjectType, typename InputCallback, typename... InputCallbackArguments> ResultType
		FunctionWrapper::call_function(
			InputObjectType&
				input_object,
			const InputCallback&
				input_callback,
			const InputCallbackArguments&...
				input_callback_arguments
		)
	{
		try
		{		
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations
					.is_thread_safety_enabled_for_feature_handling()
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			if constexpr (std::is_pointer_v<InputObjectType>)
			{
				if (!input_object)
				{
					if constexpr (std::is_default_constructible_v<ResultType>)
					{
						return
							ResultType{};
					}
					else
					{
						SingletonManager
							::get_singleton<ErrorManager>().handle_error_outputs("");
					}
				}
				return (input_object->*input_callback)(input_callback_arguments...);
			}
			else
			{
				return (input_object.*input_callback)(input_callback_arguments...);
			}
		}
		catch (const std::exception& exception)
		{
			handle_error_outputs(
				exception
			);

			if constexpr (std::is_default_constructible_v<ResultType>)
			{
				return
					ResultType{};
			}
			else
			{
				throw;
			}
		}
	}
}
