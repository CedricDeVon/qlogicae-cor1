#include "pch.hpp"

#include "../includes/configuration_manager.hpp"

using namespace QLogicaeCppCore;

namespace QLogicaeCppCoreTest
{
	class ConfigurationManagerTest : public ::testing::Test
    {
    public:
        ConfigurationManagerTest()
        {
            ConfigurationManager::singleton.reset();
        }

        ~ConfigurationManagerTest() override
        {
            ConfigurationManager::singleton.reset();
        }
    };

    TEST_F(ConfigurationManagerTest, Should_ConstructSuccessfully_When_NoException)
    {
        ASSERT_TRUE(ConfigurationManager::singleton.construct());
    }

    TEST_F(ConfigurationManagerTest, Should_DestructSuccessfully_When_NoException)
    {
        ASSERT_TRUE(ConfigurationManager::singleton.destruct());
    }

    TEST_F(ConfigurationManagerTest, Should_SetupConfigurationsCorrectly_When_ValidInput)
    {
        ConfigurationManagerConfigurations configurations;
        configurations.is_enabled = true;
        configurations.is_thread_safety_enabled = false;

        ASSERT_TRUE(ConfigurationManager::singleton.setup(configurations));
        ASSERT_TRUE(ConfigurationManager::singleton.configurations.is_enabled);
        ASSERT_FALSE(ConfigurationManager::singleton.configurations.is_thread_safety_enabled);
    }

    TEST_F(ConfigurationManagerTest, Should_ResetConfigurationsToDefault_When_Called)
    {
        ConfigurationManagerConfigurations configurations;
        configurations.is_enabled = false;
        configurations.is_thread_safety_enabled = true;

        ConfigurationManager::singleton.setup(configurations);
        ASSERT_TRUE(ConfigurationManager::singleton.reset());
        ASSERT_TRUE(ConfigurationManager::singleton.configurations.is_enabled);
        ASSERT_FALSE(ConfigurationManager::singleton.configurations.is_thread_safety_enabled);
    }

    TEST_F(ConfigurationManagerTest, Should_UpdateDefaultConfigurations_When_SetupDefaultsCalled)
    {
        ConfigurationManagerConfigurations defaults;
        defaults.is_enabled = false;
        defaults.is_thread_safety_enabled = true;

        ConfigurationManager::singleton.setup_defaults(defaults);

        ASSERT_FALSE(ConfigurationManagerConfigurations::default_configurations.is_enabled);
        ASSERT_TRUE(ConfigurationManagerConfigurations::default_configurations.is_thread_safety_enabled);
    }

    TEST_F(ConfigurationManagerTest, Should_ResetDefaultConfigurations_When_ResetDefaultsCalled)
    {
        ConfigurationManagerConfigurations temp;
        temp.is_enabled = false;
        temp.is_thread_safety_enabled = true;

        ConfigurationManager::singleton.setup_defaults(temp);
        ConfigurationManager::singleton.reset_defaults<ConfigurationManagerConfigurations>();

        ASSERT_TRUE(ConfigurationManagerConfigurations::default_configurations.is_enabled);
        ASSERT_FALSE(ConfigurationManagerConfigurations::default_configurations.is_thread_safety_enabled);
    }

    class ConfigurationManagerParameterizedTest :
        public ConfigurationManagerTest,
        public ::testing::WithParamInterface<std::tuple<bool, bool>>
    {
    };

    TEST_P(ConfigurationManagerParameterizedTest, Should_WorkCorrectly_ForAllBooleanCombinations)
    {
        auto [enabled, thread_safety] = GetParam();

        ConfigurationManagerConfigurations configurations;
        configurations.is_enabled = enabled;
        configurations.is_thread_safety_enabled = thread_safety;

        ConfigurationManager::singleton.setup(configurations);

        ASSERT_EQ(ConfigurationManager::singleton.configurations.is_enabled, enabled);
        ASSERT_EQ(ConfigurationManager::singleton.configurations.is_thread_safety_enabled, thread_safety);
    }

