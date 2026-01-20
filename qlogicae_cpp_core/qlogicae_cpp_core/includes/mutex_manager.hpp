#pragma once

#include "abstract_class.hpp"
#include "valid_mutex_lock.hpp"
#include "singleton_manager.hpp"
#include "pair_hash_operator.hpp"
#include "mutex_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{        
    class
		MutexManager :
			public AbstractClass<MutexManagerConfigurations>
    {
    public:     
		std::unordered_map<std::pair<void*, std::string>, std::mutex, PairHashOperator>
			mutex_collection;

		std::unordered_map<std::pair<void*, std::string>, std::timed_mutex, PairHashOperator>
			timed_mutex_collection;

		std::unordered_map<std::pair<void*, std::string>, std::recursive_mutex, PairHashOperator>
			recursive_mutex_collection;

		std::unordered_map<std::pair<void*, std::string>, std::recursive_timed_mutex, PairHashOperator>
			recursive_timed_mutex_collection;

		std::unordered_map<std::pair<void*, std::string>, std::shared_mutex, PairHashOperator>
			shared_mutex_collection;

		std::unordered_map<std::pair<void*, std::string>, boost::mutex, PairHashOperator>
			boost_mutex_collection;

		std::unordered_map<std::pair<void*, std::string>, boost::timed_mutex, PairHashOperator>
			boost_timed_mutex_collection;

		std::unordered_map<std::pair<void*, std::string>, boost::recursive_mutex, PairHashOperator>
			boost_recursive_mutex_collection;

		std::unordered_map<std::pair<void*, std::string>, boost::recursive_timed_mutex, PairHashOperator>
			boost_recursive_timed_mutex_collection;

		std::unordered_map<std::pair<void*, std::string>, boost::shared_mutex, PairHashOperator>
			boost_shared_mutex_collection;

		std::unordered_map<std::pair<void*, std::string>, folly::MicroSpinLock, PairHashOperator>
			folly_micro_spin_lock_collection;

        static MutexManager&
            singleton;

		MutexManager();

		~MutexManager();

		bool
			construct();

		bool
			destruct();

        bool
            lock_micro_mutex(
                const void*
                    pointer
            );

        bool
            lock_micro_mutex(
                const void*
                    pointer,
                const std::string&
                    name
            );

        bool
            unlock_micro_mutex(
                const void* pointer
            );

        bool
            unlock_micro_mutex(
                const void*
					pointer,
                const std::string&
					name
            );

		bool
			clear_all_collections();

        template<typename LockType, typename MutexType> bool
            lock_mutex(
                const void*
			        pointer
            ) requires ValidLock<LockType, MutexType>;

        template<typename LockType, typename MutexType> bool
            lock_mutex(
                const void*
		            pointer,
                const std::string&
	                name
            ) requires ValidLock<LockType, MutexType>;
    };

    template<typename LockType, typename MutexType> bool
        MutexManager
			::lock_mutex(
				const void*
					pointer
			) requires ValidLock<LockType, MutexType>
    {
        return
			lock_mutex<LockType, MutexType>(
				pointer,
				configurations.name
			);
    }

	template<typename LockType, typename MutexType> bool
	MutexManager
		::lock_mutex(
			const void*
				pointer,
			const std::string&
				name
		) requires ValidLock<LockType, MutexType>
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

			MutexType*
				mutex_pointer =
					nullptr;
			void*
				raw_pointer =
					const_cast<void*>(
						pointer
					);

			if constexpr (std::is_same_v<MutexType, std::mutex>)
			{
				mutex_pointer =
					&mutex_collection
					[
						std::pair
						{
							raw_pointer,
							name
						}
					];
			}
			else if constexpr (std::is_same_v<MutexType, std::timed_mutex>)
			{
				mutex_pointer =
					&timed_mutex_collection
					[
						std::pair
						{
							raw_pointer,
							name
						}
					];
			}
			else if constexpr (std::is_same_v<MutexType, std::recursive_mutex>)
			{
				mutex_pointer =
					&recursive_mutex_collection
					[
						std::pair
						{
							raw_pointer,
							name
						}
					];
			}
			else if constexpr (std::is_same_v<MutexType, std::recursive_timed_mutex>)
			{
				mutex_pointer =
					&recursive_timed_mutex_collection
					[
						std::pair
						{
							raw_pointer,
							name
						}
					];
			}
			else if constexpr (std::is_same_v<MutexType, std::shared_mutex>)
			{
				mutex_pointer =
					&shared_mutex_collection
					[
						std::pair
						{
							raw_pointer,
							name
						}
					];
			}
			else if constexpr (std::is_same_v<MutexType, boost::mutex>)
			{
				mutex_pointer =
					&boost_mutex_collection
					[
						std::pair
						{
							raw_pointer,
							name
						}
					];
			}
			else if constexpr (std::is_same_v<MutexType, boost::timed_mutex>)
			{
				mutex_pointer =
					&boost_timed_mutex_collection
					[
						std::pair
						{
							raw_pointer,
							name
						}
					];
			}
			else if constexpr (std::is_same_v<MutexType, boost::recursive_mutex>)
			{
				mutex_pointer =
					&boost_recursive_mutex_collection
					[
						std::pair
						{
							raw_pointer,
							name
						}
					];
			}
			else if constexpr (std::is_same_v<MutexType, boost::recursive_timed_mutex>)
			{
				mutex_pointer =
					&boost_recursive_timed_mutex_collection
					[
						std::pair
						{
							raw_pointer,
							name
						}
					];
			}
			else if constexpr (std::is_same_v<MutexType, boost::shared_mutex>)
			{
				mutex_pointer =
					&boost_shared_mutex_collection
					[
						std::pair
						{
							raw_pointer,
							name
						}
					];
			}
			else
			{
				return
					false;
			}

			LockType
				lock(
					*mutex_pointer
				);

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
