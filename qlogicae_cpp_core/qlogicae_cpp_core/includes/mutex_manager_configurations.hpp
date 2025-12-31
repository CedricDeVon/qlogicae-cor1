#pragma once

#include "value_cache.hpp"
#include "instance_manager.hpp"
#include "mutex_manager_configuration_parameters.hpp"

namespace QLogicaeCppCore
{
    class MutexManagerConfigurations
    {
    public:
        static MutexManagerConfigurations&
            instance;

        static void*
            pointer;

        static std::string
            name;

        static MutexManagerConfigurationParameters
            parameters;

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

        bool
            construct(
                const MutexManagerConfigurationParameters&
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
