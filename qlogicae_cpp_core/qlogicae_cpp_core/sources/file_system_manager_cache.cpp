#include "pch.hpp"

#include "../includes/file_system_manager_cache.hpp"

namespace QLogicaeCppCore
{
    FileSystemManagerCache&
        FileSystemManagerCache::instance =
            InstanceManager::instance
                .get_instance<FileSystemManagerCache>();

    FileSystemManagerCache::FileSystemManagerCache()
    {
        _construct();
    }

    FileSystemManagerCache::~FileSystemManagerCache()
    {
        _destruct();
    }

    bool
        FileSystemManagerCache::construct()
    {
        _construct();

        return ValueCache::boolean_1;
    }

    void
        FileSystemManagerCache::_construct()
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
        FileSystemManagerCache::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        FileSystemManagerCache::_destruct()
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
        FileSystemManagerCache::setup()
    {
        _setup();

        return ValueCache::boolean_1;
    }

    void
        FileSystemManagerCache::_setup()
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
        FileSystemManagerCache::reset()
    {
        _reset();

        return ValueCache::boolean_1;
    }

    void
        FileSystemManagerCache::_reset()
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
