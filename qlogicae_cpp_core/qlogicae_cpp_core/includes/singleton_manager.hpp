#pragma once

#include "error_manager_configurations.hpp"
#include "singleton_manager_configurations.hpp"

namespace QLogicaeCppCore
{        
    class SingletonManager
    {
    public:          
        static bool
            cache_boolean_1;

        static std::string
            cache_error_log;

        static fast_io::native_io_observer
            cache_fast_io_error_console_output_type;

        static SingletonManager&
            singleton;

        SingletonManager();

        ~SingletonManager();

        SingletonManager(
            const SingletonManager&
                instance
        ) = delete;

        SingletonManager(
            SingletonManager&&
                instance
        ) noexcept = delete;

        SingletonManager&
            operator = (
                SingletonManager&&
                    instance
        ) = delete;

        SingletonManager&
            operator = (
                const SingletonManager&
                    instance
        ) = delete;
        
        bool
            construct();

        bool
            destruct();

        bool
            setup(
                const SingletonManagerConfigurations&
                    new_configurations
            );

        bool
            setup();

        bool
            reset();

        bool
            handle_error(
                const std::exception&
                    exception
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
            _handle_error();

        void
            _handle_error_asynchronously();

        void
            _handle_error_synchronously();

        template <typename Type> static Type&
            get_singleton();

        static SingletonManager&
            get_this_singleton();

    };

    template <typename Type> Type&
        SingletonManager::get_singleton()
    {
        static Type
            singleton;

        return singleton;
    }    
}
