#pragma once

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
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
