#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "asynchronous_manager_configurations.hpp"

namespace QLogicaeCppCore
{    
    class AsynchronousManagerUtilities
    {
    public:             
        static bool
            cache_boolean_1;

        static std::shared_ptr<boost::asio::thread_pool>
            cache_main_thread_pool;

        static std::shared_ptr<boost::asio::thread_pool>
            cache_temporary_thread_pool;

        static boost::mutex
            cache_mutex;

        static AsynchronousManagerUtilities&
            singleton;

        AsynchronousManagerUtilities();

        ~AsynchronousManagerUtilities();

        AsynchronousManagerUtilities(
            const AsynchronousManagerUtilities&
                instance
        ) = delete;

        AsynchronousManagerUtilities(
            AsynchronousManagerUtilities&&
                instance
        ) noexcept = delete;

        AsynchronousManagerUtilities&
            operator = (
                AsynchronousManagerUtilities&&
                    instance
            ) = delete;

        AsynchronousManagerUtilities&
            operator = (
                const AsynchronousManagerUtilities&
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
            complete_all_threads();

        void
            _construct();

        void
            _destruct();

        void
            _setup();

        void
            _reset();

        void
            _complete_all_threads();
    };
}
