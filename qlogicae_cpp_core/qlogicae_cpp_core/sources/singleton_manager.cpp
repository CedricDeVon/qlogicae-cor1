#include "pch.hpp"

#include "../includes/singleton_manager.hpp"

namespace
	QLogicaeCppCore
{               
    SingletonManager&
        SingletonManager
			::singleton =
				SingletonManager
					::get_this_singleton();

	boost::mutex
		SingletonManager
			::feature_handling_mutex_2;

	SingletonManager
		::SingletonManager() :
			AbstractClass<SingletonManagerConfigurations>()
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

	SingletonManager
		::~SingletonManager()
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
    
    bool
        SingletonManager
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
			if
			(
				configurations
					.is_thread_safety_enabled_for_utility_handling()
			)
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
				handle_error_outputs(
					exception
				);
        }
    }

    bool
        SingletonManager
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
			if
			(
				configurations
					.is_thread_safety_enabled_for_utility_handling()
			)
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
				handle_error_outputs(
					exception
				);
        }
    }

	SingletonManager&
		SingletonManager
			::get_this_singleton()
	{
		boost::unique_lock<boost::mutex>
			mutex_lock;
		if
		(
			SingletonManagerConfigurations
				::default_configurations
					.is_thread_safety_enabled_for_feature_handling()
		)
		{
			mutex_lock =
				boost::unique_lock<boost::mutex>
				(
					feature_handling_mutex_2
				);
		}

		static SingletonManager
			singleton;

		return
			singleton;
	}
}
