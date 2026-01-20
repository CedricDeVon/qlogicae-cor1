#include "pch.hpp"

#include "../includes/mutex_manager.hpp"

namespace
	QLogicaeCppCore
{           
	MutexManager&
        MutexManager
			::singleton =
				SingletonManager
					::get_singleton<MutexManager>();



	MutexManager
		::MutexManager() :
			AbstractClass<MutexManagerConfigurations>()
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

    MutexManager
		::~MutexManager()
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
        MutexManager
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
        MutexManager
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
        MutexManager::lock_micro_mutex(
            const void*
				pointer
        )
    {
		return
			lock_micro_mutex(
				pointer,
				configurations.name
			);
    }

    bool
        MutexManager::lock_micro_mutex(
            const void*
				pointer,
            const std::string&
				name
        )
    {
       try
        {
			if (!pointer)
			{
				return
					false;
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

			void*
				raw_pointer =
					const_cast<void*>(
						pointer
					);

            folly::MicroSpinLock*
                micro_spin_lock =
                &folly_micro_spin_lock_collection
                [
					std::pair
					{
						raw_pointer,
						name
					}
                ];

            micro_spin_lock->lock();

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
        MutexManager::unlock_micro_mutex(
            const void*
	            pointer
        )
    {
        return
			unlock_micro_mutex(
				pointer,
				configurations.name
			);
    }

    bool
        MutexManager::unlock_micro_mutex(
            const void*
				pointer,
            const std::string&
				name
        )
    {
        try
        {
			if (!pointer)
			{
				return
					false;
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

			void*
				raw_pointer =
					const_cast<void*>(
						pointer
					);

            folly::MicroSpinLock*
                micro_spin_lock =
                &folly_micro_spin_lock_collection
                [
					std::pair
					{
						raw_pointer,
						name
					}
                ];

            micro_spin_lock->unlock();

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
		MutexManager
			::clear_all_collections()
	{
		try
		{
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

			mutex_collection
				.clear();

			timed_mutex_collection
				.clear();

			recursive_mutex_collection
				.clear();

			recursive_timed_mutex_collection
				.clear();

			shared_mutex_collection
				.clear();

			boost_mutex_collection
				.clear();

			boost_timed_mutex_collection
				.clear();

			boost_recursive_mutex_collection
				.clear();

			boost_recursive_timed_mutex_collection
				.clear();

			boost_shared_mutex_collection
				.clear();

			folly_micro_spin_lock_collection
				.clear();

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
}
