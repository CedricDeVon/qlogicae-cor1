#pragma once

#include "value_cache.hpp"
#include "instance_manager.hpp"
#include "mutex_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class MutexManagerCache
    {
    public:        
        static void*
            pointer;

        static std::string
            name;

        static MutexManagerConfigurations
            configurations;

        static MutexManagerCache&
            instance;

        MutexManagerCache();

        ~MutexManagerCache();

        MutexManagerCache(
            const MutexManagerCache&
                instance
        ) = delete;

        MutexManagerCache(
            MutexManagerCache&&
                instance
        ) noexcept = delete;

        MutexManagerCache&
            operator = (
                MutexManagerCache&&
                    instance
            ) = delete;

        MutexManagerCache&
            operator = (
                const MutexManagerCache&
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
                const MutexManagerConfigurations&
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
    };    
}
