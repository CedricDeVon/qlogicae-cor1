#pragma once

#include "mutex_manager.hpp"
#include "instance_manager.hpp"

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

        static bool
            _boolean_ouput_cache_1;

        static std::shared_ptr<boost::asio::thread_pool>
            _thread_pool;

        static std::shared_ptr<boost::asio::thread_pool>
            _temporary_thread_pool;

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
