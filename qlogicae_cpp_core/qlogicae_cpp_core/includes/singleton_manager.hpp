#pragma once

namespace QLogicaeCppCore
{
    class SingletonManager
    {
    public:        
        static bool
            cache_is_successful;

        static std::exception
            cache_exception;

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

        void
            _construct();

        bool
            destruct();

        void
            _destruct();

        bool
            setup();

        void
            _setup();

        bool
            reset();

        void
            _reset();

        bool
            handle_error(
                const std::exception&
                    exception
            );

        void
            _handle_error();

        template <typename Type> Type&
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
