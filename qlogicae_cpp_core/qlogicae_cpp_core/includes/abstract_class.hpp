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
			method_handling_layer_mutex_1;

		boost::mutex
			method_handling_layer_mutex_2;

		boost::mutex
			error_handling_mutex;

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

		bool
			handle_error_outputs(
				const std::string&
					title,
				const std::string&
					message
			);

		bool
			handle_error_outputs(
				const std::string&
					message
			);

		bool
			handle_error_outputs(
				const std::exception&
					exception
			);
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
			handle_error_outputs(
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
			handle_error_outputs(
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
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						method_handling_layer_mutex_1
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
				handle_error_outputs(
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
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						method_handling_layer_mutex_1
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
				handle_error_outputs(
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
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						method_handling_layer_mutex_1
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
				handle_error_outputs(
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
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						method_handling_layer_mutex_1
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
				handle_error_outputs(
					exception
				);
		}
	} 

	template <typename AbstractConfigurationsType> bool
		AbstractClass<AbstractConfigurationsType>
			::handle_error_outputs(
				const std::string&
					title,
				const std::string&
					message
			)
	{				
		boost::unique_lock<boost::mutex>
			mutex_lock;
		if (configurations.is_thread_safety_enabled_for_error_handling())
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					error_handling_mutex
				);
		}

		return
			ErrorManager::singleton
				.handle_error_outputs(
					title,
					message
			);
	}

	template <typename AbstractConfigurationsType> bool
		AbstractClass<AbstractConfigurationsType>
			::handle_error_outputs(
				const std::string&
					message
			)
	{	
		boost::unique_lock<boost::mutex>
			mutex_lock;
		if (configurations.is_thread_safety_enabled_for_error_handling())
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					error_handling_mutex
				);
		}
		
		return
			ErrorManager::singleton
				.handle_error_outputs(
					message
			);
	}

	template <typename AbstractConfigurationsType> bool
		AbstractClass<AbstractConfigurationsType>
			::handle_error_outputs(
				const std::exception&
					exception
			)
	{
		boost::unique_lock<boost::mutex>
			mutex_lock;
		if (configurations.is_thread_safety_enabled_for_error_handling())
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					error_handling_mutex
				);
		}

		return
			ErrorManager::singleton
				.handle_error_outputs(
					exception
			);
	} 	
}
