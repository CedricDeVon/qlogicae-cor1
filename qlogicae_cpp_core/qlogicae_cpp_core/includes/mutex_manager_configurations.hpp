#pragma once

#include "instance_manager.hpp"

namespace QLogicaeCppCore
{
    struct MutexManagerConfigurations
    {
        void*
            pointer =
                default_pointer;

        std::string
            name =
                default_name;



        static void*
            initial_pointer;

        static std::string
            initial_name;



        static void*
            default_pointer;

        static std::string
            default_name;
    };
}
