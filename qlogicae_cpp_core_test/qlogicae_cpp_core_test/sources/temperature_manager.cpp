#include "pch.hpp"

#include "qlogicae_cpp_core/includes/temperature_manager.hpp"

namespace QLogicaeCppCoreTest
{
    class TemperatureManagerTest :
        public ::testing::Test
    {
    public:
        TemperatureManagerTest()
        {
            QLogicaeCppCore::TemperatureManager::singleton.reset();
        }

        ~TemperatureManagerTest() override
        {
            QLogicaeCppCore::TemperatureManager::singleton.reset();
        }
    };

    struct TemperatureConversionParameters
    {
        double input_value;
        QLogicaeCppCore::TemperatureUnitType from_unit;
        QLogicaeCppCore::TemperatureUnitType to_unit;
        double expected_value;
    };

    class TemperatureManagerParameterizedTest :
        public ::testing::TestWithParam<
        TemperatureConversionParameters
        >
    {
    };

    TEST_F(
        TemperatureManagerTest,
        Should_ConstructSuccessfully_When_Created
    )
    {
        bool result =
            QLogicaeCppCore::TemperatureManager::singleton.construct();

        EXPECT_TRUE(result);
    }

    TEST_F(
        TemperatureManagerTest,
        Should_ResetDefaults_When_ResetIsCalled
    )
    {
        bool result =
            QLogicaeCppCore::TemperatureManager::singleton.reset();

        EXPECT_TRUE(result);
    }

    TEST_P(
        TemperatureManagerParameterizedTest,
        Should_CalculateCorrectly_When_ValidUnitsProvided
    )
    {
        const TemperatureConversionParameters parameters =
            GetParam();

        double result =
            QLogicaeCppCore::TemperatureManager::singleton.calculate(
                parameters.input_value,
                parameters.from_unit,
                parameters.to_unit
            );

        EXPECT_NEAR(result, parameters.expected_value, 0.0001);
    }

    TEST_F(
        TemperatureManagerTest,
        Should_NotModifyValue_When_Disabled
    )
    {
        QLogicaeCppCore::TemperatureManagerConfigurations configurations;

        configurations.is_enabled = false;

        QLogicaeCppCore::TemperatureManager::singleton.setup(
            configurations
        );

        double result =
            QLogicaeCppCore::TemperatureManager::singleton.calculate(
                100.0,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT
            );

        EXPECT_DOUBLE_EQ(result, 100.0);
    }

    TEST_F(
        TemperatureManagerTest,
        Should_CompleteAsyncCalculation_When_UsingStdAsync
    )
    {
        std::future<double> future_result =
            std::async(
                std::launch::async,
                []
                {
                    return
                        QLogicaeCppCore::TemperatureManager::singleton
                        .calculate(
                            0.0,
                            QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                            QLogicaeCppCore::TemperatureUnitType::KELVIN
                        );
                }
            );

        double result = future_result.get();

        EXPECT_DOUBLE_EQ(result, 273.15);
    }

    TEST_F(
        TemperatureManagerTest,
        Should_HandleConcurrentAccess_When_MultipleThreadsRun
    )
    {
        std::atomic<int> completion_counter = 0;
        std::mutex synchronization_mutex;

        std::vector<std::thread> worker_threads;

        for (int index = 0; index < 8; index++)
        {
            worker_threads.emplace_back(
                [&completion_counter, &synchronization_mutex]
                {
                    double result =
                        QLogicaeCppCore::TemperatureManager::singleton
                        .calculate(
                            100.0,
                            QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                            QLogicaeCppCore::TemperatureUnitType::KELVIN
                        );

                    {
                        std::lock_guard<std::mutex> lock(
                            synchronization_mutex
                        );

                        EXPECT_NEAR(result, 373.15, 0.0001);
                    }

                    completion_counter.fetch_add(1);
                }
            );
        }

        for (std::thread& worker_thread : worker_threads)
        {
            worker_thread.join();
        }

        EXPECT_EQ(completion_counter.load(), 8);
    }

