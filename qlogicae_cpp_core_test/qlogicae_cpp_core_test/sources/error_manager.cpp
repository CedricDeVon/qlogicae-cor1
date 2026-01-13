#include "pch.hpp"

#include "../includes/error_manager.hpp"

namespace QLogicaeCppCoreTest
{
    class ErrorManagerTest :
        public ::testing::Test
    {
    public:
        ErrorManagerTest()
        {
            QLogicaeCppCore::ErrorManager::singleton.reset();
        }

        ~ErrorManagerTest() override
        {
            QLogicaeCppCore::ErrorManager::singleton.reset();
        }
    };

    class ErrorManagerParameterizedTest :
        public ::testing::TestWithParam<bool>
    {
    public:
        ErrorManagerParameterizedTest()
        {
            QLogicaeCppCore::ErrorManager::singleton.reset();
        }

        ~ErrorManagerParameterizedTest() override
        {
            QLogicaeCppCore::ErrorManager::singleton.reset();
        }
    };

    class ErrorManagerConfigurationMatrixTest :
        public ::testing::TestWithParam<
        std::tuple<bool, bool, bool>
        >
    {
    public:
        ErrorManagerConfigurationMatrixTest()
        {
            QLogicaeCppCore::ErrorManager::singleton.reset();
        }

        ~ErrorManagerConfigurationMatrixTest() override
        {
            QLogicaeCppCore::ErrorManager::singleton.reset();
        }
    };

    class ErrorManagerFullParameterizedTest :
        public ::testing::TestWithParam<std::tuple<
        bool,
        bool,
        bool,
        bool,
        bool,
        bool
        >>
    {
    public:
        ErrorManagerFullParameterizedTest()
        {
            QLogicaeCppCore::ErrorManager::singleton.reset();
        }

        ~ErrorManagerFullParameterizedTest() override
        {
            QLogicaeCppCore::ErrorManager::singleton.reset();
        }
    };

    TEST(ErrorManagerTest,
        Should_ConstructSuccessfully_When_Created)
    {
        bool result =
            QLogicaeCppCore::ErrorManager::singleton.construct();

        EXPECT_TRUE(result);
    }

    TEST(ErrorManagerTest,
        Should_ResetToInitialState_When_ResetCalled)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            false;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        QLogicaeCppCore::ErrorManager::singleton.reset();

