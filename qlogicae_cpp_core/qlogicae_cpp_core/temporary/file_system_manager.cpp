#include "pch.hpp"

#include "../includes/file_system_manager.hpp"

namespace QLogicaeCppCore
{
    FileSystemManager&
        FileSystemManager::instance =
        InstanceManager::instance
        .get_instance<FileSystemManager>();

    FileSystemManager::FileSystemManager()
    {
        _construct();
    }

    FileSystemManager::~FileSystemManager()
    {
        _destruct();
    }

    bool
        FileSystemManager::construct()
    {
        _construct();

        return ValueCache::boolean_1;
    }

    void
        FileSystemManager::_construct()
    {
        try
        {
            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    bool
        FileSystemManager::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        FileSystemManager::_destruct()
    {
        try
        {
            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    bool
        FileSystemManager::setup()
    {
        _setup();

        return ValueCache::boolean_1;
    }

    void
        FileSystemManager::_setup()
    {
        try
        {
            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }

    bool
        FileSystemManager::reset()
    {
        _reset();

        return ValueCache::boolean_1;
    }

    void
        FileSystemManager::_reset()
    {
        try
        {
            ValueCache::boolean_1 =
                true;
        }
        catch (...)
        {
            ValueCache::boolean_1 =
                false;
        }
    }
}
