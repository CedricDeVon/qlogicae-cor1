#pragma once

#include "value_cache.hpp"

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
        
        static InstanceManager&
            instance;

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

        boolean_cache_1 =
            true;

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
