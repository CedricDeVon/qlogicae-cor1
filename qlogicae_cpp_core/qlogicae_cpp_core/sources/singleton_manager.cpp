#include "pch.hpp"

#include "../includes/singleton_manager.hpp"

namespace
	QLogicae::Cor::V1
{               
	SingletonManager
		::SingletonManager()
	{
		construct();
	}
	
	SingletonManager
		::~SingletonManager()
    {
		destruct();
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
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
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
			throw std::runtime_error(
				exception.what()
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
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
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
			throw std::runtime_error(
				exception.what()
			);
		}
	}

	 bool
		SingletonManager
			::setup(
				const SingletonManagerConfigurations&
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
						feature_handling_mutex_1
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
			throw std::runtime_error(
				exception.what()
			);
		}
	}

	 bool
		SingletonManager
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
						feature_handling_mutex_1
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
			throw std::runtime_error(
				exception.what()
			);
		}
	} 

	SingletonManager&
		SingletonManager
			::get_this_singleton()
	{		
		static SingletonManager
			singleton;

		return
			singleton;
	}
}
