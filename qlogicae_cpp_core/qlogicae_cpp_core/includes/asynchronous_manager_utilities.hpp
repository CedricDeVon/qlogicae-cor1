#pragma once

#include "value_cache.hpp"
#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "asynchronous_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class AsynchronousManagerUtilities
    {
    public:              
        static std::shared_ptr<boost::asio::thread_pool>
            main_thread_pool;

        static std::shared_ptr<boost::asio::thread_pool>
            temporary_thread_pool;

        static AsynchronousManagerConfigurations
            configurations;

        static boost::mutex
            mutex;

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
            complete_all_threads();

        void
            _complete_all_threads();
    };
}
