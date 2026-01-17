#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "asynchronous_manager.hpp"
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
		call_safely(
			InputObjectType&
				input_object,
			const InputCallback&
				input_callback,
			const InputCallbackArguments&...
				input_callback_arguments
		);

		template <typename ResultType, typename InputObjectType, typename InputCallback, typename... InputCallbackArguments> static std::future<ResultType>
		call_async(
			InputObjectType&
				input_object,
			const InputCallback&
				input_callback,
			const InputCallbackArguments&...
				input_callback_arguments
		);

		template <typename ResultType, typename InputObjectType, typename InputCallback, typename... InputCallbackArguments> static void
		call_async(
			const std::function<void(ResultType)>&
				output_callback,
			InputObjectType&
				input_object,
			const InputCallback&
				input_callback,
			const InputCallbackArguments&...
				input_callback_arguments
		);
	};

	template <typename ResultType, typename InputObjectType, typename InputCallback, typename... InputCallbackArguments>
	ResultType FunctionWrapper::call_safely(
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
				return (input_object->*input_callback)(input_callback_arguments...);
			}
			else
			{
				return (input_object.*input_callback)(input_callback_arguments...);
			}
		}
		catch (const std::exception& exception)
		{
			ErrorManager::singleton
				.handle_error_outputs(
					exception
				);
		}
		catch (...)
		{
			ErrorManager::singleton
				.handle_error_outputs(
					std::current_exception()
				);
		}
	}

	template <typename ResultType, typename InputObjectType, typename InputCallback, typename... InputCallbackArguments>
	std::future<ResultType> FunctionWrapper::call_async(
		InputObjectType&
			input_object,
		const InputCallback&
			input_callback,
		const InputCallbackArguments&...
			input_callback_arguments
	)
	{
		auto promise = std::make_shared<std::promise<ResultType>>();
		std::future<ResultType> future = promise->get_future();

		auto args_tuple = std::make_tuple(input_callback_arguments...);

		AsynchronousManager::singleton.begin_one_thread(
			[&input_object, input_callback, promise, args_tuple]() mutable
			{
				try
				{
					ResultType value = std::apply(
						[&](auto&&... args)
						{
							return call_safely<ResultType>(input_object, input_callback, args...);
						},
						args_tuple
					);

					promise->set_value(value);
				}
				catch (...)
				{
					ErrorManager::singleton
						.handle_error_outputs(
							std::current_exception()
						);

					promise->set_exception(std::current_exception());
				}
			}
		);

		return future;
	}

	template <typename ResultType, typename InputObjectType, typename InputCallback, typename... InputCallbackArguments>
	void FunctionWrapper::call_async(
		const std::function<void(ResultType)>&
			output_callback,
		InputObjectType&
			input_object,
		const InputCallback&
			input_callback,
		const InputCallbackArguments&...
			input_callback_arguments
	)
	{
		auto args_tuple = std::make_tuple(input_callback_arguments...);

		AsynchronousManager::singleton.begin_one_thread(
			[&input_object, input_callback, output_callback, args_tuple]() mutable
			{
				if (!output_callback) return;

				try
				{
					ResultType value = std::apply(
						[&](auto&&... args)
						{
							return call_safely<ResultType>(input_object, input_callback, args...);
						},
						args_tuple
					);

					try { output_callback(value); }
					catch (...)
					{
						ErrorManager::singleton
							.handle_error_outputs(
								std::current_exception()
							);
					}
				}
				catch (...)
				{
					ErrorManager::singleton
						.handle_error_outputs(
							std::current_exception()
						);
				}
			}
		);
	}
}

