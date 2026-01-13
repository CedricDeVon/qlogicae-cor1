#pragma once

#include "error_manager.hpp"
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
            construct(
                const AsynchronousManagerConfigurations&
                    configurations = {}
            );

        bool
            destruct(
                const AsynchronousManagerConfigurations&
                    configurations = {}
            );

        bool
            setup(
                const AsynchronousManagerConfigurations&
                    configurations = {}
            );

        bool
            reset(
                const AsynchronousManagerConfigurations&
                    configurations = {}
            );

        bool
            begin_one_thread(
                const std::function<void()>&
                    callback,
                const AsynchronousManagerConfigurations&
                    configurations = {}
            );

        void
            _handle_construct();

        void
            _handle_destruct();

        void
            _handle_setup();

        void
            _handle_reset();

        void
            _handle_begin_one_thread(
                const std::function<void()>&
                    callback
            );
    };   
}