        EXPECT_EQ(
            QLogicaeCppCore::ErrorManagerConfigurations::cache_is_enabled,
            QLogicaeCppCore::ErrorManagerConfigurations::initial_is_enabled
        );
    }

    TEST(ErrorManagerTest,
        Should_HandleSynchronously_When_AsynchronousDisabled)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            true;

        configurations.is_runtime_throw_output_enabled =
            false;

        configurations.is_asynchronous_output_enabled =
            false;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        bool result =
            QLogicaeCppCore::ErrorManager::singleton.handle(
                "title",
                "message"
            );

        EXPECT_FALSE(result);
    }

    TEST(ErrorManagerTest,
        Should_HandleAsynchronously_When_AsynchronousEnabled)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            true;

        configurations.is_asynchronous_output_enabled =
            true;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        bool result =
            QLogicaeCppCore::ErrorManager::singleton.handle(
                "message"
            );

        EXPECT_FALSE(result);
    }

    TEST(ErrorManagerTest,
        Should_NotHandle_When_Disabled)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            false;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        bool result =
            QLogicaeCppCore::ErrorManager::singleton.handle(
                "message"
            );

        EXPECT_FALSE(result);
    }

    TEST(ErrorManagerTest,
        Should_ThrowRuntimeError_When_RuntimeThrowEnabled)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            true;

        configurations.is_asynchronous_output_enabled =
            false;

        configurations.is_runtime_throw_output_enabled =
            true;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        EXPECT_THROW(
            QLogicaeCppCore::ErrorManager::singleton.handle(
                "message"
            ),
            std::runtime_error
        );
    }

    TEST(ErrorManagerTest,
        Should_HandleExceptionInput_When_ExceptionPassed)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            false;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        try
        {
            throw std::logic_error(
                "failure"
            );
        }
        catch (
            const std::exception&
            exception
            )
        {
            bool result =
                QLogicaeCppCore::ErrorManager::singleton.handle(
                    exception
                );

            EXPECT_FALSE(result);
        }
    }

    TEST(ErrorManagerTest,
        Should_BeThreadSafe_When_MultipleThreadsInvokeHandle)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            true;

        configurations.is_asynchronous_output_enabled =
            true;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        std::atomic<bool>
            completed =
            false;

        std::thread worker_thread(
            [&]()
            {
                for (
                    std::size_t iteration_index = 0;
                    iteration_index < 1000;
                    iteration_index++
                    )
                {
                    QLogicaeCppCore::ErrorManager::singleton.handle(
                        "message"
                    );
                }

                completed.store(
                    true
                );
            }
        );

        worker_thread.join();

        EXPECT_TRUE(
            completed.load()
        );
    }

    TEST(ErrorManagerTest,
        Should_CompleteUnderTimeLimit_When_StressTested)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            false;

        configurations.is_runtime_throw_output_enabled =
            false;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        auto start_time =
            std::chrono::steady_clock::now();

        for (
            std::size_t iteration_index = 0;
            iteration_index < 10000;
            iteration_index++
            )
        {
            QLogicaeCppCore::ErrorManager::singleton.handle(
                "message"
            );
        }

        auto end_time =
            std::chrono::steady_clock::now();

        auto duration =
            std::chrono::duration_cast<
            std::chrono::seconds
            >(
                end_time - start_time
            ).count();

        EXPECT_LT(
            duration,
            2
        );
    }

    TEST_P(ErrorManagerParameterizedTest,
        Should_HandleCorrectly_When_AsynchronousFlagVaries)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            true;

        configurations.is_runtime_throw_output_enabled =
            false;

        configurations.is_asynchronous_output_enabled =
            GetParam();

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        bool result =
            QLogicaeCppCore::ErrorManager::singleton.handle(
                "message"
            );

        EXPECT_FALSE(result);
    }

    INSTANTIATE_TEST_CASE_P(
        ErrorManagerAsyncVariants,
        ErrorManagerParameterizedTest,
        ::testing::Values(
            true,
            false
        )
    );

    TEST_P(ErrorManagerFullParameterizedTest,
        Should_HandleAllCombinationsCorrectly)
    {
        auto [is_enabled,
            is_async,
            is_runtime_throw,
            is_console,
            is_file,
            is_gui] = GetParam();

        QLogicaeCppCore::ErrorManagerConfigurations configurations;
        configurations.is_enabled = is_enabled;
        configurations.is_asynchronous_output_enabled = is_async;
        configurations.is_runtime_throw_output_enabled = is_runtime_throw;
        configurations.is_console_output_enabled = is_console;
        configurations.is_file_output_enabled = is_file;
        configurations.is_gui_output_enabled = is_gui;
        configurations.is_asynchronous_console_output_enabled = is_async;
        configurations.is_asynchronous_file_output_enabled = is_async;
        configurations.is_asynchronous_gui_output_enabled = is_async;
        configurations.is_asynchronous_runtime_throw_output_enabled = is_async;

        std::vector<std::string> temp_paths;
        if (is_file)
        {
            for (int i = 0; i < 2; ++i)
            {
                std::string file_path = "temp_full_param_test_" + std::to_string(i) + ".log";
                std::ofstream(file_path).close();
                temp_paths.push_back(file_path);
            }
            configurations.full_file_output_paths = temp_paths;
        }

        QLogicaeCppCore::ErrorManager::singleton.setup(configurations);

        bool caught_exception = false;
        try
        {
            QLogicaeCppCore::ErrorManager::singleton.handle("full_matrix_test");
        }
        catch (const std::runtime_error&)
        {
            caught_exception = true;
        }

        if (is_enabled && is_runtime_throw)
        {
            EXPECT_TRUE(caught_exception);
        }
        else
        {
            EXPECT_FALSE(caught_exception);
        }

        for (const std::string& path : temp_paths)
        {
            std::filesystem::remove(path);
        }
    }

    INSTANTIATE_TEST_CASE_P(
        ErrorManagerFullMatrix,
        ErrorManagerFullParameterizedTest,
        ::testing::Combine(
            ::testing::Bool(), 
            ::testing::Bool(), 
            ::testing::Bool(), 
            ::testing::Bool(), 
            ::testing::Bool(), 
            ::testing::Bool()  
        )
    );

    TEST(ErrorManagerTest,
        Should_HandleConcurrentContention_When_FourThreadsInvoke)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            true;

        configurations.is_thread_safety_enabled =
            true;

        configurations.is_asynchronous_output_enabled =
            true;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        std::atomic<std::size_t>
            completed_count =
            0;

        auto worker =
            [&]()
            {
                for (
                    std::size_t iteration_index = 0;
                    iteration_index < 500;
                    iteration_index++
                    )
                {
                    QLogicaeCppCore::ErrorManager::singleton.handle(
                        "message"
                    );
                }

                completed_count.fetch_add(
                    static_cast<std::size_t>(1)
                );
            };

        std::thread first_thread(worker);
        std::thread second_thread(worker);
        std::thread third_thread(worker);
        std::thread fourth_thread(worker);

        first_thread.join();
        second_thread.join();
        third_thread.join();
        fourth_thread.join();

        EXPECT_EQ(
            completed_count.load(),
            static_cast<std::size_t>(4)
        );
    }

    TEST(ErrorManagerTest,
        Should_CaptureAsyncException_When_RuntimeThrowEnabledAsync)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            true;

        configurations.is_asynchronous_output_enabled =
            true;

        configurations.is_asynchronous_runtime_throw_output_enabled =
            true;

        configurations.is_runtime_throw_output_enabled =
            true;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        EXPECT_THROW(
            QLogicaeCppCore::ErrorManager::singleton.handle(
                "async_exception"
            ),
            std::runtime_error
        );
    }

    TEST(ErrorManagerTest,
        Should_HandleInvalidFilePath_When_FileOutputEnabled)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            true;

        configurations.is_file_output_enabled =
            true;

        configurations.is_runtime_throw_output_enabled =
            false;

        configurations.full_file_output_paths =
        {
            std::string(4096, '\0')
        };

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        bool result =
            QLogicaeCppCore::ErrorManager::singleton.handle(
                "invalid_path"
            );

        EXPECT_FALSE(result);
    }

    TEST(ErrorManagerTest,
        Should_HandleEmptyMessage_When_MessageIsEmpty)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            false;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        bool result =
            QLogicaeCppCore::ErrorManager::singleton.handle(
                ""
            );

        EXPECT_FALSE(result);
    }

    TEST(ErrorManagerTest,
        Should_HandleVeryLargeMessage_When_MessageIsLarge)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            true;

        configurations.is_runtime_throw_output_enabled =
            false;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        std::string
            large_message(
                static_cast<std::size_t>(1000),
                'A'
            );

        bool result =
            QLogicaeCppCore::ErrorManager::singleton.handle(
                large_message
            );

        EXPECT_FALSE(result);
    }

    TEST_P(ErrorManagerConfigurationMatrixTest,
        Should_HandleConfigurationMatrix_When_ParametersVary)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            std::get<0>(GetParam());

        configurations.is_asynchronous_output_enabled =
            std::get<1>(GetParam());

        configurations.is_runtime_throw_output_enabled =
            std::get<2>(GetParam());

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        if (configurations.is_enabled &&
            configurations.is_runtime_throw_output_enabled &&
            !configurations.is_asynchronous_output_enabled)
        {
            EXPECT_THROW(
                QLogicaeCppCore::ErrorManager::singleton.handle(
                    "matrix"
                ),
                std::runtime_error
            );
        }
        else
        {
            bool result =
                QLogicaeCppCore::ErrorManager::singleton.handle(
                    "matrix"
                );

            EXPECT_FALSE(result);
        }
    }

    INSTANTIATE_TEST_CASE_P(
        ErrorManagerConfigurationMatrix,
        ErrorManagerConfigurationMatrixTest,
        ::testing::Values(
            std::make_tuple(false, false, false),
            std::make_tuple(true, false, false),
            std::make_tuple(true, true, false),
            std::make_tuple(true, false, true),
            std::make_tuple(true, true, true)
        )
    );

    TEST(ErrorManagerTest,
        Should_ReturnSameInstance_When_GettingSingletonMultipleTimes)
    {
        QLogicaeCppCore::ErrorManager&
            first_reference =
            QLogicaeCppCore::ErrorManager::singleton;

        QLogicaeCppCore::ErrorManager&
            second_reference =
            QLogicaeCppCore::ErrorManager::singleton;

        EXPECT_EQ(
            &first_reference,
            &second_reference
        );
    }

    TEST(ErrorManagerTest,
        Should_NotCrash_When_ResetAndSetupRaceOccurs)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            true;

        std::atomic<bool>
            completed =
            false;

        std::thread setup_thread(
            [&]()
            {
                for (
                    std::size_t iteration_index = 0;
                    iteration_index < 500;
                    iteration_index++
                    )
                {
                    QLogicaeCppCore::ErrorManager::singleton.setup(
                        configurations
                    );
                }
            }
        );

        std::thread reset_thread(
            [&]()
            {
                for (
                    std::size_t iteration_index = 0;
                    iteration_index < 500;
                    iteration_index++
                    )
                {
                    QLogicaeCppCore::ErrorManager::singleton.reset();
                }

                completed.store(
                    true
                );
            }
        );

        setup_thread.join();
        reset_thread.join();

        EXPECT_TRUE(
            completed.load()
        );
    }

    TEST(ErrorManagerTest,
        Should_HandleReentrantCalls_When_HandleIsCalledRecursively)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            true;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        std::function<void(std::size_t)>
            recursive_handle;

        recursive_handle =
            [&](std::size_t depth)
            {
                if (depth == 0)
                {
                    return;
                }

                QLogicaeCppCore::ErrorManager::singleton.handle(
                    "reentrant"
                );

                recursive_handle(
                    depth - 1
                );
            };

        bool result =
            false;

        try
        {
            recursive_handle(
                static_cast<std::size_t>(10)
            );
        }
        catch (...)
        {
            result =
                false;
        }

        EXPECT_FALSE(result);
    }

    TEST(ErrorManagerTest,
        Should_ThrowAsyncRuntimeError_When_AsyncAndRuntimeThrowEnabled)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled =
            true;

        configurations.is_asynchronous_output_enabled =
            true;

        configurations.is_asynchronous_runtime_throw_output_enabled =
            true;

        configurations.is_runtime_throw_output_enabled =
            true;

        QLogicaeCppCore::ErrorManager::singleton.setup(
            configurations
        );

        EXPECT_THROW(
            QLogicaeCppCore::ErrorManager::singleton.handle(
                "async_runtime_throw"
            ),
            std::runtime_error
        );
    }

    TEST(ErrorManagerTest,
        Should_HandleGuiOutput_When_GuiEnabled)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled = true;
        configurations.is_gui_output_enabled = true;
        configurations.is_asynchronous_gui_output_enabled = false;
        configurations.is_runtime_throw_output_enabled = false;

        QLogicaeCppCore::ErrorManager::singleton.setup(configurations);

        bool result = QLogicaeCppCore::ErrorManager::singleton.handle("gui_message");

        EXPECT_FALSE(result);
    }

    TEST(ErrorManagerTest,
        Should_HandleAsyncGuiOutput_When_AsynchronousGuiEnabled)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled = true;
        configurations.is_gui_output_enabled = true;
        configurations.is_asynchronous_gui_output_enabled = true;
        configurations.is_asynchronous_output_enabled = true;
        configurations.is_runtime_throw_output_enabled = false;

        QLogicaeCppCore::ErrorManager::singleton.setup(configurations);

        bool result = QLogicaeCppCore::ErrorManager::singleton.handle("async_gui_message");

        EXPECT_FALSE(result);
    }

    TEST(ErrorManagerTest,
        Should_HandleMultipleFilePaths_When_FileOutputEnabled)
    {
        std::vector<std::string> temp_paths;
        for (int i = 0; i < 2; ++i)
        {
            std::string file_path = "temp_error_" + std::to_string(i) + ".log";
            std::ofstream(file_path).close();
            temp_paths.push_back(file_path);
        }

        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled = true;
        configurations.is_file_output_enabled = true;
        configurations.full_file_output_paths = temp_paths;
        configurations.is_runtime_throw_output_enabled = false;

        QLogicaeCppCore::ErrorManager::singleton.setup(configurations);

        bool result = QLogicaeCppCore::ErrorManager::singleton.handle("file_message");

        EXPECT_FALSE(result);

        for (const std::string& path : temp_paths)
        {
            std::filesystem::remove(path);
        }
    }

    TEST(ErrorManagerTest,
        Should_HandleInternalExceptionsDuringConstruct)
    {
        struct FaultyConfigurations : QLogicaeCppCore::ErrorManagerConfigurations
        {
            FaultyConfigurations()
            {
                is_enabled = true;
            }
        };

        QLogicaeCppCore::ErrorManagerConfigurations configurations = FaultyConfigurations();

        bool result = QLogicaeCppCore::ErrorManager::singleton.construct(configurations);

        EXPECT_TRUE(result);
    }

    TEST(ErrorManagerTest,
        Should_HandleInternalExceptionsDuringSetup)
    {
        struct FaultyConfigurations : QLogicaeCppCore::ErrorManagerConfigurations
        {
            FaultyConfigurations()
            {
                is_enabled = true;
            }
        };

        QLogicaeCppCore::ErrorManagerConfigurations configurations = FaultyConfigurations();

        bool result = QLogicaeCppCore::ErrorManager::singleton.setup(configurations);

        EXPECT_TRUE(result);
    }

    TEST(ErrorManagerTest,
        Should_HandleInternalExceptionsDuringDestruct)
    {
        struct FaultyConfigurations : QLogicaeCppCore::ErrorManagerConfigurations
        {
            FaultyConfigurations()
            {
                is_enabled = true;
            }
        };

        QLogicaeCppCore::ErrorManagerConfigurations configurations = FaultyConfigurations();

        bool result = QLogicaeCppCore::ErrorManager::singleton.destruct(configurations);

        EXPECT_TRUE(result);
    }

    TEST(ErrorManagerTest,
        Should_HandleInternalExceptionsDuringReset)
    {
        struct FaultyConfigurations : QLogicaeCppCore::ErrorManagerConfigurations
        {
            FaultyConfigurations()
            {
                is_enabled = true;
            }
        };

        QLogicaeCppCore::ErrorManagerConfigurations configurations = FaultyConfigurations();

        bool result = QLogicaeCppCore::ErrorManager::singleton.reset(configurations);

        EXPECT_TRUE(result);
    }

    TEST(ErrorManagerTest,
        Should_UpdateCacheVariablesCorrectly_AfterHandle)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;

        configurations.is_enabled = true;
        configurations.is_runtime_throw_output_enabled = false;
        configurations.is_asynchronous_output_enabled = false;

        QLogicaeCppCore::ErrorManager::singleton.setup(configurations);

        QLogicaeCppCore::ErrorManager::singleton.handle("cache_test");

        EXPECT_EQ(QLogicaeCppCore::ErrorManager::cache_error_log, "cache_test");
        EXPECT_FALSE(QLogicaeCppCore::ErrorManager::cache_boolean_1);
    }

    TEST(ErrorManagerTest,
        Should_HandleTitleAndMessageCorrectly)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;
        configurations.is_enabled = true;
        configurations.is_runtime_throw_output_enabled = false;
        configurations.is_asynchronous_output_enabled = false;
        QLogicaeCppCore::ErrorManager::singleton.setup(configurations);

        bool result =
            QLogicaeCppCore::ErrorManager::singleton.handle(
                "ErrorTitle",
                "ErrorMessage"
            );

        EXPECT_FALSE(result);
    }

    TEST(ErrorManagerTest,
        Should_HandleGUIOutputWhenEnabled)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;
        configurations.is_enabled = true;
        configurations.is_gui_output_enabled = true;
        configurations.is_asynchronous_gui_output_enabled = false;
        configurations.is_runtime_throw_output_enabled = false;
        QLogicaeCppCore::ErrorManager::singleton.setup(configurations);

        bool result =
            QLogicaeCppCore::ErrorManager::singleton.handle(
                "GUI message"
            );

        EXPECT_FALSE(result);
    }

    TEST(ErrorManagerTest,
        Should_HandleGUIOutputAsyncWhenEnabled)
    {
        QLogicaeCppCore::ErrorManagerConfigurations configurations;
        configurations.is_enabled = true;
        configurations.is_gui_output_enabled = true;
        configurations.is_asynchronous_gui_output_enabled = true;
        configurations.is_runtime_throw_output_enabled = false;
        configurations.is_asynchronous_output_enabled = true;
        QLogicaeCppCore::ErrorManager::singleton.setup(configurations);

        bool result =
            QLogicaeCppCore::ErrorManager::singleton.handle(
                "GUI async message"
            );

        EXPECT_FALSE(result);
    }
}