    TEST_F(
        TemperatureManagerTest,
        Should_CompleteStressTest_When_ExecutedRepeatedly
    )
    {
        const auto start_time =
            std::chrono::steady_clock::now();

        for (int iteration = 0; iteration < 100000; iteration++)
        {
            double result =
                QLogicaeCppCore::TemperatureManager::singleton.calculate(
                    25.0,
                    QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                    QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT
                );

            EXPECT_NEAR(result, 77.0, 0.0001);
        }

        const auto end_time =
            std::chrono::steady_clock::now();

        const auto duration =
            std::chrono::duration_cast<
            std::chrono::milliseconds
            >(end_time - start_time);

        EXPECT_LT(duration.count(), 2000);
    }

    TEST_F(
        TemperatureManagerTest,
        Should_CompleteAsyncCalculation_When_UsingPromiseAndFuture
    )
    {
        std::promise<double> calculation_promise;

        std::future<double> calculation_future =
            calculation_promise.get_future();

        std::thread worker_thread(
            [&calculation_promise]
            {
                double result =
                    QLogicaeCppCore::TemperatureManager::singleton
                    .calculate(
                        10.0,
                        QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                        QLogicaeCppCore::TemperatureUnitType::KELVIN
                    );

                calculation_promise.set_value(result);
            }
        );

        double result = calculation_future.get();

        worker_thread.join();

        EXPECT_DOUBLE_EQ(result, 283.15);
    }

    TEST_F(
        TemperatureManagerTest,
        Should_SynchronizeThreads_When_UsingConditionVariable
    )
    {
        std::mutex synchronization_mutex;
        std::condition_variable synchronization_condition;
        bool is_ready = false;
        double calculated_value = 0.0;

        std::thread producer_thread(
            [&]
            {
                std::unique_lock<std::mutex> lock(
                    synchronization_mutex
                );

                calculated_value =
                    QLogicaeCppCore::TemperatureManager::singleton
                    .calculate(
                        0.0,
                        QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                        QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT
                    );

                is_ready = true;
                synchronization_condition.notify_one();
            }
        );

        std::thread consumer_thread(
            [&]
            {
                std::unique_lock<std::mutex> lock(
                    synchronization_mutex
                );

                synchronization_condition.wait(
                    lock,
                    [&]
                    {
                        return is_ready;
                    }
                );

                EXPECT_DOUBLE_EQ(calculated_value, 32.0);
            }
        );

        producer_thread.join();
        consumer_thread.join();
    }

    TEST_F(
        TemperatureManagerTest,
        Should_NotThrowException_When_InvalidEnumProvided
    )
    {
        EXPECT_NO_THROW(
            QLogicaeCppCore::TemperatureManager::singleton
            .calculate(
                100.0,
                static_cast<QLogicaeCppCore::TemperatureUnitType>(255),
                static_cast<QLogicaeCppCore::TemperatureUnitType>(255)
            )
        );
    }

    TEST_F(
        TemperatureManagerTest,
        Should_NotModifyValue_When_UnitTypeIsNone
    )
    {
        double result =
            QLogicaeCppCore::TemperatureManager::singleton
            .calculate(
                50.0,
                QLogicaeCppCore::TemperatureUnitType::NONE,
                QLogicaeCppCore::TemperatureUnitType::NONE
            );

        EXPECT_DOUBLE_EQ(result, 50.0);
    }

    TEST_F(
        TemperatureManagerTest,
        Should_HandleExtremeValues_When_MaximumDoubleUsed
    )
    {
        const double maximum_value =
            std::numeric_limits<double>::max();

        double result =
            QLogicaeCppCore::TemperatureManager::singleton
            .calculate(
                maximum_value,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS
            );

        EXPECT_DOUBLE_EQ(result, maximum_value);
    }

    TEST_F(
        TemperatureManagerTest,
        Should_HandleNegativeValues_When_BelowAbsoluteZeroProvided
    )
    {
        double result =
            QLogicaeCppCore::TemperatureManager::singleton
            .calculate(
                -500.0,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                QLogicaeCppCore::TemperatureUnitType::KELVIN
            );

        EXPECT_NEAR(result, -226.85, 0.0001);
    }

