#pragma once

#include "value_cache.hpp"
#include "instance_manager.hpp"

namespace QLogicaeCppCore
{
    class FileSystemManagerCache
    {
    public:
        static FileSystemManagerCache&
            instance;

        FileSystemManagerCache();

        ~FileSystemManagerCache();

        FileSystemManagerCache(
            const FileSystemManagerCache&
                instance
        ) = delete;

        FileSystemManagerCache(
            FileSystemManagerCache&&
                instance
        ) noexcept = delete;

        FileSystemManagerCache& operator = (
            FileSystemManagerCache&&
                instance
            ) = delete;

        FileSystemManagerCache& operator = (
            const FileSystemManagerCache&
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
    };
}
