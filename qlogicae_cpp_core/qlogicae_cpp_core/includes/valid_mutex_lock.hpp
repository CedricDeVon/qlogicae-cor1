#pragma once

namespace QLogicaeCppCore
{
    template<typename LockType, typename MutexType>
    concept ValidLock =
        (
            std::is_same_v<LockType, std::unique_lock<MutexType>> ||
            std::is_same_v<LockType, std::shared_lock<MutexType>>
        );
}