    INSTANTIATE_TEST_CASE_P(
        BooleanCombinations,
        ConfigurationManagerParameterizedTest,
        ::testing::Values(
            std::make_tuple(true, true),
            std::make_tuple(true, false),
            std::make_tuple(false, true),
            std::make_tuple(false, false)
        )
    );

    TEST_F(ConfigurationManagerTest, Should_HandleSingletonAccessAcrossThreads_When_ThreadSafetyEnabled)
    {
        ConfigurationManagerConfigurations configurations;
        configurations.is_enabled = true;
        configurations.is_thread_safety_enabled = true;
        ConfigurationManager::singleton.setup(configurations);

        std::atomic<int> counter{0};
        auto task = []()
        {
            ConfigurationManagerConfigurations conf;
            conf.is_enabled = true;
            conf.is_thread_safety_enabled = true;
            ConfigurationManager::singleton.setup(conf);
        };

        std::vector<std::thread> threads;
        for (int i = 0; i < 32; ++i)
        {
            threads.emplace_back(task);
        }

        for (auto& t : threads)
        {
            t.join();
        }

        ASSERT_TRUE(ConfigurationManager::singleton.configurations.is_enabled);
        ASSERT_TRUE(ConfigurationManager::singleton.configurations.is_thread_safety_enabled);
    }

    TEST_F(ConfigurationManagerTest, Should_HandleMultipleConcurrentSetupResetCalls_WithoutRaceConditions)
    {
        auto setup_reset_task = []()
        {
            ConfigurationManagerConfigurations conf;
            conf.is_enabled = true;
            conf.is_thread_safety_enabled = false;

            for (int i = 0; i < 100; ++i)
            {
                ConfigurationManager::singleton.setup(conf);
                ConfigurationManager::singleton.reset();
            }
        };

        std::vector<std::thread> threads;
        for (int i = 0; i < 8; ++i)
        {
            threads.emplace_back(setup_reset_task);
        }

        for (auto& t : threads)
        {
            t.join();
        }

        ASSERT_TRUE(ConfigurationManager::singleton.configurations.is_enabled);
        ASSERT_FALSE(ConfigurationManager::singleton.configurations.is_thread_safety_enabled);
    }

    TEST_F(ConfigurationManagerTest, Should_CompleteUnderStress_When_CalledManyTimes)
    {
        ConfigurationManagerConfigurations conf;
        conf.is_enabled = true;
        conf.is_thread_safety_enabled = true;

        for (int i = 0; i < 1000; ++i)
        {
            ConfigurationManager::singleton.reset();
            ConfigurationManager::singleton.setup(conf);
        }

        ASSERT_TRUE(ConfigurationManager::singleton.configurations.is_enabled);
        ASSERT_TRUE(ConfigurationManager::singleton.configurations.is_thread_safety_enabled);
    }

    TEST_F(ConfigurationManagerTest, Should_HandleAsyncSetupReset_When_CalledViaStdAsync)
    {
        ConfigurationManagerConfigurations conf;
        conf.is_enabled = true;
        conf.is_thread_safety_enabled = true;

        auto future2 = std::async(std::launch::async, [&]()
        {
            for (int i = 0; i < 100; ++i)
            {
                ConfigurationManager::singleton.reset();
            }
        });

        future2.get();

        auto future1 = std::async(std::launch::async, [&]()
        {
            for (int i = 0; i < 100; ++i)
            {
                ConfigurationManager::singleton.setup(conf);
            }
        });

        future1.get();

        ASSERT_TRUE(ConfigurationManager::singleton.configurations.is_enabled);
        ASSERT_TRUE(ConfigurationManager::singleton.configurations.is_thread_safety_enabled);
    }

    TEST_F(ConfigurationManagerTest, Should_HandleEmptyConfigurations_When_SetupCalledWithDefault)
    {
        ConfigurationManagerConfigurations default_conf;
        ASSERT_TRUE(ConfigurationManager::singleton.setup(default_conf));

        ASSERT_TRUE(ConfigurationManager::singleton.configurations.is_enabled);
        ASSERT_FALSE(ConfigurationManager::singleton.configurations.is_thread_safety_enabled);
    }
}
