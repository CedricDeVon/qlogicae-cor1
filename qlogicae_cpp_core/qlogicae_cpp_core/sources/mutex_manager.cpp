#include "pch.hpp"

#include "../includes/mutex_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{           
	MutexManager
		::MutexManager() :
			AbstractClass<MutexManagerConfigurations>()
    {
        
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						pointer == nullptr ||
						name.empty()
					)
				)
			)
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

            folly::MicroSpinLock*
                micro_spin_lock =
                &folly_micro_spin_lock_collection
                [
					std::pair
					{
						const_cast<void*>(
							pointer
						),
						name
					}
                ];

            micro_spin_lock->lock();

            return
				true;
        }
        catch
        (
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
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
        MutexManager::unlock_micro_mutex(
            const void*
				pointer,
            const std::string&
				name
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
						pointer == nullptr ||
						name.empty()
					)
				)
			)
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
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
            QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
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
				configurations
					.name
			);
    }

    bool
		MutexManager
			::clear_all_collections()
	{
		try
		{
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
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
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
		}
	}
}
