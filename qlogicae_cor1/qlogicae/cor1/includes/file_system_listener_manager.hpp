#pragma once

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		FileSystemListenerManager \
	)

#include "abstract_enum.hpp"
#include "abstract_class.hpp"
#include "file_system_entity.hpp"
#include "file_system_listener_manager_configurations.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{	    
    enum class
        FileSystemEventAction :
            QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_ENUM_INHERITED_TYPE
    {
        CREATED,

        DELETED,

        MODIFIED,

        RENAMED,

        MOVED,

        METADATA_CHANGED,

        UNKNOWN,

        QLOGICAE_COR1__BASE__HPP_CPP__ENUM_CONSTANTS
    };

    enum class
        FileSystemEventSource :
            QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_ENUM_INHERITED_TYPE
    {
        NATIVE,

        SYNTHETIC,

        QLOGICAE_COR1__BASE__HPP_CPP__ENUM_CONSTANTS
    };

    enum class
        FileSystemEventMetadataFlags :
            QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_ENUM_INHERITED_TYPE
    {
        PERMISSIONS = 1 << 0,

        TIMESTAMP = 1 << 1,

        OWNERSHIP = 1 << 2,

        QLOGICAE_COR1__BASE__HPP_CPP__ENUM_CONSTANTS
    };

    struct
        FileSystemEvent
    {
        std::uint64_t
            sequence;

        std::uint64_t
            correlation_id;

        std::string
            path;

        std::string
            old_path;

        FileSystemEventAction
            action;

        FileSystemEntity
            type;

        FileSystemEventSource
            source;

        FileSystemEventMetadataFlags
            metadata_flags;

        std::uint8_t
            flags;

        std::chrono::steady_clock::time_point
            timestamp;
    };

    struct
        FileSystemListenerManagerOptions
    {
        bool
            is_recursive_enabled;

        std::chrono::milliseconds
            debounce_interval;

        std::unordered_set<std::string>
            extensions;

        std::unordered_set<std::string>
            explicit_files;
    };

    struct
        FileSystemWatchContext
    {
        std::string
            directory;

        FileSystemListenerManagerOptions
            options;
    };

    struct
        FileSystemEventSlot
    {
        std::atomic<bool>
            is_ready;

        FileSystemEvent
            event;

        FileSystemEventSlot() :
            is_ready(false)
        {
        }

        FileSystemEventSlot(
            const FileSystemEventSlot&
        ) = delete;

        FileSystemEventSlot&
            operator=(
                const FileSystemEventSlot&
            ) = delete;

        FileSystemEventSlot(
            FileSystemEventSlot&&
                other
        ) noexcept :
            is_ready(other.is_ready.load(
                std::memory_order_relaxed
            )),
            event(std::move(other.event))
        {
            other.is_ready.store(
                false,
                std::memory_order_relaxed
            );
        }

        FileSystemEventSlot&
            operator=(
                FileSystemEventSlot&&
                    other
            ) noexcept
        {
            is_ready.store(
                other.is_ready.load(
                    std::memory_order_relaxed
                ),
                std::memory_order_relaxed
            );

            event = std::move(other.event);

            other.is_ready.store(
                false,
                std::memory_order_relaxed
            );

            return *this;
        }
    };

    class
        FileSystemListenerManager :
            public QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<
                FileSystemListenerManagerConfigurations
            >,
            public efsw::FileWatchListener
    {
    public:
        FileSystemListenerManager();

        ~FileSystemListenerManager();

        bool
            start_watching();

        bool
            stop_watching();

        bool
            add_watch(
                const std::string&
                    directory,
                const FileSystemListenerManagerOptions&
                    options
            );

        bool
            remove_watch(
                const std::string&
                    directory
            );

        bool
            add_listener(
                const std::function<void(const FileSystemEvent&)>&
                    callback
            );

        void
            handleFileAction(
                efsw::WatchID
                    watch_id,
                const std::string&
                    directory,
                const std::string&
                    filename,
                efsw::Action
                    action,
                std::string
                    old_filename
            ) override;

        static
            FileSystemEventAction
            translate_action(
                const efsw::Action&
                    action
            );

        bool
            dispatch_loop();

        bool
            notify_batch(
                std::vector<FileSystemEvent>&
                    batch
            );

        bool
            passes_filter(
                const std::string&
                    path,
                const FileSystemListenerManagerOptions&
                    options
            );

        bool
            resolve_full_path(
                const efsw::WatchID&
                    watch_id,
                const std::string&
                    directory,
                const std::string&
                    filename,
                std::string&
                    out_path
            );

        bool
            resolve_old_path(
                const efsw::WatchID&
                    watch_id,
                const std::string&
                    directory,
                const std::string&
                    old_filename,
                std::string&
                    out_path
            );

        static constexpr std::size_t
            queue_capacity = 65536;

        efsw::FileWatcher
            watcher;

        std::unordered_map<
            efsw::WatchID,
            FileSystemWatchContext
        >
            watch_registry;

        std::atomic<bool>
            is_running;

        std::thread
            watcher_thread;

        std::thread
            dispatcher_thread;

        std::vector<FileSystemEventSlot>
            ring_buffer;

        std::atomic<std::size_t>
            write_index;

        std::atomic<std::size_t>
            read_index;

        std::vector<
            std::function<void(const FileSystemEvent&)>
        >
            listeners;

        std::atomic<std::uint64_t>
            sequence_counter;
    };
}

#endif
