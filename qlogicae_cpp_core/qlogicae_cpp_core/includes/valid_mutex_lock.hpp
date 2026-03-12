#pragma once

namespace
	QLogicae::Cor::V1
{
    template<typename LockType, typename MutexType>
    concept ValidLock =
        requires(
            LockType
                lock_type,
            MutexType
                mutex_type
            )
    {
        lock_type(
            mutex_type
        );
    } ||
        requires(
            LockType
                lock_type,
            MutexType
                mutex_type
            )
    {
        lock_type
			.lock();
        
		lock_type
			.unlock();
    };
}

