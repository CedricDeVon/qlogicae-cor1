#pragma once

#include "value_cache.hpp"
#include "asynchronous_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class AsynchronousManagerCache
    {
    public:      
        static bool
            is_enabled;
        
        static std::shared_ptr<boost::asio::thread_pool>
            main_thread_pool;

        static std::shared_ptr<boost::asio::thread_pool>
            temporary_thread_pool;

        static AsynchronousManagerConfigurations
            configurations;

        static AsynchronousManagerCache&
            instance;

        AsynchronousManagerCache();

        ~AsynchronousManagerCache();

        AsynchronousManagerCache(
            const AsynchronousManagerCache&
                instance
        ) = delete;

        AsynchronousManagerCache(
            AsynchronousManagerCache&&
                instance
        ) noexcept = delete;

        AsynchronousManagerCache&
            operator = (
                AsynchronousManagerCache&&
                    instance
            ) = delete;

        AsynchronousManagerCache&
            operator = (
                const AsynchronousManagerCache&
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
                    configurations
            );

        bool
            setup();

        void
            _setup();

        bool
            reset();

        void
            _reset();
    };
}
