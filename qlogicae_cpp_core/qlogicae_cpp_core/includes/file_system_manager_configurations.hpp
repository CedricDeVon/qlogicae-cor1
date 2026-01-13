#pragma once

#include "error_manager.hpp"

namespace QLogicaeCppCore
{
    struct FileSystemManagerConfigurations
    {
        static bool
            cache_boolean_1;

        static FileSystemManagerConfigurations
            cache_configurations;


        
        static bool
            construct(
                const FileSystemManagerConfigurations&
                    configurations = {}
            );

        static bool
            destruct(
                const FileSystemManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup(
                const FileSystemManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset(
                const FileSystemManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup_caches(
                const FileSystemManagerConfigurations&
                    configurations = {}
            );

        static bool
            setup_defaults(
                const FileSystemManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset_caches(
                const FileSystemManagerConfigurations&
                    configurations = {}
            );

        static bool
            reset_defaults(
                const FileSystemManagerConfigurations&
                    configurations = {}
            );

        static void
            _handle_construct();

        static void
            _handle_destruct();

        static void
            _handle_setup();

        static void
            _handle_reset();

        static void
            _handle_setup_caches();

        static void
            _handle_setup_defaults();

        static void
            _handle_reset_caches();

        static void
            _handle_reset_defaults();
    };
}
