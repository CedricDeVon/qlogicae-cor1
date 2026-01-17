#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "function_wrapper_configurations.hpp"

namespace
	QLogicaeCppCore
{
	class
		FunctionWrapper
	{
	public:
		FunctionWrapperConfigurations
			configurations;

		static FunctionWrapper&
			singleton;

		FunctionWrapper();
		
		~FunctionWrapper();

		bool
			construct();

		bool
			destruct();

		bool
			setup(
				const FunctionWrapperConfigurations&
					new_configurations
			);

		bool
			reset();

		template <typename ResultType, typename InputObjectType, typename InputCallback, typename... InputCallbackArguments> static ResultType
		call_function(
			InputObjectType&
				input_object,
			const InputCallback&
				input_callback,
			const InputCallbackArguments&...
				input_callback_arguments
		);
	};

	template <typename ResultType, typename InputObjectType, typename InputCallback, typename... InputCallbackArguments>
	ResultType FunctionWrapper::call_function(
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
			if constexpr (std::is_pointer_v<InputObjectType>)
			{
				if (!input_object)
				{
					if constexpr (std::is_default_constructible_v<ResultType>)
					{
						return ResultType{};
					}
					else
					{
						ErrorManager::singleton.handle_error_outputs("");
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
			ErrorManager::singleton.handle_error_outputs(exception);

			if constexpr (std::is_default_constructible_v<ResultType>)
			{
				return ResultType{};
			}
			else
			{
				throw;
			}
		}
	}
}
