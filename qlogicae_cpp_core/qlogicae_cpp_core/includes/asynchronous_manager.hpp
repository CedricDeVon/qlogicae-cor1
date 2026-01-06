#pragma once

#include "value_cache.hpp"
#include "singleton_manager.hpp"
#include "asynchronous_manager_utilities.hpp"
#include "asynchronous_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class AsynchronousManager
    {
    public:        
        static AsynchronousManager&
            singleton;

        AsynchronousManager();

        ~AsynchronousManager();

        AsynchronousManager(
            const AsynchronousManager&
                instance
        ) = delete;

        AsynchronousManager(
            AsynchronousManager&&
                instance
        ) noexcept = delete;

        AsynchronousManager&
            operator = (
                AsynchronousManager&&
                    instance
        ) = delete;

        AsynchronousManager&
            operator = (
                const AsynchronousManager&
                    instance
        ) = delete;
        
        bool
            construct();

        void
            _construct();

        bool
            destruct();

        void
            _destruct();

        bool
            setup(
                const AsynchronousManagerConfigurations&
                    new_configurations
            );

        bool
            setup();

        void
            _setup();

        bool
            reset();

        void
            _reset();

        bool
            begin_one_thread(
                const std::function<void()>&
                    callback
            );

        void
            _begin_one_thread(
                const std::function<void()>&
                    callback
            );
    };
}
