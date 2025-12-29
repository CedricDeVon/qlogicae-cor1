#pragma once

namespace QLogicaeCppCore
{
    template<typename LockType, typename MutexType>
    concept ValidLock =
        requires(LockType l, MutexType m)
    {
        l(m);
    } ||
        requires(LockType l, MutexType m)
    {
        l.lock(); l.unlock();
    };
}
