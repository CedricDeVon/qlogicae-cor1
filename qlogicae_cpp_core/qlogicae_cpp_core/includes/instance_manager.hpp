#pragma once

namespace QLogicaeCppCore
{
    class InstanceManager
    {
    public:
        InstanceManager();

        ~InstanceManager();

        InstanceManager(
            const InstanceManager&
                instance
        ) =
            delete;

        InstanceManager(
            InstanceManager&&
                instance
        ) noexcept =
            delete;

        InstanceManager&
            operator = (
                InstanceManager&&
                    instance
            ) =
                delete;

        InstanceManager&
            operator = (
                const InstanceManager&
                    instance
            ) =
                delete;
        
        static InstanceManager&
            instance;

        static bool
            _boolean_ouput_cache_1; // is successful

        bool
            construct();

        void
            _construct();

        bool
            destruct();

        void
            _destruct();

        template <typename Type> Type&
            get_instance();

        static InstanceManager&
            get_instance_manager();
    };

    template <typename Type> Type&
        InstanceManager::get_instance()
    {
        static Type instance;

        return instance;
    }   
}

/*

std::future<bool>
    construct_asynchronously(
        const std::function<void(const bool& result)>&
        callback = nullptr
    );

std::future<bool>
    destruct_asynchronously(
        const std::function<void(const bool& result)>&
            callback = nullptr
    );

*/
