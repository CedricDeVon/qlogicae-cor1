#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "file_system_manager_utilities.hpp"
#include "file_system_manager_configurations.hpp"

namespace QLogicaeCppCore
{
    class FileSystemManager
    {
    public:
        static bool
            cache_boolean_1;

        static FileSystemManager&
            singleton;

        FileSystemManager();

        ~FileSystemManager();

        FileSystemManager(
            const FileSystemManager&
                instance
        ) = delete;

        FileSystemManager(
            FileSystemManager&&
                instance
        ) noexcept = delete;

        FileSystemManager& operator = (
            FileSystemManager&&
                instance
        ) = delete;

        FileSystemManager& operator = (
            const FileSystemManager&
                instance
        ) = delete;

        bool
            construct();

        bool
            destruct();

        bool
            setup(
                const FileSystemManagerConfigurations&
                    new_configurations
            );

        bool
            setup();

        bool
            reset();
        
        void
            _handle_construct();

        void
            _handle_destruct();        

        void
            _handle_setup();

        void
            _handle_reset();
    };
}
