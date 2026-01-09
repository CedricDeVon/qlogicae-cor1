#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "asynchronous_manager_configurations.hpp"
#include "asynchronous_manager_utilities.hpp"

namespace QLogicaeCppCore
{    
    class AsynchronousManager
    {
    public:                
        static bool
            cache_boolean_1;

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

        bool
            destruct();

        bool
            setup(
                const AsynchronousManagerConfigurations&
                    new_configurations
            );

        bool
            setup();

        bool
            reset();

        bool
            begin_one_thread(
                const std::function<void()>&
                    callback
            );

        void
            _construct();

        void
            _destruct();

        void
            _setup();

        void
            _reset();

        void
            _begin_one_thread(
                const std::function<void()>&
                    callback
            );
    };   
}
