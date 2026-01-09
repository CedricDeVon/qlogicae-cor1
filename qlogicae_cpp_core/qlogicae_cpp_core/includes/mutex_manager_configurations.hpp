#pragma once

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



        static std::string
            default_name;

        static void*
            default_pointer;



        static std::string
            cache_name;

        static void*
            cache_pointer;



        static MutexManagerConfigurations
            cache;
    };
}
