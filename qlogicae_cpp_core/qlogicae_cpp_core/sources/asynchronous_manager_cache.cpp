#include "pch.hpp"

#include "../includes/asynchronous_manager_cache.hpp"

namespace QLogicaeCppCore
{
    bool
        AsynchronousManagerCache::is_enabled =
            AsynchronousManagerConfigurations::default_is_enabled;

    std::shared_ptr<boost::asio::thread_pool>
        AsynchronousManagerCache::main_thread_pool =
            nullptr;

    std::shared_ptr<boost::asio::thread_pool>
        AsynchronousManagerCache::temporary_thread_pool =
            nullptr;

    AsynchronousManagerConfigurations
        AsynchronousManagerCache::configurations =
            {};

    AsynchronousManagerCache&
        AsynchronousManagerCache::instance =
            InstanceManager::instance
                .get_instance<AsynchronousManagerCache>();

    AsynchronousManagerCache::AsynchronousManagerCache()
    {
        _construct();
    }

    AsynchronousManagerCache::~AsynchronousManagerCache()
    {
        _destruct();
    }

    bool
        AsynchronousManagerCache::construct()
    {
        _construct();

        return ValueCache::boolean_1;
    }

    void
        AsynchronousManagerCache::_construct()
    {
        try
        {
            main_thread_pool =
                std::make_shared<boost::asio::thread_pool>(
                    std::thread::hardware_concurrency()
                );

            temporary_thread_pool =
                nullptr;

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
        AsynchronousManagerCache::destruct()
    {
        _destruct();

        return ValueCache::boolean_1;
    }

    void
        AsynchronousManagerCache::_destruct()
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
        AsynchronousManagerCache::setup(
            const AsynchronousManagerConfigurations&
                new_configurations
        )
    {
        configurations =
            new_configurations;

        _setup();

        return ValueCache::boolean_1;
    }

    bool
        AsynchronousManagerCache::setup()
    {
        configurations =
            {};

        _setup();

        return ValueCache::boolean_1;
    }

    void
        AsynchronousManagerCache::_setup()
    {
        try
        {
            is_enabled =
                AsynchronousManagerConfigurations::default_is_enabled =
                configurations.is_enabled;

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
        AsynchronousManagerCache::reset()
    {
        _reset();

        return ValueCache::boolean_1;
    }

    void
        AsynchronousManagerCache::_reset()
    {
        try
        {
            is_enabled =
                AsynchronousManagerConfigurations::default_is_enabled =
                AsynchronousManagerConfigurations::initial_is_enabled;

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
