#pragma once

#include "value_cache.hpp"
#include "instance_manager.hpp"
#include "mutex_manager_configurations_parameters.hpp"

namespace QLogicaeCppCore
{
    class MutexManagerConfigurations
    {
    public:
        MutexManagerConfigurations();

        ~MutexManagerConfigurations();

        MutexManagerConfigurations(
            const MutexManagerConfigurations&
                instance
        ) = delete;

        MutexManagerConfigurations(
            MutexManagerConfigurations&&
                instance
        ) noexcept = delete;

        MutexManagerConfigurations&
            operator = (
                MutexManagerConfigurations&&
                    instance
            ) = delete;

        MutexManagerConfigurations&
            operator = (
                const MutexManagerConfigurations&
                    instance
            ) = delete;

        static MutexManagerConfigurations&
            instance;

        static std::string
            base_name;

        bool
            construct(
                const MutexManagerConfigurationsParameters&
                    new_parameters
            );

        bool
            construct();

        void
            _construct();

        bool
            destruct();

        void
            _destruct();
    };    
}
