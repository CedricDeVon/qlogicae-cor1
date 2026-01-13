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

        static boost::mutex
            cache_mutex_1;

		static boost::mutex
			cache_mutex_2;

        static std::shared_ptr<boost::asio::thread_pool>
            cache_main_thread_pool;

        static std::shared_ptr<boost::asio::thread_pool>
            cache_temporary_thread_pool;

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
            complete_all_threads(
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
            _handle_complete_all_threads();
    };
}
