#pragma once

namespace QLogicaeCppCore
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
        lock_type.lock();
        lock_type.unlock();
    };
}
