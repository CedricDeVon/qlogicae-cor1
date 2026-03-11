#pragma once

#include "error_manager.hpp"
#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{
    template <typename AbstractConfigurationsType> class
		AbstractClass
    {
    public:
		boost::mutex
			utility_handling_mutex_1;

		boost::mutex
			feature_handling_mutex_1;

		AbstractConfigurationsType
			configurations;

		AbstractClass();

		~AbstractClass();

        bool
            construct();

		bool
            destruct();

		virtual bool
            setup(
				const AbstractConfigurationsType&
					new_configurations
			);

		virtual bool
            reset();

		template <typename OutputType = bool> OutputType
			handle_error_outputs(
				const std::string&
					title,
				const std::string&
					message
			);

		template <typename OutputType = bool> OutputType
			handle_error_outputs(
				const std::string&
					message
			);

		template <typename OutputType = bool> OutputType
			handle_error_outputs(
				const std::exception&
					exception
			);

		template <typename OutputType = bool> OutputType
			handle_callback_wrapper(
				const std::function<void()>&
					callback
			);

		template <typename Type> static Type
			get_singleton();
    };

	template <typename AbstractConfigurationsType>
		AbstractClass<AbstractConfigurationsType>
			::AbstractClass()
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
			handle_error_outputs<bool>(
				exception
			);
		}
    }

	template <typename AbstractConfigurationsType>
		AbstractClass<AbstractConfigurationsType>
			::~AbstractClass()
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
			handle_error_outputs<bool>(
				exception
			);
		}
    }

	template <typename AbstractConfigurationsType> bool
		AbstractClass<AbstractConfigurationsType>
			::construct()
	{		
		try
		{	
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}
	
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
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
				handle_error_outputs<bool>(
					exception
				);
		}
	}

	template <typename AbstractConfigurationsType> bool
		AbstractClass<AbstractConfigurationsType>
			::destruct()
	{
		try
		{		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
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
				handle_error_outputs<bool>(
					exception
				);
		}
	}

	template <typename AbstractConfigurationsType> bool
		AbstractClass<AbstractConfigurationsType>
			::setup(
				const AbstractConfigurationsType&
					new_configurations
			)
	{
		try
		{	
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}
			
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

			configurations =
				new_configurations;

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
				handle_error_outputs<bool>(
					exception
				);
		}
	}

	template <typename AbstractConfigurationsType> bool
		AbstractClass<AbstractConfigurationsType>
			::reset()
	{
		try
		{	
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}

			configurations =
				{};

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
				handle_error_outputs<bool>(
					exception
				);
		}
	} 
	
	template <typename AbstractConfigurationsType>
	template <typename Type> Type
		AbstractClass<AbstractConfigurationsType>
			::get_singleton()
    {
		static Type singleton;

		return
			singleton;
    }

	template <typename AbstractConfigurationsType>
	template <typename OutputType> OutputType
		AbstractClass<AbstractConfigurationsType>
			::handle_error_outputs(
				const std::string&
					title,
				const std::string&
					message
			)
	{				
		if
		(
			configurations
				.is_runtime_execution_disabled_for_feature_handling()
		)
		{
			return
				OutputType{};
		}

		boost::unique_lock<boost::mutex>
			mutex_lock;
		if (configurations.is_thread_safety_enabled_for_error_handling())
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					utility_handling_mutex_1
				);
		}

		return
			ErrorManager::singleton
				.handle_error_outputs<OutputType>(
					title,
					message
			);
	}

	template <typename AbstractConfigurationsType>
	template <typename OutputType> OutputType
		AbstractClass<AbstractConfigurationsType>
			::handle_error_outputs(
				const std::string&
					message
			)
	{	
		if
		(
			configurations
				.is_runtime_execution_disabled_for_feature_handling()
		)
		{
			return
				OutputType{};
		}

		boost::unique_lock<boost::mutex>
			mutex_lock;
		if (configurations.is_thread_safety_enabled_for_error_handling())
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					utility_handling_mutex_1
				);
		}
		
		return
			ErrorManager::singleton
				.handle_error_outputs<OutputType>(
					message
			);
	}

	template <typename AbstractConfigurationsType>
	template <typename OutputType> OutputType
		AbstractClass<AbstractConfigurationsType>
			::handle_error_outputs(
				const std::exception&
					exception
			)
	{
		if
		(
			configurations
				.is_runtime_execution_disabled_for_feature_handling()
		)
		{
			return
				OutputType{};
		}

		boost::unique_lock<boost::mutex>
			mutex_lock;
		if (configurations.is_thread_safety_enabled_for_error_handling())
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					utility_handling_mutex_1
				);
		}

		return
			ErrorManager::singleton
				.handle_error_outputs<OutputType>(
					exception
			);
	} 

	template <typename AbstractConfigurationsType>
	template <typename OutputType> OutputType
		AbstractClass<AbstractConfigurationsType>
			::handle_callback_wrapper(
				const std::function<void()>&
					callback
			)
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						callback == nullptr
					)
				)
			)
			{
				return
					OutputType{};
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}

			callback();

			return
				OutputType{};
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			return
				handle_error_outputs<OutputType>(
					exception
				);
		}
	}	
}
