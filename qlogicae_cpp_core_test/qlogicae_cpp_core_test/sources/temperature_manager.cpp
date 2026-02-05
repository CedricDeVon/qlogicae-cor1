#include "pch.hpp"

#include "qlogicae_cpp_core/includes/temperature_manager.hpp"

namespace
	QLogicaeCppCoreTest
{
	struct
		TemperatureConversionParameters
	{
		double
			input_value;

		QLogicaeCppCore::TemperatureUnit
			original_unit;

		QLogicaeCppCore::TemperatureUnit
			target_unit;

		double
			expected_value;
	};

	class
		TemperatureManagerTest :
		public ::testing::Test
	{
	public:
		QLogicaeCppCore::TemperatureManager
			temperature_manager;

		void
			SetUp() override
		{
			temperature_manager.construct();
			temperature_manager.reset();
		}

		void
			TearDown() override
		{
			temperature_manager.destruct();
			temperature_manager.reset();
		}
	};

	class
		TemperatureManagerParameterizedTest :
		public TemperatureManagerTest,
		public ::testing::WithParamInterface<
		TemperatureConversionParameters
		>
	{
	};

	TEST_F(
		TemperatureManagerTest,
		Should_ReturnSameValue_When_UnitsAreEqual
	)
	{
		double
			input_value =
			25.0;

		double
			result =
			temperature_manager
			.convert_unit(
				input_value,
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS,
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS
			);

		EXPECT_DOUBLE_EQ(
			result,
			input_value
		);
	}

	TEST_F(
		TemperatureManagerTest,
		Should_UseConfiguredUnits_When_NoUnitsProvided
	)
	{
		QLogicaeCppCore
			::TemperatureManagerConfigurations
			configurations;

		configurations
			.original_unit =
			QLogicaeCppCore
			::TemperatureUnit
			::FAHRENHEIT;

		configurations
			.target_unit =
			QLogicaeCppCore
			::TemperatureUnit
			::CELSIUS;

		temperature_manager
			.setup(
				configurations
			);

		double
			result =
			temperature_manager
			.convert_unit(
				32.0
			);

		EXPECT_DOUBLE_EQ(
			result,
			0.0
		);
	}

	TEST_P(
		TemperatureManagerParameterizedTest,
		Should_ConvertCorrectly_When_ValidParametersProvided
	)
	{
		TemperatureConversionParameters
			parameters =
			GetParam();

		double
			result =
			temperature_manager
			.convert_unit(
				parameters.input_value,
				parameters.original_unit,
				parameters.target_unit
			);

		EXPECT_NEAR(
			result,
			parameters.expected_value,
			1e-12
		);
	}

	INSTANTIATE_TEST_CASE_P(
		TemperatureManagerConversions,
		TemperatureManagerParameterizedTest,
		::testing::Values(
			TemperatureConversionParameters
			{
				0.0,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				32.0
			},
			TemperatureConversionParameters
			{
				100.0,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				212.0
			},
			TemperatureConversionParameters
			{
				-40.0,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				-40.0
			},
			TemperatureConversionParameters
			{
				0.0,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				273.15
			},
			TemperatureConversionParameters
			{
				100.0,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				373.15
			},
			TemperatureConversionParameters
			{
				-273.15,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				0.0
			},
			TemperatureConversionParameters
			{
				32.0,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				0.0
			},
			TemperatureConversionParameters
			{
				212.0,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				100.0
			},
			TemperatureConversionParameters
			{
				-40.0,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				-40.0
			},
			TemperatureConversionParameters
			{
				32.0,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				273.15
			},
			TemperatureConversionParameters
			{
				212.0,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				373.15
			},
			TemperatureConversionParameters
			{
				-459.67,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				0.0
			},
			TemperatureConversionParameters
			{
				273.15,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				0.0
			},
			TemperatureConversionParameters
			{
				373.15,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				100.0
			},
			TemperatureConversionParameters
			{
				0.0,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				-273.15
			},
			TemperatureConversionParameters
			{
				273.15,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				32.0
			},
			TemperatureConversionParameters
			{
				373.15,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				212.0
			},
			TemperatureConversionParameters
			{
				0.0,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				-459.67
			},
			TemperatureConversionParameters
			{
				25.5,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				77.9
			},
			TemperatureConversionParameters
			{
				77.9,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				25.5
			},
			TemperatureConversionParameters
			{
				25.5,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				298.65
			},
			TemperatureConversionParameters
			{
				298.65,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				25.5
			},
			TemperatureConversionParameters
			{
				1234.56,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				QLogicaeCppCore::TemperatureUnit::CELSIUS,
				1234.56
			},
			TemperatureConversionParameters
			{
				-999.99,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				QLogicaeCppCore::TemperatureUnit::FAHRENHEIT,
				-999.99
			},
			TemperatureConversionParameters
			{
				555.55,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				QLogicaeCppCore::TemperatureUnit::KELVIN,
				555.55
			}
		)
	);

	TEST_F(
		TemperatureManagerTest,
		Should_HandleInvalidEnumGracefully_When_InvalidUnitProvided
	)
	{
		double
			result =
			temperature_manager
			.convert_unit(
				10.0,
				static_cast<
				QLogicaeCppCore
				::TemperatureUnit
				>(
					255
					),
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS
			);

		EXPECT_DOUBLE_EQ(
			result,
			10.0
		);
	}

	TEST_F(
		TemperatureManagerTest,
		Should_NotThrow_When_CalledConcurrently
	)
	{
		std::atomic<bool>
			completed =
			false;

		std::thread
			worker_thread =
			std::thread(
				[&]()
				{
					for
						(
							std::size_t
							iteration = 0;
							iteration < 10000;
							++iteration
							)
					{
						temperature_manager
							.convert_unit(
								100.0,
								QLogicaeCppCore
								::TemperatureUnit
								::CELSIUS,
								QLogicaeCppCore
								::TemperatureUnit
								::FAHRENHEIT
							);
					}

					completed =
						true;
				}
			);

		worker_thread
			.join();

		EXPECT_TRUE(
			completed
		);
	}

	TEST_F(
		TemperatureManagerTest,
		Should_ExecuteAsynchronously_When_UsingStdAsync
	)
	{
		std::future<double>
			result_future =
			std::async(
				std::launch::async,
				[&]()
				{
					return
						temperature_manager
						.convert_unit(
							0.0,
							QLogicaeCppCore
							::TemperatureUnit
							::CELSIUS,
							QLogicaeCppCore
							::TemperatureUnit
							::KELVIN
						);
				}
			);

		EXPECT_DOUBLE_EQ(
			result_future.get(),
			273.15
		);
	}

	TEST_F(
		TemperatureManagerTest,
		Should_HandleExtremeValues_When_DoubleLimitsProvided
	)
	{
		double
			max_value =
			std::numeric_limits<double>
			::max();

		double
			result =
			temperature_manager
			.convert_unit(
				max_value,
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS,
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS
			);

		EXPECT_DOUBLE_EQ(
			result,
			max_value
		);
	}

	TEST_F(
		TemperatureManagerTest,
		Should_HandleLowestDoubleValue_When_MinimumDoubleProvided
	)
	{
		double
			minimum_value =
			std::numeric_limits<double>
			::lowest();

		double
			result =
			temperature_manager
			.convert_unit(
				minimum_value,
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS,
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS
			);

		EXPECT_DOUBLE_EQ(
			result,
			minimum_value
		);
	}

	TEST_F(
		TemperatureManagerTest,
		Should_HandleNaNValue_When_NaNProvided
	)
	{
		double
			nan_value =
			std::numeric_limits<double>
			::quiet_NaN();

		double
			result =
			temperature_manager
			.convert_unit(
				nan_value,
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS,
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS
			);

		EXPECT_TRUE(
			std::isnan(
				result
			)
		);
	}

	TEST_F(
		TemperatureManagerTest,
		Should_HandleInfinityValues_When_InfiniteProvided
	)
	{
		double
			positive_infinity =
			std::numeric_limits<double>
			::infinity();

		double
			negative_infinity =
			-std::numeric_limits<double>
			::infinity();

		double
			positive_result =
			temperature_manager
			.convert_unit(
				positive_infinity,
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS,
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS
			);

		double
			negative_result =
			temperature_manager
			.convert_unit(
				negative_infinity,
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS,
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS
			);

		EXPECT_TRUE(
			std::isinf(
				positive_result
			)
		);

		EXPECT_TRUE(
			std::isinf(
				negative_result
			)
		);
	}

	TEST_F(
		TemperatureManagerTest,
		Should_NotDeadlock_When_MultipleThreadsConvertSimultaneously
	)
	{
		std::atomic<std::size_t>
			completed_threads =
			0;

		std::vector<std::thread>
			worker_threads;

		for
			(
				std::size_t
				thread_index = 0;
				thread_index < 8;
				++thread_index
				)
		{
			worker_threads
				.emplace_back(
					[&]()
					{
						for
							(
								std::size_t
								iteration = 0;
								iteration < 5000;
								++iteration
								)
						{
							temperature_manager
								.convert_unit(
									10.0,
									QLogicaeCppCore
									::TemperatureUnit
									::FAHRENHEIT,
									QLogicaeCppCore
									::TemperatureUnit
									::CELSIUS
								);
						}

						++completed_threads;
					}
				);
		}

		for
			(
				std::thread&
				worker_thread :
				worker_threads
				)
		{
			worker_thread
				.join();
		}

		EXPECT_EQ(
			completed_threads.load(),
			static_cast<std::size_t>(
				8
				)
		);
	}

	TEST_F(
		TemperatureManagerTest,
		Should_HandleConcurrentConfigurationChanges_When_MultiThreaded
	)
	{
		std::atomic<bool>
			completed =
			false;

		std::thread
			writer_thread =
			std::thread(
				[&]()
				{
					QLogicaeCppCore
						::TemperatureManagerConfigurations
						configurations;

					for
						(
							std::size_t
							iteration = 0;
							iteration < 1000;
							++iteration
							)
					{
						configurations
							.original_unit =
							QLogicaeCppCore
							::TemperatureUnit
							::CELSIUS;

						configurations
							.target_unit =
							QLogicaeCppCore
							::TemperatureUnit
							::FAHRENHEIT;

						temperature_manager
							.setup(
								configurations
							);
					}

					completed =
						true;
				}
			);

		for
			(
				std::size_t
				iteration = 0;
				iteration < 1000;
				++iteration
				)
		{
			temperature_manager
				.convert_unit(
					20.0
				);
		}

		writer_thread
			.join();

		EXPECT_TRUE(
			completed
		);
	}

	TEST_F(
		TemperatureManagerTest,
		Should_ExecuteMultipleAsyncTasks_When_UsingFutures
	)
	{
		std::vector<
			std::future<double>
		>
			futures;

		for
			(
				std::size_t
				iteration = 0;
				iteration < 16;
				++iteration
				)
		{
			futures
				.emplace_back(
					std::async(
						std::launch::async,
						[&]()
						{
							return
								temperature_manager
								.convert_unit(
									100.0,
									QLogicaeCppCore
									::TemperatureUnit
									::CELSIUS,
									QLogicaeCppCore
									::TemperatureUnit
									::KELVIN
								);
						}
					)
				);
		}

		for
			(
				std::future<double>&
				result_future :
				futures
				)
		{
			EXPECT_DOUBLE_EQ(
				result_future.get(),
				373.15
			);
		}
	}

	TEST_F(
		TemperatureManagerTest,
		Should_RespectFeatureThreadSafetyDisabled_When_FeatureLockDisabled
	)
	{
		QLogicaeCppCore
			::TemperatureManagerConfigurations
			configurations;

		configurations
			.is_feature_thread_safety_handling_enabled =
			false;

		temperature_manager
			.setup(
				configurations
			);

		double
			result =
			temperature_manager
			.convert_unit(
				0.0,
				QLogicaeCppCore
				::TemperatureUnit
				::CELSIUS,
				QLogicaeCppCore
				::TemperatureUnit
				::FAHRENHEIT
			);

		EXPECT_DOUBLE_EQ(
			result,
			32.0
		);
	}
}