    TEST_F(
        TemperatureManagerTest,
        Should_UseDefaults_When_EmptyConfigurationProvided
    )
    {
        QLogicaeCppCore::TemperatureManagerConfigurations
            empty_configurations;

        QLogicaeCppCore::TemperatureManager::singleton
            .setup(empty_configurations);

        double result =
            QLogicaeCppCore::TemperatureManager::singleton
            .calculate(
                empty_configurations
            );

        EXPECT_DOUBLE_EQ(result, 0.0);
    }

    TEST_F(
        TemperatureManagerTest,
        Should_RemainStable_When_SetupAndResetRepeatedConcurrently
    )
    {
        std::atomic<int> completion_counter = 0;

        std::vector<std::thread> worker_threads;

        for (int iteration = 0; iteration < 16; iteration++)
        {
            worker_threads.emplace_back(
                [&completion_counter]
                {
                    QLogicaeCppCore::TemperatureManager::singleton
                        .setup();

                    QLogicaeCppCore::TemperatureManager::singleton
                        .reset();

                    double result =
                        QLogicaeCppCore::TemperatureManager::singleton
                        .calculate(
                            20.0,
                            QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                            QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT
                        );

                    EXPECT_NEAR(result, 68.0, 0.0001);

                    completion_counter.fetch_add(1);
                }
            );
        }

        for (std::thread& worker_thread : worker_threads)
        {
            worker_thread.join();
        }

        EXPECT_EQ(completion_counter.load(), 16);
    }

    INSTANTIATE_TEST_CASE_P(
        TemperatureConversions,
        TemperatureManagerParameterizedTest,
        ::testing::Values(
            TemperatureConversionParameters
            {
                0.0,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT,
                32.0
            },
            TemperatureConversionParameters
            {
                100.0,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT,
                212.0
            },
            TemperatureConversionParameters
            {
                -40.0,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT,
                -40.0
            },
            TemperatureConversionParameters
            {
                0.0,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                QLogicaeCppCore::TemperatureUnitType::KELVIN,
                273.15
            },
            TemperatureConversionParameters
            {
                100.0,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                QLogicaeCppCore::TemperatureUnitType::KELVIN,
                373.15
            },
            TemperatureConversionParameters
            {
                -273.15,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                QLogicaeCppCore::TemperatureUnitType::KELVIN,
                0.0
            },
            TemperatureConversionParameters
            {
                32.0,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                0.0
            },
            TemperatureConversionParameters
            {
                212.0,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                100.0
            },
            TemperatureConversionParameters
            {
                -40.0,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                -40.0
            },
            TemperatureConversionParameters
            {
                32.0,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT,
                QLogicaeCppCore::TemperatureUnitType::KELVIN,
                273.15
            },
            TemperatureConversionParameters
            {
                212.0,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT,
                QLogicaeCppCore::TemperatureUnitType::KELVIN,
                373.15
            },
            TemperatureConversionParameters
            {
                273.15,
                QLogicaeCppCore::TemperatureUnitType::KELVIN,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                0.0
            },
            TemperatureConversionParameters
            {
                373.15,
                QLogicaeCppCore::TemperatureUnitType::KELVIN,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                100.0
            },
            TemperatureConversionParameters
            {
                0.0,
                QLogicaeCppCore::TemperatureUnitType::KELVIN,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                -273.15
            },
            TemperatureConversionParameters
            {
                273.15,
                QLogicaeCppCore::TemperatureUnitType::KELVIN,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT,
                32.0
            },
            TemperatureConversionParameters
            {
                373.15,
                QLogicaeCppCore::TemperatureUnitType::KELVIN,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT,
                212.0
            },
            TemperatureConversionParameters
            {
                0.0,
                QLogicaeCppCore::TemperatureUnitType::KELVIN,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT,
                -459.67
            },
            TemperatureConversionParameters
            {
                25.0,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                QLogicaeCppCore::TemperatureUnitType::CELSIUS,
                25.0
            },
            TemperatureConversionParameters
            {
                77.0,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT,
                QLogicaeCppCore::TemperatureUnitType::FAHRENHEIT,
                77.0
            },
            TemperatureConversionParameters
            {
                300.0,
                QLogicaeCppCore::TemperatureUnitType::KELVIN,
                QLogicaeCppCore::TemperatureUnitType::KELVIN,
                300.0
            }
        )
    );
}
