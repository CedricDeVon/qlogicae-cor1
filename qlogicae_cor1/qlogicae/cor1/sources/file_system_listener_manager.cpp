#include "pch.hpp"

#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
		FileSystemListenerManager \
	)

#include "../includes/file_system_listener_manager.hpp"

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{    	
    FileSystemListenerManager::FileSystemListenerManager() :
        is_running(false),
        write_index(0),
        read_index(0),
        sequence_counter(0),
        QLOGICAE_COR1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<FileSystemListenerManagerConfigurations>()
    {
        ring_buffer.resize(queue_capacity);

        for (auto& slot : ring_buffer)
        {
            slot.is_ready.store(false, std::memory_order_relaxed);
        }
    }

    FileSystemListenerManager::~FileSystemListenerManager()
    {
        stop_watching();
    }

    bool
    FileSystemListenerManager::start_watching()
    {
        if (is_running.load())
        {
            return false;
        }

        is_running.store(true);

        watcher.watch();

        watcher_thread = std::thread([this]()
        {
            while (is_running.load())
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        });

        dispatcher_thread = std::thread(
            &FileSystemListenerManager::dispatch_loop,
            this
        );

        return true;
    }

    bool
    FileSystemListenerManager::stop_watching()
    {
        if (!is_running.load())
        {
            return false;
        }

        is_running.store(false);

        if (watcher_thread.joinable())
        {
            watcher_thread.join();
        }

        if (dispatcher_thread.joinable())
        {
            dispatcher_thread.join();
        }

        return true;
    }

    bool
    FileSystemListenerManager::add_watch(
        const std::string& directory,
        const FileSystemListenerManagerOptions& options
    )
    {
        auto id = watcher.addWatch(
            directory,
            this,
            options.is_recursive_enabled
        );

        if (id < 0)
        {
            return false;
        }

        watch_registry.emplace(
            id,
            FileSystemWatchContext{directory, options}
        );

        return true;
    }

    bool
    FileSystemListenerManager::remove_watch(
        const std::string& directory
    )
    {
        for (auto it = watch_registry.begin();
             it != watch_registry.end();
             ++it)
        {
            if (it->second.directory == directory)
            {
                watcher.removeWatch(it->first);
                watch_registry.erase(it);
                return true;
            }
        }

        return false;
    }

    bool
    FileSystemListenerManager::add_listener(
        const std::function<void(const FileSystemEvent&)>& callback
    )
    {
        listeners.push_back(callback);
        return true;
    }

    void
    FileSystemListenerManager::handleFileAction(
        efsw::WatchID watch_id,
        const std::string& directory,
        const std::string& filename,
        efsw::Action action,
        std::string old_filename
    )
    {
        auto it = watch_registry.find(watch_id);

        if (it == watch_registry.end())
        {
            return;
        }

        std::string full_path;
        std::string old_path;

        resolve_full_path(
            watch_id,
            directory,
            filename,
            full_path
        );

        resolve_old_path(
            watch_id,
            directory,
            old_filename,
            old_path
        );

        if (!passes_filter(full_path, it->second.options))
        {
            return;
        }

        FileSystemEvent event;

        event.sequence =
            sequence_counter.fetch_add(1);

        event.correlation_id = 0;

        event.path = std::move(full_path);

        event.old_path = std::move(old_path);

        event.action = translate_action(action);

        event.type = FileSystemEntity::FILE;

        event.source = FileSystemEventSource::NATIVE;

        event.metadata_flags =
            static_cast<FileSystemEventMetadataFlags>(0);

        event.flags = 0;

        event.timestamp =
            std::chrono::steady_clock::now();

        std::size_t index =
            write_index.fetch_add(1,
                std::memory_order_acq_rel);

        std::size_t slot_index =
            index % queue_capacity;

        auto& slot = ring_buffer[slot_index];

        while (slot.is_ready.load(
            std::memory_order_acquire))
        {
            read_index.fetch_add(1,
                std::memory_order_acq_rel);

            slot.is_ready.store(
                false,
                std::memory_order_release
            );
        }

        slot.event = std::move(event);

        slot.is_ready.store(
            true,
            std::memory_order_release
        );
    }

    FileSystemEventAction
    FileSystemListenerManager::translate_action(
        const efsw::Action& action
    )
    {
        switch (action)
        {
            case efsw::Actions::Add:
                return FileSystemEventAction::CREATED;

            case efsw::Actions::Delete:
                return FileSystemEventAction::DELETED;

            case efsw::Actions::Modified:
                return FileSystemEventAction::MODIFIED;

            case efsw::Actions::Moved:
                return FileSystemEventAction::MOVED;

            default:
                return FileSystemEventAction::UNKNOWN;
        }
    }

    bool
    FileSystemListenerManager::dispatch_loop()
    {
        std::vector<FileSystemEvent> batch;
        batch.reserve(256);

        while (is_running.load() ||
               read_index.load() < write_index.load())
        {
            batch.clear();

            std::size_t local_read =
                read_index.load(std::memory_order_acquire);

            std::size_t local_write =
                write_index.load(std::memory_order_acquire);

            while (local_read < local_write &&
                   batch.size() < 256)
            {
                std::size_t slot_index =
                    local_read % queue_capacity;

                auto& slot = ring_buffer[slot_index];

                if (!slot.is_ready.load(
                    std::memory_order_acquire))
                {
                    break;
                }

                batch.push_back(
                    std::move(slot.event)
                );

                slot.is_ready.store(
                    false,
                    std::memory_order_release
                );

                ++local_read;
            }

            if (!batch.empty())
            {
                read_index.store(
                    local_read,
                    std::memory_order_release
                );

                notify_batch(batch);
            }
            else
            {
                std::this_thread::yield();
            }
        }

        return true;
    }

    bool
    FileSystemListenerManager::notify_batch(
        std::vector<FileSystemEvent>& batch
    )
    {
        for (auto& event : batch)
        {
            for (auto& listener : listeners)
            {
                listener(event);
            }
        }

        return true;
    }

    bool
    FileSystemListenerManager::passes_filter(
        const std::string& path,
        const FileSystemListenerManagerOptions& options
    )
    {
        if (!options.explicit_files.empty())
        {
            return options.explicit_files.find(path) !=
                   options.explicit_files.end();
        }

        if (!options.extensions.empty())
        {
            auto pos = path.find_last_of('.');

            if (pos == std::string::npos)
            {
                return false;
            }

            std::string ext = path.substr(pos);

            return options.extensions.find(ext) !=
                   options.extensions.end();
        }

        return true;
    }

    bool
    FileSystemListenerManager::resolve_full_path(
        const efsw::WatchID& watch_id,
        const std::string& directory,
        const std::string& filename,
        std::string& out_path
    )
    {
        auto it = watch_registry.find(watch_id);

        if (it == watch_registry.end())
        {
            return false;
        }

        out_path.clear();

        out_path.reserve(
            it->second.directory.size() +
            directory.size() +
            filename.size() + 2
        );

        out_path.append(it->second.directory);

        if (!directory.empty())
        {
            out_path.append("/");
            out_path.append(directory);
        }

        out_path.append("/");
        out_path.append(filename);

        return true;
    }

    bool
    FileSystemListenerManager::resolve_old_path(
        const efsw::WatchID& watch_id,
        const std::string& directory,
        const std::string& old_filename,
        std::string& out_path
    )
    {
        if (old_filename.empty())
        {
            out_path.clear();
            return true;
        }

        return resolve_full_path(
            watch_id,
            directory,
            old_filename,
            out_path
        );
    }
}

#endif
