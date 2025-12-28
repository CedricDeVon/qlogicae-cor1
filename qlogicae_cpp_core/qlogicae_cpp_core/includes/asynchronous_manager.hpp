#pragma once

#include "value_cache.hpp"
#include "mutex_manager.hpp"
#include "instance_manager.hpp"
#include "asynchronous_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class AsynchronousManager
    {
    public:
        AsynchronousManager();

        ~AsynchronousManager();

        AsynchronousManager(
            const AsynchronousManager& instance
        ) = delete;

        AsynchronousManager(
            AsynchronousManager&& instance
        ) noexcept = delete;

        AsynchronousManager&
            operator = (
                AsynchronousManager&& instance
            ) = delete;

        AsynchronousManager&
            operator = (
                const AsynchronousManager& instance
            ) = delete;

        static AsynchronousManager&
            instance;

        static std::shared_ptr<boost::asio::thread_pool>
            main_thread_pool;

        static std::shared_ptr<boost::asio::thread_pool>
            temporary_thread_pool;

        bool
            construct();

        void
            _construct();

        bool
            destruct();

        void
            _destruct();

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

        bool
            complete_all_threads();

        void
            _complete_all_threads();
    };
}
