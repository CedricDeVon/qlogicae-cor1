#pragma once

namespace QLogicaeCppCore
{
    class InstanceManager
    {
    public:        
        static InstanceManager&
            instance;

        InstanceManager();

        ~InstanceManager();

        InstanceManager(
            const InstanceManager&
                instance
        ) = delete;

        InstanceManager(
            InstanceManager&&
                instance
        ) noexcept = delete;

        InstanceManager&
            operator = (
                InstanceManager&&
                    instance
            ) = delete;

        InstanceManager&
            operator = (
                const InstanceManager&
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

        template <typename Type> Type&
            get_instance();

        static InstanceManager&
            get_instance_manager();
    };

    template <typename Type> Type&
        InstanceManager::get_instance()
    {
        static Type
            instance;

        return instance;
    }   
}
