#pragma once

#include "qlogicae_cpp_core_benchmark/includes/application.hpp"

#include "qlogicae_cpp_core/includes/runtime_benchmarker.hpp"

namespace Experiment10 // pure
{
    std::string extern_static_string_input_value = "0";

    std::string extern_static_string_output_value = "";
}

int main(int, char**);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE,
    LPSTR,
    int
)
{
    return main(__argc, __argv);
}

namespace QLogicaeCppCoreBenchmark
{

}


struct NanobenchBenchmarkEpochIterationPair
{
    std::size_t epochs = 1;

    std::size_t iterations = 1;
};

struct NanobenchBenchmarkingTestCase
{
    std::string name = "";

    std::function<void()> callback = []() {};

    std::function<void()> before_test_callback = []() {};

    std::function<void()> after_test_callback = []() {};
};

struct NanobenchBenchmarkingTestSuite
{
    std::string name = "";

    size_t warmup_count = 1;

    bool is_relative = true;

    std::vector<NanobenchBenchmarkEpochIterationPair> epoch_iteration_pairs = {};

    std::vector<NanobenchBenchmarkingTestCase> test_cases = {};

    std::function<void()> before_test_suite_callback = []() {};

    std::function<void()> before_test_case_callback = []() {};

    std::function<void()> before_test_case_iteration_callback = []() {};

    std::function<void()> after_test_suite_callback = []() {};

    std::function<void()> after_test_case_callback = []() {};

    std::function<void()> after_test_case_iteration_callback = []() {};
};

void execute_nanobenchmark(
    const NanobenchBenchmarkingTestSuite& test_suite
)
{
    const std::string test_suite_name =
        test_suite.name;

    const std::size_t test_suite_epoch_pair_count =
        test_suite.epoch_iteration_pairs.size();

    const std::size_t test_suite_case_count =
        test_suite.test_cases.size();

    const std::size_t test_suite_warmup_count =
        test_suite.warmup_count;

    const bool test_suite_is_relative =
        test_suite.is_relative;

    const std::function<void()>& before_test_suite_callback =
        test_suite.before_test_suite_callback;

    const std::function<void()>& after_test_suite_callback =
        test_suite.after_test_suite_callback;

    const std::function<void()>& before_test_case_callback =
        test_suite.before_test_case_callback;

    const std::function<void()>& after_test_case_callback =
        test_suite.after_test_case_callback;

    const std::function<void()>& before_test_case_iteration_callback =
        test_suite.before_test_case_iteration_callback;

    const std::function<void()>& after_test_case_iteration_callback =
        test_suite.after_test_case_iteration_callback;

    before_test_suite_callback();

    for (std::size_t epoch_index = 0;
        epoch_index < test_suite_epoch_pair_count;
        ++epoch_index)
    {
        before_test_case_callback();

        const auto& epoch_iteration_pair =
            test_suite.epoch_iteration_pairs[epoch_index];

        const std::size_t epochs =
            epoch_iteration_pair.epochs;

        const std::size_t iterations =
            epoch_iteration_pair.iterations;

        ankerl::nanobench::Bench benchmarker;
        benchmarker.minEpochIterations(epochs);
        benchmarker.warmup(test_suite_warmup_count);
        benchmarker.relative(test_suite_is_relative);

        for (std::size_t test_index = 0;
            test_index < test_suite_case_count;
            ++test_index)
        {
            const auto& test_case =
                test_suite.test_cases[test_index];

            const std::string test_case_name =
                test_case.name;

            const std::string benchmark_name =
                test_suite_name + " | " + test_case_name + " | " + std::to_string(iterations);

            const std::function<void()>& callback =
                test_case.callback;

            const std::function<void()>& before_test_callback =
                test_case.before_test_callback;

            const std::function<void()>& after_test_callback =
                test_case.after_test_callback;

            before_test_case_iteration_callback();

            before_test_callback();

            benchmarker.run(
                benchmark_name,
                [callback, iterations]()
                {
                    for (std::size_t index_3 = 0;
                        index_3 < iterations;
                        ++index_3
                        )
                    {
                        callback();
                    }
                }
            );

            after_test_callback();

            after_test_case_iteration_callback();
        }

        std::cout << "\n";

        after_test_case_callback();
    }

    after_test_suite_callback();
}

/*

,
				{
					.name = "assign__string_parameter_type__const_arguments__concatenate_string",
					.callback = []()
					{
						Samples::instance
							.assign__string_parameter_type__const_arguments__concatenate_string("a", "a");
					}
				},
				{
					.name = "assign__const_string_parameter_type__const_arguments__concatenate_string",
					.callback = []()
					{
						Samples::instance
							.assign__const_string_parameter_type__const_arguments__concatenate_string("a", "a");
					}
				},
				{
					.name = "assign__reference_string_parameter_type__instance_arguments__concatenate_string",
					.callback = []()
					{
						Samples::instance
							.assign__reference_string_parameter_type__instance_arguments__concatenate_string(Samples::instance.instance_string_output_2, Samples::instance.instance_string_output_2);
					}
				},
				{
					.name = "assign__const_reference_string_parameter_type__const_arguments__concatenate_string",
					.callback = []()
					{
						Samples::instance
							.assign__const_reference_string_parameter_type__const_arguments__concatenate_string("a", "a");
					}
				},

				{
					.name = "return_and_assign__string_parameter_type__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string v = Samples::instance
							.return_and_assign__string_parameter_type__const_arguments__concatenate_string("a", "a");
					}
				},
				{
					.name = "return_and_assign__const_string_parameter_type__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string v = Samples::instance
							.return_and_assign__const_string_parameter_type__const_arguments__concatenate_string("a", "a");
					}
				},
				{
					.name = "return_and_assign__reference_string_parameter_type__instance_arguments__concatenate_string",
					.callback = []()
					{
						std::string v = Samples::instance
							.return_and_assign__reference_string_parameter_type__instance_arguments__concatenate_string(Samples::instance.instance_string_output_2, Samples::instance.instance_string_output_2);
					}
				},
				{
					.name = "return_and_assign__const_reference_string_parameter_type__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string v = Samples::instance
							.return_and_assign__const_reference_string_parameter_type__const_arguments__concatenate_string("a", "a");
					}
				},
				{
					.name = "recursive__pass_and_return__const_reference_string_parameter_type__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string v = Samples::instance
							.recursive__pass_and_return__const_reference_string_parameter_type__const_arguments__concatenate_string("a", "a", 100);
					}
				},
				{
					.name = "recursive__pass_and_return__const_reference_string_view_parameter_type__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string v = Samples::instance
							.recursive__pass_and_return__const_reference_string_view_parameter_type__const_arguments__concatenate_string("a", "a", 100);
					}
				},
				{
					.name = "recursive__pass__const_reference_string_parameter_type__const_arguments__concatenate_string",
					.callback = []()
					{
						Samples::instance
							.recursive__pass__const_reference_string_parameter_type__const_arguments__concatenate_string(Samples::instance.instance_string_output_2, "a", "a", 100);
					}
				},
				{
					.name = "recursive__pass__const_reference_string_view_parameter_type__const_arguments__concatenate_string",
					.callback = []()
					{
						Samples::instance
							.recursive__pass__const_reference_string_view_parameter_type__const_arguments__concatenate_string(Samples::instance.instance_string_output_2, "a", "a", 100);
					}
				}


*/

namespace AsynchronousBenchmarks
{
	/*

	Results:

	- Use:
		- boost_asio_co_spawn_strand__detached__constant_lambda()
			- multi-threading (general usage)

		- boost_asio_co_spawn_strand__use_future__constant_lambda()
			- multi-threading (general usage)

		- boost_asio_co_spawn_io__detached__constant_lambda()
			- fire-and-forget

		- boost_asio_co_spawn_io__use_future__constant_lambda()
			- fire-and-forget

	- Results:
	| relative |               ns/op |                op/s |    err% |     total | benchmark
	|---------:|--------------------:|--------------------:|--------:|----------:|:----------
	|   100.0% |              465.05 |        2,150,298.05 |    2.3% |      0.52 | `thread_creation | boost_asio_co_spawn_strand__detached__constant_lambda | 1`
	|    26.4% |            1,762.47 |          567,385.27 |    0.5% |      2.14 | `thread_creation | boost_asio_co_spawn_io__detached__constant_lambda | 1`
	|    69.1% |              673.04 |        1,485,798.31 |    1.7% |      0.83 | `thread_creation | boost_asio_co_spawn_strand__use_future__constant_lambda | 1`
	|    22.9% |            2,031.28 |          492,299.86 |    0.3% |      2.46 | `thread_creation | boost_asio_co_spawn_io__use_future__constant_lambda | 1`
	|    27.7% |            1,677.93 |          595,972.57 |    0.3% |      2.03 | `thread_creation | boost_asio_post_thread__thread_pool_instance__constant_lambda | 1`
	|    27.5% |            1,693.60 |          590,459.93 |    0.3% |      2.04 | `thread_creation | boost_asio_post_thread__thread_pool_heap__constant_lambda | 1`
	|    22.5% |            2,070.83 |          482,897.90 |    0.4% |      2.51 | `thread_creation | boost_asio_co_spawn_thread__detached__constant_lambda | 1`
	|    24.3% |            1,914.20 |          522,411.17 |    1.9% |      2.30 | `thread_creation | boost_asio_post_thread__system_executor__constant_lambda | 1`
	|    26.9% |            1,725.65 |          579,490.37 |    1.0% |      2.09 | `thread_creation | boost_asio_dispatch_thread__thread_pool_instance__constant_lambda | 1`
	|    26.1% |            1,785.19 |          560,165.56 |    0.6% |      2.20 | `thread_creation | boost_asio_dispatch_thread__thread_pool_heap__constant_lambda | 1`
	|     9.4% |            4,943.96 |          202,267.21 |    1.5% |      6.18 | `thread_creation | std_async_thread__constant_lambda | 1`

	|   100.0% |            4,478.64 |          223,281.91 |    1.8% |      0.50 | `thread_creation | boost_asio_co_spawn_strand__detached__constant_lambda | 10`
	|    25.5% |           17,570.24 |           56,914.41 |    0.8% |      2.12 | `thread_creation | boost_asio_co_spawn_io__detached__constant_lambda | 10`
	|    61.3% |            7,311.49 |          136,771.08 |    5.0% |      0.97 | `thread_creation | boost_asio_co_spawn_strand__use_future__constant_lambda | 10`
	|    16.2% |           27,694.07 |           36,108.82 |    1.5% |      3.33 | `thread_creation | boost_asio_co_spawn_io__use_future__constant_lambda | 10`
	|    19.0% |           23,587.24 |           42,395.80 |    0.7% |      2.86 | `thread_creation | boost_asio_post_thread__thread_pool_instance__constant_lambda | 10`
	|    19.0% |           23,606.80 |           42,360.67 |    0.5% |      2.86 | `thread_creation | boost_asio_post_thread__thread_pool_heap__constant_lambda | 10`
	|    15.5% |           28,968.51 |           34,520.24 |    0.6% |      3.52 | `thread_creation | boost_asio_co_spawn_thread__detached__constant_lambda | 10`
	|    16.7% |           26,823.11 |           37,281.28 |    0.2% |      3.23 | `thread_creation | boost_asio_post_thread__system_executor__constant_lambda | 10`
	|    18.9% |           23,643.36 |           42,295.18 |    0.6% |      2.96 | `thread_creation | boost_asio_dispatch_thread__thread_pool_instance__constant_lambda | 10`
	|    18.7% |           24,007.64 |           41,653.41 |    0.5% |      2.93 | `thread_creation | boost_asio_dispatch_thread__thread_pool_heap__constant_lambda | 10`
	|     8.8% |           50,691.71 |           19,727.09 |    4.8% |      6.23 | `thread_creation | std_async_thread__constant_lambda | 10`

	|   100.0% |           47,171.53 |           21,199.23 |    1.3% |      0.51 | `thread_creation | boost_asio_co_spawn_strand__detached__constant_lambda | 100`
	|    20.5% |          229,674.59 |            4,353.99 |    1.1% |      2.75 | `thread_creation | boost_asio_co_spawn_io__detached__constant_lambda | 100`
	|    64.6% |           73,010.37 |           13,696.69 |    1.3% |      0.97 | `thread_creation | boost_asio_co_spawn_strand__use_future__constant_lambda | 100`
	|    17.3% |          272,201.17 |            3,673.75 |    2.0% |      3.27 | `thread_creation | boost_asio_co_spawn_io__use_future__constant_lambda | 100`
	|    20.1% |          235,073.93 |            4,253.98 |    0.4% |      2.83 | `thread_creation | boost_asio_post_thread__thread_pool_instance__constant_lambda | 100`
	|    20.0% |          236,368.07 |            4,230.69 |    0.6% |      2.88 | `thread_creation | boost_asio_post_thread__thread_pool_heap__constant_lambda | 100`
	|    16.5% |          285,316.09 |            3,504.88 |    0.3% |      3.46 | `thread_creation | boost_asio_co_spawn_thread__detached__constant_lambda | 100`
	|    17.8% |          265,601.21 |            3,765.04 |    0.8% |      3.23 | `thread_creation | boost_asio_post_thread__system_executor__constant_lambda | 100`
	|    19.8% |          238,357.06 |            4,195.39 |    0.9% |      2.91 | `thread_creation | boost_asio_dispatch_thread__thread_pool_instance__constant_lambda | 100`
	|    18.7% |          252,047.88 |            3,967.50 |    3.4% |      3.09 | `thread_creation | boost_asio_dispatch_thread__thread_pool_heap__constant_lambda | 100`
	|     8.9% |          528,372.05 |            1,892.61 |    3.3% |      6.41 | `thread_creation | std_async_thread__constant_lambda | 100`

	|   100.0% |          522,610.78 |            1,913.47 |    1.2% |      0.63 | `thread_creation | boost_asio_co_spawn_strand__detached__constant_lambda | 1000`
	|    21.1% |        2,482,494.74 |              402.82 |    1.0% |      2.97 | `thread_creation | boost_asio_co_spawn_io__detached__constant_lambda | 1000`
	|    69.1% |          756,775.23 |            1,321.40 |    2.5% |      1.01 | `thread_creation | boost_asio_co_spawn_strand__use_future__constant_lambda | 1000`
	|    18.1% |        2,886,800.95 |              346.40 |    0.9% |      3.46 | `thread_creation | boost_asio_co_spawn_io__use_future__constant_lambda | 1000`
	|    21.3% |        2,452,335.65 |              407.77 |    0.5% |      2.97 | `thread_creation | boost_asio_post_thread__thread_pool_instance__constant_lambda | 1000`
	|    21.1% |        2,477,329.91 |              403.66 |    1.0% |      2.99 | `thread_creation | boost_asio_post_thread__thread_pool_heap__constant_lambda | 1000`
	|    17.4% |        3,002,938.32 |              333.01 |    0.4% |      3.64 | `thread_creation | boost_asio_co_spawn_thread__detached__constant_lambda | 1000`
	|    18.8% |        2,781,906.96 |              359.47 |    0.5% |      3.36 | `thread_creation | boost_asio_post_thread__system_executor__constant_lambda | 1000`
	|    20.9% |        2,504,734.29 |              399.24 |    0.8% |      3.03 | `thread_creation | boost_asio_dispatch_thread__thread_pool_instance__constant_lambda | 1000`
	|    20.9% |        2,500,058.88 |              399.99 |    0.5% |      3.03 | `thread_creation | boost_asio_dispatch_thread__thread_pool_heap__constant_lambda | 1000`
	|     9.9% |        5,294,259.13 |              188.88 |    4.1% |      6.48 | `thread_creation | std_async_thread__constant_lambda | 1000`

	|   100.0% |      510,373,700.00 |                1.96 |    1.1% |      5.62 | `thread_creation | boost_asio_co_spawn_strand__detached__constant_lambda | 1000000`
	|    20.2% |    2,524,726,900.00 |                0.40 |    0.6% |     29.48 | `thread_creation | boost_asio_co_spawn_io__detached__constant_lambda | 1000000`
	|    64.4% |      792,991,200.00 |                1.26 |    1.6% |      8.72 | `thread_creation | boost_asio_co_spawn_strand__use_future__constant_lambda | 1000000`
	|    17.4% |    2,937,717,500.00 |                0.34 |    0.6% |     32.36 | `thread_creation | boost_asio_co_spawn_io__use_future__constant_lambda | 1000000`
	|    19.9% |    2,565,697,600.00 |                0.39 |    1.0% |     28.21 | `thread_creation | boost_asio_post_thread__thread_pool_instance__constant_lambda | 1000000`
	|    19.8% |    2,574,147,900.00 |                0.39 |    0.6% |     28.37 | `thread_creation | boost_asio_post_thread__thread_pool_heap__constant_lambda | 1000000`
	|    16.7% |    3,050,680,500.00 |                0.33 |    0.6% |     33.70 | `thread_creation | boost_asio_co_spawn_thread__detached__constant_lambda | 1000000`
	|    18.0% |    2,840,849,400.00 |                0.35 |    0.7% |     31.59 | `thread_creation | boost_asio_post_thread__system_executor__constant_lambda | 1000000`
	|    19.7% |    2,594,505,200.00 |                0.39 |    0.7% |     28.90 | `thread_creation | boost_asio_dispatch_thread__thread_pool_instance__constant_lambda | 1000000`
	|    19.7% |    2,587,159,400.00 |                0.39 |    0.3% |     28.52 | `thread_creation | boost_asio_dispatch_thread__thread_pool_heap__constant_lambda | 1000000`
	|     9.4% |    5,422,414,400.00 |                0.18 |    0.9% |     59.39 | `thread_creation | std_async_thread__constant_lambda | 1000000`

	*/

	inline static std::function<void()> instance_lambda = []() {};

	inline static boost::asio::thread_pool THREAD_POOL_INSTANCE{ std::thread::hardware_concurrency() };

	inline static std::shared_ptr<boost::asio::thread_pool> THREAD_POOL_HEAP;

	inline static boost::asio::io_context IO;

	inline static boost::asio::strand<decltype(IO.get_executor())> STRAND(IO.get_executor());

	inline static auto WORK = boost::asio::make_work_guard(IO);

	inline static std::vector<std::thread> WORKERS;

	inline static boost::asio::inline_executor exec;

	void start_io_workers()
	{
		for (size_t i = 0; i < std::thread::hardware_concurrency(); ++i)
			WORKERS.emplace_back([] { IO.run(); });
	}

	void stop_io_workers()
	{
		WORK.reset();
		IO.stop();
		for (auto& t : WORKERS)
			if (t.joinable())
				t.join();
		WORKERS.clear();
	}

	void boost_asio_co_spawn_io__detached__constant_lambda()
	{
		// auto start = std::chrono::high_resolution_clock::now();
		boost::asio::co_spawn(
			IO,
			[]() -> boost::asio::awaitable<void>
			{
				co_return;
			},
			boost::asio::detached
		);
		// auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start)
		//	.count();
		// std::cout << "Nanoseconds " << ": " << ns << " ns\n";
	}

	void boost_asio_post_thread__thread_pool_instance__constant_lambda()
	{
		// auto start = std::chrono::high_resolution_clock::now();
		boost::asio::post(
			THREAD_POOL_INSTANCE,
			[]() {}
		);
		// auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start)
		//	.count();
		// std::cout << "Nanoseconds " << ": " << ns << " ns\n";
	}

	void boost_asio_co_spawn_strand__detached__constant_lambda()
	{
		// auto start = std::chrono::high_resolution_clock::now();
		boost::asio::co_spawn(
			STRAND,
			[]() -> boost::asio::awaitable<void>
			{
				co_return;
			},
			boost::asio::detached
		);
		// auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start)
		//	.count();
		// std::cout << "Nanoseconds " << ": " << ns << " ns\n";
	}

	std::future<void>
		boost_asio_co_spawn_io__use_future__constant_lambda()
	{
		// auto start = std::chrono::high_resolution_clock::now();
		std::function<void()> callback = []() {};

		auto future = boost::asio::co_spawn(
			IO,
			[callback]() -> boost::asio::awaitable<void>
			{
				callback();

				co_return;
			},
			boost::asio::use_future
		);
		// auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start)
		//	.count();
		// std::cout << "Nanoseconds " << ": " << ns << " ns\n";

		return future;
	}

	std::future<void>
		boost_asio_co_spawn_strand__use_future__constant_lambda()
	{
		// auto start = std::chrono::high_resolution_clock::now();
		std::function<void()> callback = []() {};

		auto future = boost::asio::co_spawn(
			STRAND,
			[callback]() -> boost::asio::awaitable<void>
			{
				callback();

				co_return;
			},
			boost::asio::use_future
		);
		// auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start)
		//	.count();
		// std::cout << "Nanoseconds " << ": " << ns << " ns\n";

		return future;
	}

	void boost_asio_post_thread__system_executor__constant_lambda()
	{
		boost::asio::post(boost::asio::system_executor(), []() {});
	}

	void boost_asio_dispatch_thread__inline_executor__constant_lambda()
	{
		boost::asio::dispatch(exec, []() {});
	}

	void boost_asio_co_spawn_thread__detached__constant_lambda()
	{
		boost::asio::co_spawn(
			THREAD_POOL_INSTANCE.get_executor(),
			[]() -> boost::asio::awaitable<void>
			{
				co_return;
			},
			boost::asio::detached
		);
	}

	void boost_asio_dispatch_thread__thread_pool_instance__constant_lambda()
	{
		boost::asio::dispatch(
			THREAD_POOL_INSTANCE,
			[]() {}
		);
	}

	void boost_asio_post_thread__thread_pool_heap__constant_lambda()
	{
		boost::asio::post(
			*THREAD_POOL_HEAP,
			[]() {}
		);
	}

	void boost_asio_dispatch_thread__thread_pool_heap__constant_lambda()
	{
		boost::asio::dispatch(
			*THREAD_POOL_HEAP,
			[]() {}
		);
	}

	void std_async_thread__constant_lambda()
	{
		std::async(
			std::launch::async,
			[]() {}
		);
	}

	void execute()
	{
		THREAD_POOL_HEAP =
			std::make_shared<boost::asio::thread_pool>(
				std::thread::hardware_concurrency()
			);

		NanobenchBenchmarkingTestSuite test_suite
		{
			.name = "thread_creation",
			.epoch_iteration_pairs =
			{
				{
					.epochs = 100000,
					.iterations = 1
				},
				{
					.epochs = 10000,
					.iterations = 10
				},
				{
					.epochs = 1000,
					.iterations = 100
				},
				{
					.epochs = 100,
					.iterations = 1000
				},
				{
					.epochs = 1,
					.iterations = 1000000
				}
			},
			.test_cases =
			{
				{
					.name = "boost_asio_co_spawn_strand__detached__constant_lambda",
					.callback = boost_asio_co_spawn_strand__detached__constant_lambda
				},
				{
					.name = "boost_asio_co_spawn_io__detached__constant_lambda",
					.callback = boost_asio_co_spawn_io__detached__constant_lambda
				},
				{
					.name = "boost_asio_co_spawn_strand__use_future__constant_lambda",
					.callback = boost_asio_co_spawn_strand__use_future__constant_lambda
				},
				{
					.name = "boost_asio_co_spawn_io__use_future__constant_lambda",
					.callback = boost_asio_co_spawn_io__use_future__constant_lambda
				},
				{
					.name = "boost_asio_post_thread__thread_pool_instance__constant_lambda",
					.callback = boost_asio_post_thread__thread_pool_instance__constant_lambda
				},
				{
					.name = "boost_asio_post_thread__thread_pool_heap__constant_lambda",
					.callback = boost_asio_post_thread__thread_pool_heap__constant_lambda
				},
				{
					.name = "boost_asio_co_spawn_thread__detached__constant_lambda",
					.callback = boost_asio_co_spawn_thread__detached__constant_lambda
				},
				{
					.name = "boost_asio_post_thread__system_executor__constant_lambda",
					.callback = boost_asio_post_thread__system_executor__constant_lambda
				},
				{
					.name = "boost_asio_dispatch_thread__thread_pool_instance__constant_lambda",
					.callback = boost_asio_dispatch_thread__thread_pool_instance__constant_lambda
				},
				{
					.name = "boost_asio_dispatch_thread__thread_pool_heap__constant_lambda",
					.callback = boost_asio_dispatch_thread__thread_pool_heap__constant_lambda
				},
				{
					.name = "std_async_thread__constant_lambda",
					.callback = std_async_thread__constant_lambda
				}
			}
		};

		start_io_workers();

		execute_nanobenchmark(
			test_suite
		);

		stop_io_workers();

		/*
		boost_asio_post_thread__thread_pool_instance__constant_lambda();
		boost_asio_co_spawn_io__detached__constant_lambda();
		boost_asio_co_spawn_strand__detached__constant_lambda();
		*/

		bool exit_code;
		std::cin >> exit_code;
	}
}



namespace ArithmeticOperationsPerTypes
{
	/*

	Conclusion:
		- size_t
		- long double
		- long long int

	Results:

	| relative |               ns/op |                op/s |    err% |     total | benchmark
	|---------:|--------------------:|--------------------:|--------:|----------:|:----------
	|   100.0% |                1.91 |      522,535,815.02 |    1.2% |      0.47 | `Arithmetic Operations Per Type | add__instance__char | 1`
	|   101.3% |                1.89 |      529,530,385.14 |    0.8% |      0.46 | `Arithmetic Operations Per Type | add__instance__short_int | 1`
	|   130.2% |                1.47 |      680,262,808.03 |    1.7% |      0.36 | `Arithmetic Operations Per Type | add__instance__int | 1`
	|   135.7% |                1.41 |      708,858,861.97 |    1.1% |      0.34 | `Arithmetic Operations Per Type | add__instance__long_int | 1`
	|   133.3% |                1.44 |      696,436,513.98 |    0.4% |      0.35 | `Arithmetic Operations Per Type | add__instance__long_long_int | 1`
	|   101.2% |                1.89 |      528,822,927.05 |    1.3% |      0.46 | `Arithmetic Operations Per Type | add__instance__int8_t | 1`
	|    99.9% |                1.92 |      521,774,024.71 |    0.6% |      0.47 | `Arithmetic Operations Per Type | add__instance__int16_t | 1`
	|   134.3% |                1.43 |      701,706,556.83 |    1.4% |      0.35 | `Arithmetic Operations Per Type | add__instance__int32_t | 1`
	|   134.4% |                1.42 |      702,350,831.12 |    3.2% |      0.34 | `Arithmetic Operations Per Type | add__instance__int64_t | 1`
	|   132.5% |                1.44 |      692,347,740.88 |    0.6% |      0.35 | `Arithmetic Operations Per Type | add__instance__size_t | 1`
	|    61.6% |                3.11 |      321,681,290.51 |    0.0% |      0.75 | `Arithmetic Operations Per Type | add__instance__float | 1`
	|    61.6% |                3.11 |      321,640,703.56 |    0.1% |      0.75 | `Arithmetic Operations Per Type | add__instance__double | 1`
	|    61.6% |                3.11 |      321,806,391.06 |    0.1% |      0.75 | `Arithmetic Operations Per Type | add__instance__long_double | 1`
	|   160.1% |                1.20 |      836,323,272.53 |    0.1% |      0.29 | `Arithmetic Operations Per Type | subtract__instance__char | 1`
	|   160.2% |                1.19 |      837,113,241.52 |    0.0% |      0.29 | `Arithmetic Operations Per Type | subtract__instance__short_int | 1`
	|   159.6% |                1.20 |      834,181,006.16 |    0.3% |      0.29 | `Arithmetic Operations Per Type | subtract__instance__int | 1`
	|   160.1% |                1.20 |      836,657,499.21 |    0.1% |      0.29 | `Arithmetic Operations Per Type | subtract__instance__long_int | 1`
	|   160.0% |                1.20 |      836,171,439.57 |    0.1% |      0.29 | `Arithmetic Operations Per Type | subtract__instance__long_long_int | 1`
	|   159.9% |                1.20 |      835,435,075.06 |    0.2% |      0.29 | `Arithmetic Operations Per Type | subtract__instance__int8_t | 1`
	|   160.1% |                1.20 |      836,325,924.08 |    0.1% |      0.29 | `Arithmetic Operations Per Type | subtract__instance__int16_t | 1`
	|   160.0% |                1.20 |      835,849,081.01 |    0.1% |      0.29 | `Arithmetic Operations Per Type | subtract__instance__int32_t | 1`
	|   159.8% |                1.20 |      834,846,432.32 |    0.2% |      0.29 | `Arithmetic Operations Per Type | subtract__instance__int64_t | 1`
	|   156.8% |                1.22 |      819,401,890.21 |    1.6% |      0.30 | `Arithmetic Operations Per Type | subtract__instance__size_t | 1`
	|    60.9% |                3.14 |      318,194,415.22 |    0.9% |      0.76 | `Arithmetic Operations Per Type | subtract__instance__float | 1`
	|    61.2% |                3.12 |      320,044,295.42 |    0.4% |      0.76 | `Arithmetic Operations Per Type | subtract__instance__double | 1`
	|    61.3% |                3.12 |      320,092,091.80 |    0.2% |      0.76 | `Arithmetic Operations Per Type | subtract__instance__long_double | 1`
	|    88.8% |                2.15 |      464,157,092.86 |    0.2% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__char | 1`
	|    88.8% |                2.16 |      463,874,572.71 |    0.2% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__short_int | 1`
	|   100.0% |                1.91 |      522,582,492.51 |    0.1% |      0.46 | `Arithmetic Operations Per Type | multiply__instance__int | 1`
	|   100.0% |                1.91 |      522,729,883.17 |    0.1% |      0.46 | `Arithmetic Operations Per Type | multiply__instance__long_int | 1`
	|   100.1% |                1.91 |      522,942,422.52 |    0.1% |      0.46 | `Arithmetic Operations Per Type | multiply__instance__long_long_int | 1`
	|    88.9% |                2.15 |      464,718,691.00 |    0.1% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__int8_t | 1`
	|    88.9% |                2.15 |      464,666,384.19 |    0.1% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__int16_t | 1`
	|   100.0% |                1.91 |      522,788,354.22 |    0.1% |      0.46 | `Arithmetic Operations Per Type | multiply__instance__int32_t | 1`
	|   100.1% |                1.91 |      523,040,666.96 |    0.1% |      0.46 | `Arithmetic Operations Per Type | multiply__instance__int64_t | 1`
	|   100.1% |                1.91 |      523,018,023.64 |    0.1% |      0.46 | `Arithmetic Operations Per Type | multiply__instance__size_t | 1`
	|    89.0% |                2.15 |      465,034,802.31 |    0.0% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__float | 1`
	|    88.9% |                2.15 |      464,770,955.57 |    0.1% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__double | 1`
	|    88.9% |                2.15 |      464,709,785.40 |    0.1% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__long_double | 1`
	|   160.0% |                1.20 |      836,034,592.36 |    0.1% |      0.29 | `Arithmetic Operations Per Type | divide__instance__char | 1`
	|   160.0% |                1.20 |      836,316,558.85 |    0.1% |      0.29 | `Arithmetic Operations Per Type | divide__instance__short_int | 1`
	|   160.0% |                1.20 |      836,029,516.48 |    0.1% |      0.29 | `Arithmetic Operations Per Type | divide__instance__int | 1`
	|   160.1% |                1.20 |      836,517,699.20 |    0.1% |      0.29 | `Arithmetic Operations Per Type | divide__instance__long_int | 1`
	|   159.8% |                1.20 |      835,162,844.18 |    0.2% |      0.29 | `Arithmetic Operations Per Type | divide__instance__long_long_int | 1`
	|   160.1% |                1.19 |      836,823,983.22 |    0.1% |      0.29 | `Arithmetic Operations Per Type | divide__instance__int8_t | 1`
	|   160.0% |                1.20 |      835,932,453.82 |    0.1% |      0.29 | `Arithmetic Operations Per Type | divide__instance__int16_t | 1`
	|   160.2% |                1.19 |      836,859,194.13 |    0.1% |      0.29 | `Arithmetic Operations Per Type | divide__instance__int32_t | 1`
	|   159.9% |                1.20 |      835,525,248.35 |    0.2% |      0.29 | `Arithmetic Operations Per Type | divide__instance__int64_t | 1`
	|   160.0% |                1.20 |      836,277,126.66 |    0.2% |      0.29 | `Arithmetic Operations Per Type | divide__instance__size_t | 1`
	|   159.9% |                1.20 |      835,711,753.85 |    0.2% |      0.29 | `Arithmetic Operations Per Type | divide__instance__float | 1`
	|   160.1% |                1.20 |      836,639,469.16 |    0.1% |      0.29 | `Arithmetic Operations Per Type | divide__instance__double | 1`
	|   160.2% |                1.19 |      836,894,510.69 |    0.1% |      0.29 | `Arithmetic Operations Per Type | divide__instance__long_double | 1`

	|   100.0% |            1,909.79 |          523,618.07 |    0.1% |      0.46 | `Arithmetic Operations Per Type | add__instance__char | 1000`
	|   100.1% |            1,908.47 |          523,980.61 |    0.1% |      0.46 | `Arithmetic Operations Per Type | add__instance__short_int | 1000`
	|   132.9% |            1,437.25 |          695,771.81 |    1.0% |      0.35 | `Arithmetic Operations Per Type | add__instance__int | 1000`
	|   133.0% |            1,435.76 |          696,497.59 |    0.5% |      0.35 | `Arithmetic Operations Per Type | add__instance__long_int | 1000`
	|   132.8% |            1,437.72 |          695,547.56 |    0.5% |      0.35 | `Arithmetic Operations Per Type | add__instance__long_long_int | 1000`
	|   100.2% |            1,906.84 |          524,428.12 |    0.0% |      0.46 | `Arithmetic Operations Per Type | add__instance__int8_t | 1000`
	|   100.1% |            1,906.94 |          524,401.01 |    0.1% |      0.46 | `Arithmetic Operations Per Type | add__instance__int16_t | 1000`
	|   131.6% |            1,451.08 |          689,142.36 |    0.7% |      0.35 | `Arithmetic Operations Per Type | add__instance__int32_t | 1000`
	|   131.3% |            1,454.24 |          687,646.73 |    0.7% |      0.35 | `Arithmetic Operations Per Type | add__instance__int64_t | 1000`
	|   133.0% |            1,436.32 |          696,223.73 |    0.1% |      0.35 | `Arithmetic Operations Per Type | add__instance__size_t | 1000`
	|    61.4% |            3,107.95 |          321,755.41 |    0.1% |      0.75 | `Arithmetic Operations Per Type | add__instance__float | 1000`
	|    61.4% |            3,110.17 |          321,525.60 |    0.1% |      0.76 | `Arithmetic Operations Per Type | add__instance__double | 1000`
	|    61.4% |            3,107.91 |          321,759.43 |    0.1% |      0.75 | `Arithmetic Operations Per Type | add__instance__long_double | 1000`
	|   197.8% |              965.53 |        1,035,703.42 |    0.1% |      0.21 | `Arithmetic Operations Per Type | subtract__instance__char | 1000`
	|   197.6% |              966.66 |        1,034,494.21 |    0.1% |      0.23 | `Arithmetic Operations Per Type | subtract__instance__short_int | 1000`
	|   197.0% |              969.23 |        1,031,751.66 |    0.3% |      0.24 | `Arithmetic Operations Per Type | subtract__instance__int | 1000`
	|   196.4% |              972.45 |        1,028,328.26 |    0.7% |      0.21 | `Arithmetic Operations Per Type | subtract__instance__long_int | 1000`
	|   197.7% |              965.82 |        1,035,389.86 |    0.1% |      0.21 | `Arithmetic Operations Per Type | subtract__instance__long_long_int | 1000`
	|   197.4% |              967.41 |        1,033,686.59 |    0.2% |      0.21 | `Arithmetic Operations Per Type | subtract__instance__int8_t | 1000`
	|   197.3% |              967.82 |        1,033,251.64 |    0.2% |      0.23 | `Arithmetic Operations Per Type | subtract__instance__int16_t | 1000`
	|   197.5% |              966.84 |        1,034,301.81 |    0.2% |      0.21 | `Arithmetic Operations Per Type | subtract__instance__int32_t | 1000`
	|   197.6% |              966.29 |        1,034,882.00 |    0.2% |      0.21 | `Arithmetic Operations Per Type | subtract__instance__int64_t | 1000`
	|   197.1% |              969.00 |        1,031,987.17 |    0.1% |      0.21 | `Arithmetic Operations Per Type | subtract__instance__size_t | 1000`
	|    61.4% |            3,111.34 |          321,405.40 |    0.2% |      0.75 | `Arithmetic Operations Per Type | subtract__instance__float | 1000`
	|    61.4% |            3,112.36 |          321,299.30 |    0.2% |      0.76 | `Arithmetic Operations Per Type | subtract__instance__double | 1000`
	|    61.4% |            3,112.49 |          321,285.73 |    0.1% |      0.75 | `Arithmetic Operations Per Type | subtract__instance__long_double | 1000`
	|    88.7% |            2,152.61 |          464,553.34 |    0.1% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__char | 1000`
	|    88.7% |            2,152.76 |          464,520.06 |    0.1% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__short_int | 1000`
	|    99.7% |            1,915.50 |          522,057.57 |    0.2% |      0.46 | `Arithmetic Operations Per Type | multiply__instance__int | 1000`
	|    99.9% |            1,912.33 |          522,921.67 |    0.1% |      0.46 | `Arithmetic Operations Per Type | multiply__instance__long_int | 1000`
	|    99.8% |            1,912.76 |          522,805.96 |    0.1% |      0.46 | `Arithmetic Operations Per Type | multiply__instance__long_long_int | 1000`
	|    88.7% |            2,152.50 |          464,576.36 |    0.1% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__int8_t | 1000`
	|    88.7% |            2,151.99 |          464,685.36 |    0.1% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__int16_t | 1000`
	|    99.7% |            1,914.88 |          522,226.35 |    0.1% |      0.46 | `Arithmetic Operations Per Type | multiply__instance__int32_t | 1000`
	|    99.9% |            1,911.75 |          523,081.31 |    0.0% |      0.46 | `Arithmetic Operations Per Type | multiply__instance__int64_t | 1000`
	|    99.8% |            1,913.33 |          522,650.03 |    0.1% |      0.46 | `Arithmetic Operations Per Type | multiply__instance__size_t | 1000`
	|    88.8% |            2,151.43 |          464,807.20 |    0.1% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__float | 1000`
	|    88.7% |            2,152.15 |          464,652.36 |    0.1% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__double | 1000`
	|    88.8% |            2,151.59 |          464,773.63 |    0.1% |      0.52 | `Arithmetic Operations Per Type | multiply__instance__long_double | 1000`
	|   197.7% |              965.98 |        1,035,214.10 |    0.2% |      0.23 | `Arithmetic Operations Per Type | divide__instance__char | 1000`
	|   197.7% |              965.81 |        1,035,402.13 |    0.1% |      0.21 | `Arithmetic Operations Per Type | divide__instance__short_int | 1000`
	|   198.0% |              964.76 |        1,036,523.42 |    0.1% |      0.21 | `Arithmetic Operations Per Type | divide__instance__int | 1000`
	|   197.7% |              965.92 |        1,035,283.13 |    0.1% |      0.23 | `Arithmetic Operations Per Type | divide__instance__long_int | 1000`
	|   197.7% |              966.16 |        1,035,029.16 |    0.2% |      0.21 | `Arithmetic Operations Per Type | divide__instance__long_long_int | 1000`
	|   197.9% |              964.90 |        1,036,375.22 |    0.1% |      0.23 | `Arithmetic Operations Per Type | divide__instance__int8_t | 1000`
	|   197.9% |              965.19 |        1,036,066.82 |    0.1% |      0.21 | `Arithmetic Operations Per Type | divide__instance__int16_t | 1000`
	|   197.9% |              964.82 |        1,036,465.08 |    0.1% |      0.21 | `Arithmetic Operations Per Type | divide__instance__int32_t | 1000`
	|   197.6% |              966.70 |        1,034,442.25 |    0.2% |      0.23 | `Arithmetic Operations Per Type | divide__instance__int64_t | 1000`
	|   197.8% |              965.47 |        1,035,769.06 |    0.1% |      0.23 | `Arithmetic Operations Per Type | divide__instance__size_t | 1000`
	|   197.9% |              965.17 |        1,036,091.57 |    0.1% |      0.21 | `Arithmetic Operations Per Type | divide__instance__float | 1000`
	|   197.5% |              966.97 |        1,034,160.56 |    0.2% |      0.23 | `Arithmetic Operations Per Type | divide__instance__double | 1000`
	|   197.6% |              966.69 |        1,034,462.62 |    0.4% |      0.22 | `Arithmetic Operations Per Type | divide__instance__long_double | 1000`

	|   100.0% |        1,901,400.00 |              525.93 |    3.7% |      0.02 | `Arithmetic Operations Per Type | add__instance__char | 1000000`
	|    99.5% |        1,910,000.00 |              523.56 |    2.5% |      0.02 | `Arithmetic Operations Per Type | add__instance__short_int | 1000000`
	|   132.7% |        1,433,200.00 |              697.74 |    0.1% |      0.02 | `Arithmetic Operations Per Type | add__instance__int | 1000000`
	|   132.7% |        1,432,800.00 |              697.93 |    0.5% |      0.02 | `Arithmetic Operations Per Type | add__instance__long_int | 1000000`
	|   132.6% |        1,433,500.00 |              697.59 |    0.7% |      0.02 | `Arithmetic Operations Per Type | add__instance__long_long_int | 1000000`
	|    99.5% |        1,911,000.00 |              523.29 |    1.7% |      0.02 | `Arithmetic Operations Per Type | add__instance__int8_t | 1000000`
	|    99.2% |        1,917,500.00 |              521.51 |    2.9% |      0.02 | `Arithmetic Operations Per Type | add__instance__int16_t | 1000000`
	|   132.7% |        1,432,700.00 |              697.98 |    0.1% |      0.02 | `Arithmetic Operations Per Type | add__instance__int32_t | 1000000`
	|   132.1% |        1,439,000.00 |              694.93 |    0.5% |      0.02 | `Arithmetic Operations Per Type | add__instance__int64_t | 1000000`
	|   132.5% |        1,435,400.00 |              696.67 |    0.5% |      0.02 | `Arithmetic Operations Per Type | add__instance__size_t | 1000000`
	|    61.2% |        3,105,200.00 |              322.04 |    0.1% |      0.04 | `Arithmetic Operations Per Type | add__instance__float | 1000000`
	|    61.3% |        3,104,200.00 |              322.14 |    0.0% |      0.03 | `Arithmetic Operations Per Type | add__instance__double | 1000000`
	|    61.2% |        3,104,800.00 |              322.08 |    0.0% |      0.03 | `Arithmetic Operations Per Type | add__instance__long_double | 1000000`
	|   198.8% |          956,500.00 |            1,045.48 |    0.2% |      0.01 | `Arithmetic Operations Per Type | subtract__instance__char | 1000000`
	|   198.9% |          955,900.00 |            1,046.13 |    0.1% |      0.01 | `Arithmetic Operations Per Type | subtract__instance__short_int | 1000000`
	|   199.0% |          955,300.00 |            1,046.79 |    0.1% |      0.01 | `Arithmetic Operations Per Type | subtract__instance__int | 1000000`
	|   199.1% |          955,100.00 |            1,047.01 |    0.1% |      0.01 | `Arithmetic Operations Per Type | subtract__instance__long_int | 1000000`
	|   199.0% |          955,300.00 |            1,046.79 |    0.1% |      0.01 | `Arithmetic Operations Per Type | subtract__instance__long_long_int | 1000000`
	|   199.0% |          955,400.00 |            1,046.68 |    0.1% |      0.01 | `Arithmetic Operations Per Type | subtract__instance__int8_t | 1000000`
	|   198.3% |          959,000.00 |            1,042.75 |    0.5% |      0.01 | `Arithmetic Operations Per Type | subtract__instance__int16_t | 1000000`
	|   199.0% |          955,300.00 |            1,046.79 |    0.1% |      0.01 | `Arithmetic Operations Per Type | subtract__instance__int32_t | 1000000`
	|   199.0% |          955,300.00 |            1,046.79 |    0.1% |      0.01 | `Arithmetic Operations Per Type | subtract__instance__int64_t | 1000000`
	|   198.9% |          956,000.00 |            1,046.03 |    0.1% |      0.01 | `Arithmetic Operations Per Type | subtract__instance__size_t | 1000000`
	|    61.3% |        3,104,100.00 |              322.15 |    0.0% |      0.03 | `Arithmetic Operations Per Type | subtract__instance__float | 1000000`
	|    61.3% |        3,104,200.00 |              322.14 |    0.0% |      0.03 | `Arithmetic Operations Per Type | subtract__instance__double | 1000000`
	|    61.2% |        3,104,500.00 |              322.11 |    0.0% |      0.03 | `Arithmetic Operations Per Type | subtract__instance__long_double | 1000000`
	|    88.5% |        2,148,600.00 |              465.42 |    0.0% |      0.02 | `Arithmetic Operations Per Type | multiply__instance__char | 1000000`
	|    88.5% |        2,148,600.00 |              465.42 |    0.0% |      0.02 | `Arithmetic Operations Per Type | multiply__instance__short_int | 1000000`
	|    99.5% |        1,911,900.00 |              523.04 |    0.1% |      0.02 | `Arithmetic Operations Per Type | multiply__instance__int | 1000000`
	|    99.5% |        1,910,000.00 |              523.56 |    0.0% |      0.02 | `Arithmetic Operations Per Type | multiply__instance__long_int | 1000000`
	|    99.5% |        1,910,200.00 |              523.51 |    0.0% |      0.02 | `Arithmetic Operations Per Type | multiply__instance__long_long_int | 1000000`
	|    88.5% |        2,148,600.00 |              465.42 |    0.0% |      0.02 | `Arithmetic Operations Per Type | multiply__instance__int8_t | 1000000`
	|    88.5% |        2,149,400.00 |              465.25 |    0.0% |      0.02 | `Arithmetic Operations Per Type | multiply__instance__int16_t | 1000000`
	|    99.5% |        1,910,100.00 |              523.53 |    0.0% |      0.02 | `Arithmetic Operations Per Type | multiply__instance__int32_t | 1000000`
	|    99.5% |        1,911,000.00 |              523.29 |    0.1% |      0.02 | `Arithmetic Operations Per Type | multiply__instance__int64_t | 1000000`
	|    99.5% |        1,910,500.00 |              523.42 |    0.0% |      0.02 | `Arithmetic Operations Per Type | multiply__instance__size_t | 1000000`
	|    88.4% |        2,151,200.00 |              464.86 |    0.1% |      0.02 | `Arithmetic Operations Per Type | multiply__instance__float | 1000000`
	|    88.2% |        2,155,500.00 |              463.93 |    0.3% |      0.02 | `Arithmetic Operations Per Type | multiply__instance__double | 1000000`
	|    88.4% |        2,150,000.00 |              465.12 |    0.1% |      0.02 | `Arithmetic Operations Per Type | multiply__instance__long_double | 1000000`
	|   198.9% |          955,800.00 |            1,046.24 |    0.1% |      0.01 | `Arithmetic Operations Per Type | divide__instance__char | 1000000`
	|   198.9% |          955,800.00 |            1,046.24 |    0.1% |      0.01 | `Arithmetic Operations Per Type | divide__instance__short_int | 1000000`
	|   199.0% |          955,300.00 |            1,046.79 |    0.1% |      0.01 | `Arithmetic Operations Per Type | divide__instance__int | 1000000`
	|   199.0% |          955,400.00 |            1,046.68 |    0.1% |      0.01 | `Arithmetic Operations Per Type | divide__instance__long_int | 1000000`
	|   198.7% |          957,000.00 |            1,044.93 |    0.3% |      0.01 | `Arithmetic Operations Per Type | divide__instance__long_long_int | 1000000`
	|   198.9% |          955,800.00 |            1,046.24 |    0.1% |      0.01 | `Arithmetic Operations Per Type | divide__instance__int8_t | 1000000`
	|   199.0% |          955,300.00 |            1,046.79 |    0.1% |      0.01 | `Arithmetic Operations Per Type | divide__instance__int16_t | 1000000`
	|   199.0% |          955,300.00 |            1,046.79 |    0.1% |      0.01 | `Arithmetic Operations Per Type | divide__instance__int32_t | 1000000`
	|   199.0% |          955,600.00 |            1,046.46 |    0.1% |      0.01 | `Arithmetic Operations Per Type | divide__instance__int64_t | 1000000`
	|   198.6% |          957,400.00 |            1,044.50 |    0.3% |      0.01 | `Arithmetic Operations Per Type | divide__instance__size_t | 1000000`
	|   199.0% |          955,500.00 |            1,046.57 |    0.1% |      0.01 | `Arithmetic Operations Per Type | divide__instance__float | 1000000`
	|   199.0% |          955,300.00 |            1,046.79 |    0.1% |      0.01 | `Arithmetic Operations Per Type | divide__instance__double | 1000000`
	|   199.0% |          955,500.00 |            1,046.57 |    0.1% |      0.01 | `Arithmetic Operations Per Type | divide__instance__long_double | 1000000`

	*/

	class Samples
	{
	public:
		char char_instance_value = 1;

		int int_instance_value = 1;

		short int short_int_instance_value = 1;

		long int long_int_instance_value = 1;

		long long int long_long_int_instance_value = 1;

		int8_t int8_t_instance_value = 1;

		int16_t int16_t_instance_value = 1;

		int32_t int32_t_instance_value = 1;

		int64_t int64_t_instance_value = 1;

		size_t size_t_instance_value = 1;

		float float_instance_value = 1.0;

		double double_instance_value = 1.0;

		long double long_double_instance_value = 1.0;

		static Samples instance;

		void add__instance__char()
		{
			char_instance_value += char_instance_value + 1;
		}

		void add__instance__short_int()
		{
			short_int_instance_value += short_int_instance_value + 1;
		}

		void add__instance__int()
		{
			int_instance_value += int_instance_value + 1;
		}

		void add__instance__long_int()
		{
			long_int_instance_value += long_int_instance_value + 1;
		}

		void add__instance__long_long_int()
		{
			long_long_int_instance_value += long_long_int_instance_value + 1;
		}

		void add__instance__int8_t()
		{
			int8_t_instance_value += int8_t_instance_value + 1;
		}

		void add__instance__int16_t()
		{
			int16_t_instance_value += int16_t_instance_value + 1;
		}

		void add__instance__int32_t()
		{
			int32_t_instance_value += int32_t_instance_value + 1;
		}

		void add__instance__int64_t()
		{
			int64_t_instance_value += int64_t_instance_value + 1;
		}

		void add__instance__size_t()
		{
			size_t_instance_value += size_t_instance_value + 1;

		}

		void add__instance__float()
		{
			float_instance_value += float_instance_value + 1.0;
		}

		void add__instance__double()
		{
			double_instance_value += double_instance_value + 1.0;
		}

		void add__instance__long_double()
		{
			long_double_instance_value += long_double_instance_value + 1.0;
		}



		void multiply__instance__char()
		{
			char_instance_value *= char_instance_value * 1;
		}

		void multiply__instance__short_int()
		{
			short_int_instance_value *= short_int_instance_value * 1;
		}

		void multiply__instance__int()
		{
			int_instance_value *= int_instance_value * 1;
		}

		void multiply__instance__long_int()
		{
			long_int_instance_value *= long_int_instance_value * 1;
		}

		void multiply__instance__long_long_int()
		{
			long_long_int_instance_value *= long_long_int_instance_value * 1;
		}

		void multiply__instance__int8_t()
		{
			int8_t_instance_value *= int8_t_instance_value * 1;
		}

		void multiply__instance__int16_t()
		{
			int16_t_instance_value *= int16_t_instance_value * 1;
		}

		void multiply__instance__int32_t()
		{
			int32_t_instance_value *= int32_t_instance_value * 1;
		}

		void multiply__instance__int64_t()
		{
			int64_t_instance_value *= int64_t_instance_value * 1;
		}

		void multiply__instance__size_t()
		{
			size_t_instance_value *= size_t_instance_value * 1;

		}

		void multiply__instance__float()
		{
			float_instance_value *= float_instance_value * 1.0;
		}

		void multiply__instance__double()
		{
			double_instance_value *= double_instance_value * 1.0;
		}

		void multiply__instance__long_double()
		{
			long_double_instance_value *= long_double_instance_value * 1.0;
		}



		void subtract__instance__char()
		{
			char_instance_value -= char_instance_value - 1;
		}

		void subtract__instance__short_int()
		{
			short_int_instance_value -= short_int_instance_value - 1;
		}

		void subtract__instance__int()
		{
			int_instance_value -= int_instance_value - 1;
		}

		void subtract__instance__long_int()
		{
			long_int_instance_value -= long_int_instance_value - 1;
		}

		void subtract__instance__long_long_int()
		{
			long_long_int_instance_value -= long_long_int_instance_value - 1;
		}

		void subtract__instance__int8_t()
		{
			int8_t_instance_value -= int8_t_instance_value - 1;
		}

		void subtract__instance__int16_t()
		{
			int16_t_instance_value -= int16_t_instance_value - 1;
		}

		void subtract__instance__int32_t()
		{
			int32_t_instance_value -= int32_t_instance_value - 1;
		}

		void subtract__instance__int64_t()
		{
			int64_t_instance_value -= int64_t_instance_value - 1;
		}

		void subtract__instance__size_t()
		{
			size_t_instance_value -= size_t_instance_value - 1;

		}

		void subtract__instance__float()
		{
			float_instance_value -= float_instance_value - 1.0;
		}

		void subtract__instance__double()
		{
			double_instance_value -= double_instance_value - 1.0;
		}

		void subtract__instance__long_double()
		{
			long_double_instance_value -= long_double_instance_value - 1.0;
		}


		void divide__instance__char()
		{
			char_instance_value = char_instance_value / 1;
		}

		void divide__instance__short_int()
		{
			short_int_instance_value = short_int_instance_value / 1;
		}

		void divide__instance__int()
		{
			int_instance_value = int_instance_value / 1;
		}

		void divide__instance__long_int()
		{
			long_int_instance_value = long_int_instance_value / 1;
		}

		void divide__instance__long_long_int()
		{
			long_long_int_instance_value = long_long_int_instance_value / 1;
		}

		void divide__instance__int8_t()
		{
			int8_t_instance_value = int8_t_instance_value / 1;
		}

		void divide__instance__int16_t()
		{
			int16_t_instance_value = int16_t_instance_value / 1;
		}

		void divide__instance__int32_t()
		{
			int32_t_instance_value = int32_t_instance_value / 1;
		}

		void divide__instance__int64_t()
		{
			int64_t_instance_value = int64_t_instance_value / 1;
		}

		void divide__instance__size_t()
		{
			size_t_instance_value = size_t_instance_value / 1;

		}

		void divide__instance__float()
		{
			float_instance_value = float_instance_value / 1.0;
		}

		void divide__instance__double()
		{
			double_instance_value = double_instance_value / 1.0;
		}

		void divide__instance__long_double()
		{
			long_double_instance_value = long_double_instance_value / 1.0;
		}
	};

	Samples Samples::instance;

	void execute()
	{
		NanobenchBenchmarkingTestSuite test_suite
		{
			.name = "Arithmetic Operations Per Type",
			.epoch_iteration_pairs =
			{
				{
					.epochs = 20000000,
					.iterations = 1
				},
				{
					.epochs = 20000,
					.iterations = 1000
				},
				{
					.epochs = 1,
					.iterations = 1000000
				}
			},
			.test_cases =
			{
				{
					.name = "add__instance__char",
					.callback = []() { Samples::instance.add__instance__char(); }
				},
				{
					.name = "add__instance__short_int",
					.callback = []() { Samples::instance.add__instance__short_int(); }
				},
				{
					.name = "add__instance__int",
					.callback = []() { Samples::instance.add__instance__int(); }
				},
				{
					.name = "add__instance__long_int",
					.callback = []() { Samples::instance.add__instance__long_int(); }
				},
				{
					.name = "add__instance__long_long_int",
					.callback = []() { Samples::instance.add__instance__long_long_int(); }
				},
				{
					.name = "add__instance__int8_t",
					.callback = []() { Samples::instance.add__instance__int8_t(); }
				},
				{
					.name = "add__instance__int16_t",
					.callback = []() { Samples::instance.add__instance__int16_t(); }
				},
				{
					.name = "add__instance__int32_t",
					.callback = []() { Samples::instance.add__instance__int32_t(); }
				},
				{
					.name = "add__instance__int64_t",
					.callback = []() { Samples::instance.add__instance__int64_t(); }
				},
				{
					.name = "add__instance__size_t",
					.callback = []() { Samples::instance.add__instance__size_t(); }
				},
				{
					.name = "add__instance__float",
					.callback = []() { Samples::instance.add__instance__float(); }
				},
				{
					.name = "add__instance__double",
					.callback = []() { Samples::instance.add__instance__double(); }
				},
				{
					.name = "add__instance__long_double",
					.callback = []() { Samples::instance.add__instance__long_double(); }
				},

				{
					.name = "subtract__instance__char",
					.callback = []() { Samples::instance.subtract__instance__char(); }
				},
				{
					.name = "subtract__instance__short_int",
					.callback = []() { Samples::instance.subtract__instance__short_int(); }
				},
				{
					.name = "subtract__instance__int",
					.callback = []() { Samples::instance.subtract__instance__int(); }
				},
				{
					.name = "subtract__instance__long_int",
					.callback = []() { Samples::instance.subtract__instance__long_int(); }
				},
				{
					.name = "subtract__instance__long_long_int",
					.callback = []() { Samples::instance.subtract__instance__long_long_int(); }
				},
				{
					.name = "subtract__instance__int8_t",
					.callback = []() { Samples::instance.subtract__instance__int8_t(); }
				},
				{
					.name = "subtract__instance__int16_t",
					.callback = []() { Samples::instance.subtract__instance__int16_t(); }
				},
				{
					.name = "subtract__instance__int32_t",
					.callback = []() { Samples::instance.subtract__instance__int32_t(); }
				},
				{
					.name = "subtract__instance__int64_t",
					.callback = []() { Samples::instance.subtract__instance__int64_t(); }
				},
				{
					.name = "subtract__instance__size_t",
					.callback = []() { Samples::instance.subtract__instance__size_t(); }
				},
				{
					.name = "subtract__instance__float",
					.callback = []() { Samples::instance.subtract__instance__float(); }
				},
				{
					.name = "subtract__instance__double",
					.callback = []() { Samples::instance.subtract__instance__double(); }
				},
				{
					.name = "subtract__instance__long_double",
					.callback = []() { Samples::instance.subtract__instance__long_double(); }
				},


				{
					.name = "multiply__instance__char",
					.callback = []() { Samples::instance.multiply__instance__char(); }
				},
				{
					.name = "multiply__instance__short_int",
					.callback = []() { Samples::instance.multiply__instance__short_int(); }
				},
				{
					.name = "multiply__instance__int",
					.callback = []() { Samples::instance.multiply__instance__int(); }
				},
				{
					.name = "multiply__instance__long_int",
					.callback = []() { Samples::instance.multiply__instance__long_int(); }
				},
				{
					.name = "multiply__instance__long_long_int",
					.callback = []() { Samples::instance.multiply__instance__long_long_int(); }
				},
				{
					.name = "multiply__instance__int8_t",
					.callback = []() { Samples::instance.multiply__instance__int8_t(); }
				},
				{
					.name = "multiply__instance__int16_t",
					.callback = []() { Samples::instance.multiply__instance__int16_t(); }
				},
				{
					.name = "multiply__instance__int32_t",
					.callback = []() { Samples::instance.multiply__instance__int32_t(); }
				},
				{
					.name = "multiply__instance__int64_t",
					.callback = []() { Samples::instance.multiply__instance__int64_t(); }
				},
				{
					.name = "multiply__instance__size_t",
					.callback = []() { Samples::instance.multiply__instance__size_t(); }
				},
				{
					.name = "multiply__instance__float",
					.callback = []() { Samples::instance.multiply__instance__float(); }
				},
				{
					.name = "multiply__instance__double",
					.callback = []() { Samples::instance.multiply__instance__double(); }
				},
				{
					.name = "multiply__instance__long_double",
					.callback = []() { Samples::instance.multiply__instance__long_double(); }
				},


				{
					.name = "divide__instance__char",
					.callback = []() { Samples::instance.divide__instance__char(); }
				},
				{
					.name = "divide__instance__short_int",
					.callback = []() { Samples::instance.divide__instance__short_int(); }
				},
				{
					.name = "divide__instance__int",
					.callback = []() { Samples::instance.divide__instance__int(); }
				},
				{
					.name = "divide__instance__long_int",
					.callback = []() { Samples::instance.divide__instance__long_int(); }
				},
				{
					.name = "divide__instance__long_long_int",
					.callback = []() { Samples::instance.divide__instance__long_long_int(); }
				},
				{
					.name = "divide__instance__int8_t",
					.callback = []() { Samples::instance.divide__instance__int8_t(); }
				},
				{
					.name = "divide__instance__int16_t",
					.callback = []() { Samples::instance.divide__instance__int16_t(); }
				},
				{
					.name = "divide__instance__int32_t",
					.callback = []() { Samples::instance.divide__instance__int32_t(); }
				},
				{
					.name = "divide__instance__int64_t",
					.callback = []() { Samples::instance.divide__instance__int64_t(); }
				},
				{
					.name = "divide__instance__size_t",
					.callback = []() { Samples::instance.divide__instance__size_t(); }
				},
				{
					.name = "divide__instance__float",
					.callback = []() { Samples::instance.divide__instance__float(); }
				},
				{
					.name = "divide__instance__double",
					.callback = []() { Samples::instance.divide__instance__double(); }
				},
				{
					.name = "divide__instance__long_double",
					.callback = []() { Samples::instance.divide__instance__long_double(); }
				},
			}
		};

		execute_nanobenchmark(
			test_suite
		);

		bool exit_code;
		std::cin >> exit_code;
	}
}


namespace StringOperations // string_view
{
	/*
	Results:

	| relative |               ns/op |                op/s |    err% |     total | benchmark
	|---------:|--------------------:|--------------------:|--------:|----------:|:----------
	|   100.0% |                3.87 |      258,130,456.78 |    0.7% |      0.49 | `String Operations | assign__string_to_string | 1`
	|   320.5% |                1.21 |      827,404,997.58 |    0.3% |      0.15 | `String Operations | assign__string_view_to_string_view | 1`
	|    99.4% |                3.90 |      256,629,770.35 |    0.1% |      0.47 | `String Operations | assign__string_view_to_string | 1`
	|   320.0% |                1.21 |      825,890,885.62 |    0.3% |      0.15 | `String Operations | assign__string_to_string_view | 1`
	|    29.0% |               13.35 |       74,933,394.59 |    1.1% |      1.62 | `String Operations | assign__string_parameter__const_arguments__concatenate_string | 1`
	|    28.9% |               13.41 |       74,552,514.90 |    0.7% |      1.62 | `String Operations | assign__const_string_parameter__const_arguments__concatenate_string | 1`
	|   228.6% |                1.69 |      590,074,986.87 |    0.9% |      0.20 | `String Operations | assign__reference_string_parameter__instance_arguments__concatenate_string | 1`
	|    55.8% |                6.94 |      144,041,334.25 |    0.2% |      0.76 | `String Operations | assign__const_reference_string_parameter__const_arguments__concatenate_string | 1`
	|    83.6% |                4.63 |      215,909,872.42 |    0.3% |      0.56 | `String Operations | return_and_assign__string_parameter__const_arguments__concatenate_string | 1`
	|    83.2% |                4.66 |      214,751,888.69 |    0.4% |      0.56 | `String Operations | return_and_assign__const_string_parameter__const_arguments__concatenate_string | 1`
	|   228.2% |                1.70 |      589,098,997.32 |    1.3% |      0.21 | `String Operations | return_and_assign__reference_string_parameter__instance_arguments__concatenate_string | 1`
	|   201.0% |                1.93 |      518,841,586.37 |    0.6% |      0.23 | `String Operations | return_and_assign__const_reference_string_parameter__const_arguments__concatenate_string | 1`
	|     1.9% |              198.85 |        5,028,808.96 |    2.5% |     23.83 | `String Operations | recursive__pass_and_return__const_reference_string_parameter__const_arguments__concatenate_string | 1`
	|     2.0% |              195.93 |        5,103,973.49 |    0.7% |     24.32 | `String Operations | recursive__pass_and_return__const_reference_string_view_parameter__const_arguments__concatenate_string | 1`
	|     1.6% |              240.06 |        4,165,650.83 |    1.8% |     28.91 | `String Operations | recursive__pass_and_return__const_reference_char_string_parameter__const_arguments__concatenate_string | 1`
	|    13.9% |               27.82 |       35,941,841.90 |    0.5% |      3.38 | `String Operations | recursive__pass__const_reference_string_parameter__const_arguments__concatenate_string | 1`
	|    15.2% |               25.56 |       39,129,338.96 |    1.0% |      3.10 | `String Operations | recursive__pass__const_reference_string_view_parameter__const_arguments__concatenate_string | 1`
	|    11.9% |               32.52 |       30,751,979.08 |    0.8% |      3.94 | `String Operations | recursive__pass__const_reference_char_string_parameter__const_arguments__concatenate_string | 1`

	|   100.0% |            3,673.60 |          272,212.74 |    0.3% |      0.44 | `String Operations | assign__string_to_string | 1000`
	|   374.4% |              981.17 |        1,019,187.27 |    0.5% |      0.12 | `String Operations | assign__string_view_to_string_view | 1000`
	|    98.9% |            3,713.30 |          269,302.47 |    0.2% |      0.45 | `String Operations | assign__string_view_to_string | 1000`
	|   331.6% |            1,108.00 |          902,524.91 |    0.4% |      0.13 | `String Operations | assign__string_to_string_view | 1000`
	|    27.6% |           13,301.49 |           75,179.55 |    0.4% |      1.61 | `String Operations | assign__string_parameter__const_arguments__concatenate_string | 1000`
	|    27.5% |           13,345.91 |           74,929.31 |    0.4% |      1.61 | `String Operations | assign__const_string_parameter__const_arguments__concatenate_string | 1000`
	|   234.4% |            1,566.97 |          638,176.33 |    1.3% |      0.19 | `String Operations | assign__reference_string_parameter__instance_arguments__concatenate_string | 1000`
	|    59.1% |            6,220.40 |          160,761.46 |    0.1% |      0.76 | `String Operations | assign__const_reference_string_parameter__const_arguments__concatenate_string | 1000`
	|    74.9% |            4,905.75 |          203,842.42 |    0.5% |      0.59 | `String Operations | return_and_assign__string_parameter__const_arguments__concatenate_string | 1000`
	|    74.9% |            4,905.04 |          203,871.76 |    0.3% |      0.59 | `String Operations | return_and_assign__const_string_parameter__const_arguments__concatenate_string | 1000`
	|   229.4% |            1,601.45 |          624,435.52 |    2.7% |      0.20 | `String Operations | return_and_assign__reference_string_parameter__instance_arguments__concatenate_string | 1000`
	|   206.1% |            1,782.42 |          561,033.55 |    0.5% |      0.22 | `String Operations | return_and_assign__const_reference_string_parameter__const_arguments__concatenate_string | 1000`
	|     1.7% |          218,880.04 |            4,568.71 |    1.4% |     26.23 | `String Operations | recursive__pass_and_return__const_reference_string_parameter__const_arguments__concatenate_string | 1000`
	|     1.8% |          199,754.10 |            5,006.16 |    0.3% |     24.18 | `String Operations | recursive__pass_and_return__const_reference_string_view_parameter__const_arguments__concatenate_string | 1000`
	|     1.6% |          226,195.24 |            4,420.96 |    0.9% |     27.49 | `String Operations | recursive__pass_and_return__const_reference_char_string_parameter__const_arguments__concatenate_string | 1000`
	|    12.8% |           28,611.99 |           34,950.39 |    0.1% |      3.46 | `String Operations | recursive__pass__const_reference_string_parameter__const_arguments__concatenate_string | 1000`
	|    12.7% |           28,947.43 |           34,545.38 |    0.6% |      3.50 | `String Operations | recursive__pass__const_reference_string_view_parameter__const_arguments__concatenate_string | 1000`
	|    10.5% |           34,946.34 |           28,615.30 |    0.2% |      4.23 | `String Operations | recursive__pass__const_reference_char_string_parameter__const_arguments__concatenate_string | 1000`

	|   100.0% |        3,610,890.00 |              276.94 |    0.4% |      0.44 | `String Operations | assign__string_to_string | 1000000`
	|   377.1% |          957,541.67 |            1,044.34 |    0.3% |      0.12 | `String Operations | assign__string_view_to_string_view | 1000000`
	|    99.8% |        3,618,533.33 |              276.36 |    0.4% |      0.44 | `String Operations | assign__string_view_to_string | 1000000`
	|   332.7% |        1,085,180.00 |              921.51 |    0.4% |      0.13 | `String Operations | assign__string_to_string_view | 1000000`
	|    27.3% |       13,223,490.91 |               75.62 |    0.2% |      1.61 | `String Operations | assign__string_parameter__const_arguments__concatenate_string | 1000000`
	|    27.2% |       13,278,575.00 |               75.31 |    0.1% |      1.62 | `String Operations | assign__const_string_parameter__const_arguments__concatenate_string | 1000000`
	|   241.2% |        1,496,781.82 |              668.10 |    0.2% |      0.18 | `String Operations | assign__reference_string_parameter__instance_arguments__concatenate_string | 1000000`
	|    58.1% |        6,213,336.36 |              160.94 |    0.1% |      0.76 | `String Operations | assign__const_reference_string_parameter__const_arguments__concatenate_string | 1000000`
	|    77.2% |        4,676,363.64 |              213.84 |    1.0% |      0.57 | `String Operations | return_and_assign__string_parameter__const_arguments__concatenate_string | 1000000`
	|    76.8% |        4,701,075.00 |              212.72 |    0.8% |      0.57 | `String Operations | return_and_assign__const_string_parameter__const_arguments__concatenate_string | 1000000`
	|   243.0% |        1,486,016.67 |              672.94 |    1.0% |      0.18 | `String Operations | return_and_assign__reference_string_parameter__instance_arguments__concatenate_string | 1000000`
	|   207.3% |        1,741,718.18 |              574.15 |    0.3% |      0.21 | `String Operations | return_and_assign__const_reference_string_parameter__const_arguments__concatenate_string | 1000000`
	|     1.7% |      207,753,390.91 |                4.81 |    1.2% |     25.70 | `String Operations | recursive__pass_and_return__const_reference_string_parameter__const_arguments__concatenate_string | 1000000`
	|     1.9% |      193,253,275.00 |                5.17 |    0.3% |     23.69 | `String Operations | recursive__pass_and_return__const_reference_string_view_parameter__const_arguments__concatenate_string | 1000000`
	|     1.6% |      226,073,530.00 |                4.42 |    0.7% |     27.85 | `String Operations | recursive__pass_and_return__const_reference_char_string_parameter__const_arguments__concatenate_string | 1000000`
	|    13.0% |       27,698,570.00 |               36.10 |    1.5% |      3.37 | `String Operations | recursive__pass__const_reference_string_parameter__const_arguments__concatenate_string | 1000000`
	|    15.2% |       23,760,136.36 |               42.09 |    0.8% |      2.90 | `String Operations | recursive__pass__const_reference_string_view_parameter__const_arguments__concatenate_string | 1000000`
	|    10.8% |       33,395,383.33 |               29.94 |    0.5% |      4.07 | `String Operations | recursive__pass__const_reference_char_string_parameter__const_arguments__concatenate_string | 1000000`
	*/

	class Samples
	{
	public:
		std::string instance_string_input = "a";

		std::string instance_string_output = "";

		std::string instance_string_output_2 = "";

		std::string_view instance_string_view_input = "a";

		std::string_view instance_string_view_output = "";

		static Samples instance;

		void assign__string_to_string()
		{
			instance_string_output =
				instance_string_input;
		}

		void assign__string_view_to_string_view()
		{
			instance_string_view_output =
				instance_string_view_input;
		}

		void assign__string_view_to_string()
		{
			instance_string_output =
				instance_string_view_input;
		}

		void assign__string_to_string_view()
		{
			instance_string_view_output =
				instance_string_input;
		}

		void assign__string_parameter__const_arguments__concatenate_string(
			std::string a, std::string b
		)
		{
			instance_string_output =
				a + b;
		}

		void assign__const_string_parameter__const_arguments__concatenate_string(
			const std::string a, const std::string b
		)
		{
			instance_string_output =
				a + b;
		}

		void assign__reference_string_parameter__instance_arguments__concatenate_string(
			std::string& a, std::string& b
		)
		{
			a += b;
		}

		void assign__const_reference_string_parameter__const_arguments__concatenate_string(
			const std::string& a, const std::string& b
		)
		{
			instance_string_output =
				a + b;
		}

		std::string return_and_assign__string_parameter__const_arguments__concatenate_string(
			std::string a, std::string b
		)
		{
			return
				a + b;
		}

		std::string return_and_assign__const_string_parameter__const_arguments__concatenate_string(
			const std::string a, const std::string b
		)
		{
			return
				a + b;
		}

		std::string return_and_assign__reference_string_parameter__instance_arguments__concatenate_string(
			std::string& a, std::string& b
		)
		{
			return
				a + b;
		}

		std::string return_and_assign__const_reference_string_parameter__const_arguments__concatenate_string(
			const std::string& a, const std::string& b
		)
		{
			return
				a + b;
		}



		std::string recursive__pass_and_return__const_reference_string_parameter__const_arguments__concatenate_string(
			const std::string& value_1,
			const std::string& value_2,
			const std::size_t layers
		)
		{
			if (layers == 0)
			{
				return value_1 + value_2;
			}

			return recursive__pass_and_return__const_reference_string_parameter__const_arguments__concatenate_string(
				value_1,
				value_2,
				layers - 1
			);
		}

		std::string recursive__pass_and_return__const_reference_string_view_parameter__const_arguments__concatenate_string(
			const std::string_view& value_1,
			const std::string_view& value_2,
			const std::size_t layers
		)
		{
			if (layers == 0)
			{
				return std::string(value_1.data()) + value_2.data();
			}

			return recursive__pass_and_return__const_reference_string_view_parameter__const_arguments__concatenate_string(
				value_1,
				value_2,
				layers - 1
			);
		}

		std::string recursive__pass_and_return__const_reference_char_string_parameter__const_arguments__concatenate_string(
			const char* value_1,
			const char* value_2,
			const std::size_t layers
		)
		{
			if (layers == 0)
			{
				return std::string(value_1) + std::string(value_2);
			}

			return recursive__pass_and_return__const_reference_char_string_parameter__const_arguments__concatenate_string(
				value_1,
				value_2,
				layers - 1
			);
		}
		void recursive__pass__const_reference_string_parameter__const_arguments__concatenate_string(
			std::string& output,
			const std::string& value_1,
			const std::string& value_2,
			const std::size_t layers
		)
		{
			if (layers == 0)
			{
				output = value_1 + value_2;
				return;
			}

			recursive__pass__const_reference_string_parameter__const_arguments__concatenate_string(
				output,
				value_1,
				value_2,
				layers - 1
			);
		}

		void recursive__pass__const_reference_string_view_parameter__const_arguments__concatenate_string(
			std::string& output,
			const std::string_view& value_1,
			const std::string_view& value_2,
			const std::size_t layers
		)
		{
			if (layers == 0)
			{
				output = std::string(value_1.data()) + value_2.data();
				return;
			}

			recursive__pass__const_reference_string_view_parameter__const_arguments__concatenate_string(
				output,
				value_1,
				value_2,
				layers - 1
			);
		}

		void recursive__pass__const_reference_char_string_parameter__const_arguments__concatenate_string(
			std::string& output,
			const char* value_1,
			const char* value_2,
			const std::size_t layers
		)
		{
			if (layers == 0)
			{
				output = std::string(value_1) + std::string(value_2);
				return;
			}

			recursive__pass__const_reference_char_string_parameter__const_arguments__concatenate_string(
				output,
				value_1,
				value_2,
				layers - 1
			);
		}


	};

	Samples Samples::instance;

	void execute()
	{
		NanobenchBenchmarkingTestSuite test_suite
		{
			.name = "String Operations",
			.epoch_iteration_pairs =
			{
				{
					.epochs = 10000000,
					.iterations = 1
				},
				{
					.epochs = 10000,
					.iterations = 1000
				},
				{
					.epochs = 10,
					.iterations = 1000000
				}
			},
			.test_cases =
			{
				{
					.name = "assign__string_to_string",
					.callback = []() { Samples::instance.assign__string_to_string(); }
				},
				{
					.name = "assign__string_view_to_string_view",
					.callback = []() { Samples::instance.assign__string_view_to_string_view(); }
				},
				{
					.name = "assign__string_view_to_string",
					.callback = []() { Samples::instance.assign__string_view_to_string(); }
				},
				{
					.name = "assign__string_to_string_view",
					.callback = []() { Samples::instance.assign__string_to_string_view(); }
				},
				{
					.name = "assign__string_parameter__const_arguments__concatenate_string",
					.callback = []()
					{
						Samples::instance
							.assign__string_parameter__const_arguments__concatenate_string("a", "a");
					}
				},
				{
					.name = "assign__const_string_parameter__const_arguments__concatenate_string",
					.callback = []()
					{
						Samples::instance
							.assign__const_string_parameter__const_arguments__concatenate_string("a", "a");
					}
				},
				{
					.name = "assign__reference_string_parameter__instance_arguments__concatenate_string",
					.callback = []()
					{
						std::string input_1 = "";
						std::string input_2 = "";
						Samples::instance
							.assign__reference_string_parameter__instance_arguments__concatenate_string(input_1, input_2);
					}
				},
				{
					.name = "assign__const_reference_string_parameter__const_arguments__concatenate_string",
					.callback = []()
					{
						Samples::instance
							.assign__const_reference_string_parameter__const_arguments__concatenate_string("a", "a");
					}
				},

				{
					.name = "return_and_assign__string_parameter__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string v = Samples::instance
							.return_and_assign__string_parameter__const_arguments__concatenate_string("a", "a");
					}
				},
				{
					.name = "return_and_assign__const_string_parameter__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string v = Samples::instance
							.return_and_assign__const_string_parameter__const_arguments__concatenate_string("a", "a");
					}
				},
				{
					.name = "return_and_assign__reference_string_parameter__instance_arguments__concatenate_string",
					.callback = []()
					{
						std::string input_1 = "";
						std::string input_2 = "";
						std::string v = Samples::instance
							.return_and_assign__reference_string_parameter__instance_arguments__concatenate_string(input_1, input_2);
					}
				},
				{
					.name = "return_and_assign__const_reference_string_parameter__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string v = Samples::instance
							.return_and_assign__const_reference_string_parameter__const_arguments__concatenate_string("a", "a");
					}
				},
				{
					.name = "recursive__pass_and_return__const_reference_string_parameter__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string v = Samples::instance
							.recursive__pass_and_return__const_reference_string_parameter__const_arguments__concatenate_string("a", "a", 40);
					}
				},
				{
					.name = "recursive__pass_and_return__const_reference_string_view_parameter__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string v = Samples::instance
							.recursive__pass_and_return__const_reference_string_view_parameter__const_arguments__concatenate_string("a", "a", 40);
					}
				},
				{
					.name = "recursive__pass_and_return__const_reference_char_string_parameter__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string v = Samples::instance
							.recursive__pass_and_return__const_reference_char_string_parameter__const_arguments__concatenate_string("a", "a", 40);
					}
				},
				{
					.name = "recursive__pass__const_reference_string_parameter__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string output = "";
						Samples::instance
							.recursive__pass__const_reference_string_parameter__const_arguments__concatenate_string(output, "a", "a", 40);
					}
				},
				{
					.name = "recursive__pass__const_reference_string_view_parameter__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string output = "";
						Samples::instance
							.recursive__pass__const_reference_string_view_parameter__const_arguments__concatenate_string(output, "a", "a", 40);
					}
				},
				{
					.name = "recursive__pass__const_reference_char_string_parameter__const_arguments__concatenate_string",
					.callback = []()
					{
						std::string output = "";
						Samples::instance
							.recursive__pass__const_reference_char_string_parameter__const_arguments__concatenate_string(output, "a", "a", 40);
					}
				}

			}
		};

		execute_nanobenchmark(
			test_suite
		);

		bool exit_code;
		std::cin >> exit_code;
	}
}



namespace ExecutionWithinNestedNamespaces // all
{
	/*

	Conclusion
	- No significant performance difference

	Usage
	- Indiscriminate

	| relative |               ns/op |                op/s |    err% |     total | benchmark
	|---------:|--------------------:|--------------------:|--------:|----------:|:----------
	|   100.0% |                3.12 |      320,870,434.23 |    0.2% |      3.78 | `Namespace Layers | layer_0 | 1`
	|   100.2% |                3.11 |      321,625,795.53 |    0.1% |      3.76 | `Namespace Layers | Layer1::layer_1 | 1`
	|   100.3% |                3.11 |      321,758,366.82 |    0.0% |      3.76 | `Namespace Layers | Layer1::Layer2::layer_2 | 1`
	|   100.1% |                3.11 |      321,075,843.00 |    0.0% |      3.77 | `Namespace Layers | Layer1::Layer2::Layer3::layer_3 | 1`
	|   100.0% |                3.12 |      320,865,499.26 |    0.2% |      3.77 | `Namespace Layers | Layer1::Layer2::Layer3::Layer4::layer_4 | 1`
	|   100.3% |                3.11 |      321,716,101.28 |    0.0% |      3.76 | `Namespace Layers | Layer1::Layer2::Layer3::Layer4::Layer5::layer_5 | 1`

	|   100.0% |            3,112.98 |          321,235.58 |    0.1% |      3.77 | `Namespace Layers | layer_0 | 1000`
	|   100.1% |            3,108.33 |          321,715.92 |    0.0% |      3.76 | `Namespace Layers | Layer1::layer_1 | 1000`
	|   100.2% |            3,108.01 |          321,749.66 |    0.0% |      3.76 | `Namespace Layers | Layer1::Layer2::layer_2 | 1000`
	|   100.1% |            3,109.03 |          321,644.19 |    0.0% |      3.77 | `Namespace Layers | Layer1::Layer2::Layer3::layer_3 | 1000`
	|   100.2% |            3,107.40 |          321,812.44 |    0.0% |      3.76 | `Namespace Layers | Layer1::Layer2::Layer3::Layer4::layer_4 | 1000`
	|   100.2% |            3,107.50 |          321,801.99 |    0.0% |      3.76 | `Namespace Layers | Layer1::Layer2::Layer3::Layer4::Layer5::layer_5 | 1000`

	|   100.0% |        3,108,554.55 |              321.69 |    0.1% |      0.38 | `Namespace Layers | layer_0 | 1000000`
	|   100.1% |        3,106,845.45 |              321.87 |    0.1% |      0.38 | `Namespace Layers | Layer1::layer_1 | 1000000`
	|    95.8% |        3,243,275.00 |              308.33 |    1.2% |      0.40 | `Namespace Layers | Layer1::Layer2::layer_2 | 1000000`
	|   100.0% |        3,109,916.67 |              321.55 |    0.2% |      0.38 | `Namespace Layers | Layer1::Layer2::Layer3::layer_3 | 1000000`
	|   100.0% |        3,109,481.82 |              321.60 |    0.1% |      0.38 | `Namespace Layers | Layer1::Layer2::Layer3::Layer4::layer_4 | 1000000`
	|    99.9% |        3,110,250.00 |              321.52 |    0.1% |      0.38 | `Namespace Layers | Layer1::Layer2::Layer3::Layer4::Layer5::layer_5 | 1000000`

	*/

	class Samples
	{
	public:
		double double_output = 1;

		static Samples instance;
	};

	Samples Samples::instance;

	void layer_0()
	{
		Samples::instance.double_output +=
			Samples::instance.double_output * 1.0 * 2.0;
		Samples::instance.double_output +=
			Samples::instance.double_output * 1.0 * 2.0;
	}

	namespace Layer1
	{
		void layer_1()
		{
			Samples::instance.double_output +=
				Samples::instance.double_output * 1.0 * 2.0;
			Samples::instance.double_output +=
				Samples::instance.double_output * 1.0 * 2.0;
		}

		namespace Layer2
		{
			void layer_2()
			{
				Samples::instance.double_output +=
					Samples::instance.double_output * 1.0 * 2.0;
				Samples::instance.double_output +=
					Samples::instance.double_output * 1.0 * 2.0;
			}

			namespace Layer3
			{
				void layer_3()
				{
					Samples::instance.double_output +=
						Samples::instance.double_output * 1.0 * 2.0;
					Samples::instance.double_output +=
						Samples::instance.double_output * 1.0 * 2.0;
				}

				namespace Layer4
				{
					void layer_4()
					{
						Samples::instance.double_output +=
							Samples::instance.double_output * 1.0 * 2.0;
						Samples::instance.double_output +=
							Samples::instance.double_output * 1.0 * 2.0;
					}

					namespace Layer5
					{
						void layer_5()
						{
							Samples::instance.double_output +=
								Samples::instance.double_output * 1.0 * 2.0;
							Samples::instance.double_output +=
								Samples::instance.double_output * 1.0 * 2.0;
						}
					}
				}
			}
		}
	}

	void execute()
	{
		NanobenchBenchmarkingTestSuite test_suite
		{
			.name = "Namespace Layers",
			.epoch_iteration_pairs =
			{
				{
					.epochs = 100000000,
					.iterations = 1
				},
				{
					.epochs = 100000,
					.iterations = 1000
				},
				{
					.epochs = 10,
					.iterations = 1000000
				}
			},
			.test_cases =
			{
				{
					.name = "layer_0",
					.callback = []() { layer_0(); }
				},
				{
					.name = "Layer1::layer_1",
					.callback = []() { Layer1::layer_1(); }
				},
				{
					.name = "Layer1::Layer2::layer_2",
					.callback = []() { Layer1::Layer2::layer_2(); }
				},
				{
					.name = "Layer1::Layer2::Layer3::layer_3",
					.callback = []() { Layer1::Layer2::Layer3::layer_3(); }
				},
				{
					.name = "Layer1::Layer2::Layer3::Layer4::layer_4",
					.callback = []() { Layer1::Layer2::Layer3::Layer4::layer_4(); }
				},
				{
					.name = "Layer1::Layer2::Layer3::Layer4::Layer5::layer_5",
					.callback = []() { Layer1::Layer2::Layer3::Layer4::Layer5::layer_5(); }
				},
			}
		};

		execute_nanobenchmark(
			test_suite
		);

		bool exit_code;
		std::cin >> exit_code;
	}
}


namespace ExecutionWithinNestedTryCatchBlocks
{
	/*

	Conclusion:
	- No significant performance difference

	Usage
	- Indiscriminate

	| relative |               ns/op |                op/s |    err% |     total | benchmark
	|---------:|--------------------:|--------------------:|--------:|----------:|:----------
	|   100.0% |                1.94 |      515,508,984.62 |    0.5% |      0.24 | `try_catch | nested_try_catch_block | 1`
	|   101.4% |                1.91 |      522,555,446.13 |    0.1% |      0.23 | `try_catch | no_try_catch_block | 1`
	|   101.4% |                1.91 |      522,783,208.40 |    0.1% |      0.23 | `try_catch | with_try_catch_block | 1`

	|   100.0% |               17.48 |       57,222,083.35 |    0.3% |      0.21 | `try_catch | nested_try_catch_block | 10`
	|   100.0% |               17.47 |       57,226,584.62 |    0.3% |      0.21 | `try_catch | no_try_catch_block | 10`
	|   100.0% |               17.47 |       57,249,342.20 |    0.2% |      0.21 | `try_catch | with_try_catch_block | 10`

	|   100.0% |              173.80 |        5,753,826.47 |    0.2% |      0.21 | `try_catch | nested_try_catch_block | 100`
	|   100.0% |              173.74 |        5,755,611.27 |    0.1% |      0.21 | `try_catch | no_try_catch_block | 100`
	|   100.1% |              173.64 |        5,758,971.64 |    0.2% |      0.21 | `try_catch | with_try_catch_block | 100`

	|   100.0% |            1,679.36 |          595,463.74 |    0.1% |      0.20 | `try_catch | nested_try_catch_block | 1000`
	|   100.0% |            1,679.66 |          595,360.21 |    0.1% |      0.20 | `try_catch | no_try_catch_block | 1000`
	|    99.7% |            1,684.17 |          593,765.94 |    0.2% |      0.20 | `try_catch | with_try_catch_block | 1000`

	|   100.0% |           16,756.65 |           59,677.80 |    0.1% |      0.20 | `try_catch | nested_try_catch_block | 10000`
	|    99.9% |           16,769.24 |           59,632.98 |    0.2% |      0.20 | `try_catch | no_try_catch_block | 10000`
	|   100.0% |           16,750.04 |           59,701.34 |    0.1% |      0.20 | `try_catch | with_try_catch_block | 10000`

	|   100.0% |          167,407.62 |            5,973.44 |    0.1% |      0.20 | `try_catch | nested_try_catch_block | 100000`
	|   100.0% |          167,420.87 |            5,972.97 |    0.1% |      0.21 | `try_catch | no_try_catch_block | 100000`
	|    99.8% |          167,708.70 |            5,962.72 |    0.3% |      0.20 | `try_catch | with_try_catch_block | 100000`

	|   100.0% |        1,677,641.67 |              596.07 |    0.3% |      0.20 | `try_catch | nested_try_catch_block | 1000000`
	|   100.3% |        1,672,800.00 |              597.80 |    0.0% |      0.20 | `try_catch | no_try_catch_block | 1000000`
	|   100.2% |        1,674,318.18 |              597.26 |    0.2% |      0.20 | `try_catch | with_try_catch_block | 1000000`

	|   100.0% |       16,740,700.00 |               59.73 |    0.1% |      0.19 | `try_catch | nested_try_catch_block | 10000000`
	|   100.0% |       16,738,600.00 |               59.74 |    0.1% |      0.18 | `try_catch | no_try_catch_block | 10000000`
	|    99.7% |       16,787,400.00 |               59.57 |    0.3% |      0.19 | `try_catch | with_try_catch_block | 10000000`

	*/

	class Samples
	{
	public:
		double double_input_1 = 1;

		double double_output_1 = 1;

		static Samples instance;
	};

	Samples Samples::instance;

	void nested_try_catch_block()
	{
		try
		{
			try
			{
				try
				{
					try
					{
						try
						{
							try
							{
								try
								{
									try
									{
										try
										{
											try
											{
												Samples::instance.double_output_1 =
													Samples::instance.double_input_1 + Samples::instance.double_input_1;
											}
											catch (...)
											{

											}
										}
										catch (...)
										{

										}
									}
									catch (...)
									{

									}
								}
								catch (...)
								{

								}
							}
							catch (...)
							{

							}
						}
						catch (...)
						{

						}
					}
					catch (...)
					{

					}
				}
				catch (...)
				{

				}
			}
			catch (...)
			{

			}
		}
		catch (std::exception& exception)
		{
			Samples::instance.double_output_1 = 0.0;
		}
		catch (...)
		{

		}
	}

	void with_try_catch_block()
	{
		try
		{
			Samples::instance.double_output_1 =
				Samples::instance.double_input_1 + Samples::instance.double_input_1;
		}
		catch (std::exception& exception)
		{
			Samples::instance.double_output_1 = 0.0;
		}
		catch (...)
		{

		}
	}

	void no_try_catch_block()
	{
		Samples::instance.double_output_1 =
			Samples::instance.double_input_1 + Samples::instance.double_input_1;
	}

	void before_test_case_iteration_callback()
	{
		Samples::instance.double_output_1 = 0.0;
	}

	void execute()
	{
		NanobenchBenchmarkingTestSuite test_suite
		{
			.name = "try_catch",
			.warmup_count = 2,
			.epoch_iteration_pairs =
			{
				{
					.epochs = 10'000'000,
					.iterations = 1
				},
				{
					.epochs = 1'000'000,
					.iterations = 10
				},
				{
					.epochs = 100'000,
					.iterations = 100
				},
				{
					.epochs = 10'000,
					.iterations = 1'000
				},
				{
					.epochs = 1'000,
					.iterations = 10'000
				},
				{
					.epochs = 100,
					.iterations = 100'000
				},
				{
					.epochs = 10,
					.iterations = 1'000'000
				},
				{
					.epochs = 1,
					.iterations = 10'000'000
				}
			},

			.test_cases =
			{
				{
					.name = "nested_try_catch_block",
					.callback = nested_try_catch_block
				},
				{
					.name = "no_try_catch_block",
					.callback = no_try_catch_block
				},
				{
					.name = "with_try_catch_block",
					.callback = with_try_catch_block
				}
			},

			.before_test_case_iteration_callback =
				before_test_case_iteration_callback
		};

		execute_nanobenchmark(
			test_suite
		);

		bool exit_code;
		std::cin >> exit_code;
	}
}





namespace LoopExecution
{
	/*

	Conclusion
	- use 'while' or 'for each' loops


	| relative |               ns/op |                op/s |    err% |     total | benchmark
	|---------:|--------------------:|--------------------:|--------:|----------:|:----------
	|   100.0% |               55.34 |       18,069,653.81 |    0.2% |      6.70 | `loops | for_loop | 1`
	|   100.4% |               55.12 |       18,142,605.87 |    0.1% |      6.69 | `loops | while_loop | 1`
	|   100.4% |               55.12 |       18,142,872.07 |    0.1% |      6.69 | `loops | do_while_loop | 1`
	|   154.4% |               35.85 |       27,893,959.62 |    2.0% |      4.34 | `loops | ranged_based_for_loop | 1`
	|   153.4% |               36.08 |       27,716,970.40 |    0.8% |      4.39 | `loops | for_each__begin_and_end_collection_pointers | 1`
	|   143.4% |               38.58 |       25,917,977.10 |    0.1% |      4.67 | `loops | for_each__collection_reference | 1`

	|   100.0% |           54,588.35 |           18,318.93 |    0.0% |      6.61 | `loops | for_loop | 1000`
	|   100.0% |           54,596.26 |           18,316.27 |    0.0% |      6.61 | `loops | while_loop | 1000`
	|    99.7% |           54,769.54 |           18,258.32 |    0.1% |      6.63 | `loops | do_while_loop | 1000`
	|   155.4% |           35,132.08 |           28,464.01 |    0.1% |      4.26 | `loops | ranged_based_for_loop | 1000`
	|   155.1% |           35,190.82 |           28,416.50 |    0.2% |      4.27 | `loops | for_each__begin_and_end_collection_pointers | 1000`
	|   144.3% |           37,829.52 |           26,434.38 |    0.2% |      4.59 | `loops | for_each__collection_reference | 1000`

	|   100.0% |       54,620,825.00 |               18.31 |    0.1% |      6.67 | `loops | for_loop | 1000000`
	|   100.1% |       54,570,075.00 |               18.33 |    0.0% |      6.66 | `loops | while_loop | 1000000`
	|    99.7% |       54,783,280.00 |               18.25 |    0.1% |      6.72 | `loops | do_while_loop | 1000000`
	|   155.8% |       35,051,360.00 |               28.53 |    0.5% |      4.32 | `loops | ranged_based_for_loop | 1000000`
	|   154.5% |       35,358,536.36 |               28.28 |    0.4% |      4.33 | `loops | for_each__begin_and_end_collection_pointers | 1000000`
	|   144.3% |       37,864,816.67 |               26.41 |    0.2% |      4.63 | `loops | for_each__collection_reference | 1000000`
	*/

	class Samples
	{
	public:
		size_t index = 0;

		size_t size = 0;

		char output_value;

		std::string data = std::string(0, '0');

		static Samples instance;

		void for_loop()
		{
			for (index = 0; index < size; ++index)
			{
				output_value = data[index];
			}
		}

		void while_loop()
		{
			index = 0;
			while (index < size)
			{
				output_value = data[index];
				++index;
			}
		}

		void do_while_loop()
		{
			index = 0;
			do
			{
				output_value = data[index];
				++index;

			} while (index < size);
		}

		void ranged_based_for_loop()
		{
			for (const char& datum : data)
			{
				output_value = datum;
			}
		}

		void for_each__begin_and_end_collection_pointers()
		{
			std::ranges::for_each(
				data.begin(),
				data.end(),
				[this](const char datum)
				{
					output_value = datum;
				}
			);
		}

		void for_each__collection_reference()
		{
			std::ranges::for_each(
				data,
				[this](const char datum)
				{
					output_value = datum;
				}
			);
		}
	};

	Samples Samples::instance;

	void execute()
	{
		NanobenchBenchmarkingTestSuite test_suite
		{
			.name = "loops",
			.warmup_count = 1,
			.epoch_iteration_pairs =
			{
				{
					.epochs = 10000000,
					.iterations = 1
				},
				{
					.epochs = 10000,
					.iterations = 1000
				},
				{
					.epochs = 10,
					.iterations = 1000000
				}
			},

			.test_cases =
			{
				{
					.name = "for_loop",
					.callback = []() { Samples::instance.for_loop(); }
				},
				{
					.name = "while_loop",
					.callback = []() { Samples::instance.while_loop(); }
				},
				{
					.name = "do_while_loop",
					.callback = []() { Samples::instance.do_while_loop(); }
				},
				{
					.name = "ranged_based_for_loop",
					.callback = []() { Samples::instance.ranged_based_for_loop(); }
				},
				{
					.name = "for_each__begin_and_end_collection_pointers",
					.callback = []() { Samples::instance.for_each__begin_and_end_collection_pointers(); }
				},
				{
					.name = "for_each__collection_reference",
					.callback = []() { Samples::instance.for_each__collection_reference(); }
				}
			}
		};

		execute_nanobenchmark(
			test_suite
		);

		bool exit_code;
		std::cin >> exit_code;
	}
}

/*
{
                    .name = "libuv_file_write",
                    .callback = libuv_file_write
                },
                {
                    .name = "libuv_file_append",
                    .callback = libuv_file_append
                },
                {
                    .name = "libuv_file_read",
                    .callback = libuv_file_read,
                    .before_test_callback = []()
                    {
                        std::ofstream ofstream_write_file_temp_1(file_path_1, std::ios::out);
                        ofstream_write_file_temp_1 << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
                    }
                },
            std::ofstream json_file(
                benchmark_name + ".json"
            );
            ankerl::nanobench::render(
                ankerl::nanobench::templates::json(),
                benchmarker,
                json_file
            );

            std::ofstream csv_file(
                benchmark_name + ".csv"
            );
            ankerl::nanobench::render(
                ankerl::nanobench::templates::csv(),
                benchmarker,
                csv_file
            );


namespace Experiment7 // no arguments
{
    std::string sum_raw_instance_1_output = "0";

    std::string sum_raw_instance_1_input_1 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    std::string sum_raw_instance_1_input_2 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    void sum_raw_instance_1()
    {
        sum_raw_instance_1_output =
            sum_raw_instance_1_input_1 +
            sum_raw_instance_1_input_2;
    }

    std::string sum_raw_instance_2_output = "0";

    void sum_raw_instance_2_func(
        std::string input_1,
        std::string input_2
    )
    {
        sum_raw_instance_2_output =
            input_1 + input_2;
    }

    void sum_raw_instance_2()
    {
        sum_raw_instance_2_func(
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        );
    }

    std::string sum_raw_instance_3_func()
    {
        sum_raw_instance_1_output =
            sum_raw_instance_1_input_1 +
            sum_raw_instance_1_input_2;

        return sum_raw_instance_1_output;
    }

    void sum_raw_instance_3()
    {
        sum_raw_instance_3_func();
    }

    inline static std::string sum_raw_static_1_output = "0";

    inline static std::string sum_raw_static_1_input_1 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    inline static std::string sum_raw_static_1_input_2 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    void sum_raw_static_1()
    {
        sum_raw_static_1_output =
            sum_raw_static_1_input_1 +
            sum_raw_static_1_input_2;
    }

    inline static std::string sum_raw_static_2_output = "0";

    void sum_raw_static_2_func(
        std::string input_1,
        std::string input_2
    )
    {
        sum_raw_static_2_output =
            input_1 + input_2;
    }

    void sum_raw_static_2()
    {
        sum_raw_static_2_func(
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        );
    }

    std::string sum_raw_static_3_func()
    {
        sum_raw_static_1_output =
            sum_raw_static_1_input_1 +
            sum_raw_static_1_input_2;

        return sum_raw_static_1_output;
    }

    void sum_raw_static_3()
    {
        sum_raw_static_3_func();
    }

    class Instance
    {
    public:
        std::string sum_object_instance_1_output = "0";

        std::string sum_object_instance_1_input_1 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

        std::string sum_object_instance_1_input_2 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

        void sum_object_instance_1()
        {
            sum_object_instance_1_output =
                sum_object_instance_1_input_1 +
                sum_object_instance_1_input_2;
        }

        std::string sum_object_instance_2_output = "0";

        void sum_object_instance_2(
            std::string input_1,
            std::string input_2
        )
        {
            sum_object_instance_2_output =
                input_1 + input_2;
        }

        std::string sum_object_instance_3_func()
        {
            sum_object_instance_1_output =
                sum_object_instance_1_input_1 +
                sum_object_instance_1_input_2;

            return sum_object_instance_1_output;
        }

        void sum_object_instance_3()
        {
            sum_object_instance_3_func();
        }

        inline static std::string sum_object_static_1_output = "0";

        inline static std::string sum_object_static_1_input_1 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

        inline static std::string sum_object_static_1_input_2 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

        inline static void sum_object_static_1()
        {
            sum_object_static_1_output =
                sum_object_static_1_input_1 +
                sum_object_static_1_input_2;
        }

        inline static std::string sum_object_static_2_output = "0";

        inline static void sum_object_static_2(
            std::string input_1,
            std::string input_2
        )
        {
            sum_object_static_2_output =
                input_1 + input_2;
        }

        inline static std::string sum_object_static_3_func()
        {
            sum_object_static_1_output =
                sum_object_static_1_input_1 +
                sum_object_static_1_input_2;

            return sum_object_static_1_output;
        }

        inline static void sum_object_static_3()
        {
            sum_object_static_3_func();
        }
    };

    Instance object;

    void sum_object_instance_1()
    {
        object.sum_object_instance_1();
    }

    void sum_object_instance_2()
    {
        object.sum_object_instance_2(
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        );
    }

    void sum_object_instance_3()
    {
        object.sum_object_instance_3();
    }

    void sum_object_static_1()
    {
        Instance::sum_object_static_1();
    }

    void sum_object_static_2()
    {
        Instance::sum_object_static_2(
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
        );
    }

    void sum_object_static_3()
    {
        Instance::sum_object_static_3();
    }

    void execute()
    {
        NanobenchBenchmarkingTestSuite test_suite
        {
            .name = "object_instance_or_object_static",
            .epoch_iteration_pairs =
            {
                {
                    .epochs = 1'000'000,
                    .iterations = 1
                },
                {
                    .epochs = 100'000,
                    .iterations = 10
                },
                {
                    .epochs = 10'000,
                    .iterations = 100
                },
                {
                    .epochs = 1'000,
                    .iterations = 1'000
                },
                {
                    .epochs = 1,
                    .iterations = 1'000'000
                }
            },

            .test_cases =
            {
                {
                    .name = "sum_raw_instance_1",
                    .callback = sum_raw_instance_1
                },
                {
                    .name = "sum_raw_instance_2",
                    .callback = sum_raw_instance_2
                },
                {
                    .name = "sum_raw_instance_3",
                    .callback = sum_raw_instance_3
                },
                {
                    .name = "sum_raw_static_1",
                    .callback = sum_raw_static_1
                },
                {
                    .name = "sum_raw_static_2",
                    .callback = sum_raw_static_2
                },
                {
                    .name = "sum_raw_static_3",
                    .callback = sum_raw_static_3
                },
                {
                    .name = "sum_object_instance_1",
                    .callback = sum_object_instance_1
                },
                {
                    .name = "sum_object_instance_2",
                    .callback = sum_object_instance_2
                },
                {
                    .name = "sum_object_instance_3",
                    .callback = sum_object_instance_3
                },
                {
                    .name = "sum_object_static_1",
                    .callback = sum_object_static_1
                },
                {
                    .name = "sum_object_static_2",
                    .callback = sum_object_static_2
                },
                {
                    .name = "sum_object_static_3",
                    .callback = sum_object_static_3
                }
            }
        };

        execute_nanobenchmark(
            test_suite
        );

        bool exit_code;
        std::cin >> exit_code;
    }
}










namespace Experiment10 // pure
{
    static std::string benchmark_value = "0";

    namespace Cache
    {
        static std::string pure_static_string_input_value = benchmark_value;

        static std::string pure_static_string_output_value = "";

        struct StructStringSample
        {
            inline static std::string struct_static_string_input_value = benchmark_value;

            inline static std::string struct_static_string_output_value = "";
        };

        class ClassStringSample
        {
        public:
            inline static std::string class_static_string_input_value = benchmark_value;

            inline static std::string class_static_string_output_value = "";
        };
    };

    extern std::string extern_static_string_input_value;

    extern std::string extern_static_string_output_value;

    static std::string pure_static_string_input_value = benchmark_value;

    static std::string pure_static_string_output_value = "";

    struct StructStringSample
    {
        inline static std::string struct_static_string_input_value = benchmark_value;

        inline static std::string struct_static_string_output_value = "";
    };

    class ClassStringSample
    {
    public:
        inline static std::string class_static_string_input_value = benchmark_value;

        inline static std::string class_static_string_output_value = "";
    };

    void extern_static_string()
    {
        extern_static_string_output_value =
            extern_static_string_input_value +
            extern_static_string_input_value;
    }

    void pure_namespace_static_string()
    {
        Cache::pure_static_string_output_value =
            Cache::pure_static_string_input_value +
            Cache::pure_static_string_input_value;
    }

    void pure_static_string()
    {
        pure_static_string_output_value =
            pure_static_string_input_value +
            pure_static_string_input_value;
    }

    void struct_static_string()
    {
        StructStringSample::struct_static_string_output_value =
            StructStringSample::struct_static_string_input_value +
            StructStringSample::struct_static_string_input_value;
    }

    void class_static_string()
    {
        ClassStringSample::class_static_string_output_value =
            ClassStringSample::class_static_string_input_value +
            ClassStringSample::class_static_string_input_value;
    }

    static std::string pure_static_double_input_value = benchmark_value;

    static std::string pure_double_output_value = "";

    struct StructDoubleSample
    {
        inline static std::string struct_static_double_input_value = benchmark_value;

        inline static std::string struct_double_output_value = "";
    };

    class ClassDoubleSample
    {
    public:
        inline static std::string class_static_double_input_value = benchmark_value;

        inline static std::string class_double_output_value = "";
    };

    void pure_static_double()
    {
        pure_double_output_value =
            pure_static_double_input_value +
            pure_static_double_input_value;
    }

    void struct_static_double()
    {
        StructDoubleSample::struct_double_output_value =
            StructDoubleSample::struct_static_double_input_value +
            StructDoubleSample::struct_static_double_input_value;
    }

    void class_static_double()
    {
        ClassDoubleSample::class_double_output_value =
            ClassDoubleSample::class_static_double_input_value +
            ClassDoubleSample::class_static_double_input_value;
    }


    void execute()
    {
        QLogicaeCppCore::RuntimeBenchmarkerTestSuite test_suite_1
        {
            .name = "pure_static_vs_struct_static_vs_class_static",
            .warmup_count = 2,
            .epoch_iteration_pairs =
            {
                {
                    .epochs = 10'000'000,
                    .iterations = 1
                },
                {
                    .epochs = 1'000'000,
                    .iterations = 10
                },
                {
                    .epochs = 100'000,
                    .iterations = 100
                },
                {
                    .epochs = 10'000,
                    .iterations = 1'000
                },
                {
                    .epochs = 1,
                    .iterations = 1'000'000
                }
            },

            .test_cases =
            {
                {
                    .name = "extern_static_string",
                    .callback = extern_static_string
                },
                {
                    .name = "struct_static_string",
                    .callback = struct_static_string
                },
                {
                    .name = "class_static_string",
                    .callback = class_static_string
                },
                {
                    .name = "pure_namespace_static_string",
                    .callback = pure_namespace_static_string
                },
                {
                    .name = "pure_static_string",
                    .callback = pure_static_string
                }
            }
        };

        QLogicaeCppCore::RuntimeBenchmarker::singleton
            .execute(
                test_suite_1,
                { .is_enabled = false }
            );
        QLogicaeCppCore::RuntimeBenchmarker::singleton
            .execute(
                test_suite_1,
                { .is_enabled = true }
            );

        bool exit_code;
        std::cin >> exit_code;
    }
}


namespace Experiment9 // folly and boost
{
	class InstanceCollections
	{
	public:
		folly::MicroSpinLock micro_spin_lock;

		std::mutex std_mutex;

		boost::mutex boost_mutex;

		std::unordered_map<std::string, folly::MicroSpinLock>
			folly_micro_spin_lock_collection;

		std::string z;

		std::string string_1(std::string x, std::string y)
		{
			return x + y;
		}

		void string_2(std::string x, std::string y)
		{
			//boost::unique_lock<boost::mutex> lock(boost_mutex);

			z = x + y;
		}
	};

	class StaticCollections
	{
	public:
		inline static folly::MicroSpinLock micro_spin_lock;

		inline static std::mutex std_mutex;

		inline static boost::mutex boost_mutex;

		inline static std::unordered_map<std::string, folly::MicroSpinLock>
			folly_micro_spin_lock_collection;
	};

	inline static InstanceCollections singleton;

	void instance_string_1()
	{
		singleton.string_1("a","b");
	}

	void instance_string_2()
	{
		singleton.string_2("a", "b");
	}

	void instance_lock_with_folly()
	{
		singleton.micro_spin_lock.lock();
		singleton.micro_spin_lock.unlock();
	}

	void instance_lock_with_folly_2()
	{
		try
		{
			singleton.micro_spin_lock.lock();
			singleton.micro_spin_lock.unlock();
		}
		catch (...)
		{
		}
	}

	void instance_lock_with_folly_map()
	{
		singleton.folly_micro_spin_lock_collection["instance"].lock();
		singleton.folly_micro_spin_lock_collection["instance"].unlock();
	}

	void instance_lock_with_std_mutex()
	{
		std::unique_lock<std::mutex> lock(singleton.std_mutex);
	}

	void instance_lock_with_boost_mutex()
	{
		boost::unique_lock<boost::mutex> lock(singleton.boost_mutex);
	}

	void instance_lock_with_empty_boost_lock()
	{
		boost::unique_lock<boost::mutex> lock;
	}

	void instance_lock_with_boost_mutex_disabled()
	{
		if (false)
		{
			boost::unique_lock<boost::mutex> lock;
		}
	}

	void instance_lock_with_boost_mutex_disabled_scoped()
	{
		{
			if (false)
			{
				boost::unique_lock<boost::mutex> lock;
			}
		}
	}

	void static_lock_with_folly()
	{
		StaticCollections::micro_spin_lock.lock();
		StaticCollections::micro_spin_lock.unlock();
	}

	void static_lock_with_folly_2()
	{
		try
		{
			StaticCollections::micro_spin_lock.lock();
			StaticCollections::micro_spin_lock.unlock();
		}
		catch (...)
		{
		}
	}

	void static_lock_with_folly_map()
	{
		StaticCollections::folly_micro_spin_lock_collection["static"].lock();
		StaticCollections::folly_micro_spin_lock_collection["static"].unlock();
	}

	void static_lock_with_std_mutex()
	{
		std::unique_lock<std::mutex> lock(StaticCollections::std_mutex);
	}

	void static_lock_with_boost_mutex()
	{
		boost::unique_lock<boost::mutex> lock(StaticCollections::boost_mutex);
	}

	void static_lock_with_empty_boost_lock()
	{
		boost::unique_lock<boost::mutex> lock;
	}

	void static_lock_with_boost_mutex_disabled()
	{
		if (false)
		{
			boost::unique_lock<boost::mutex> lock;
		}
	}

	void static_lock_with_boost_mutex_disabled_scoped()
	{
		{
			if (false)
			{
				boost::unique_lock<boost::mutex> lock;
			}
		}
	}

	inline static std::shared_ptr<boost::asio::thread_pool> THREAD_POOL =
		std::make_shared<boost::asio::thread_pool>(
			std::thread::hardware_concurrency()
		);

	inline static std::string static_a = "a";

	inline static std::string static_b = "b";

	void sync()
	{
		std::string a = static_a + static_b;
	}

	void async_1()
	{
		boost::asio::post(
			*THREAD_POOL,
			[]() mutable
			{
				std::string aaa = static_a + static_b;
			}
		);
	}

	void async_2()
	{
		std::async(
			std::launch::async,
			[]() mutable
			{
				std::string aaa = static_a + static_b;
			}
		);
	}


	void execute()
	{
		NanobenchBenchmarkingTestSuite test_suite
		{
			.name = "Experiment 9",
			.epoch_iteration_pairs =
			{
				{
					.epochs = 100000,
					.iterations = 1
				},
				{
					.epochs = 10000,
					.iterations = 10
				},
				{
					.epochs = 1000,
					.iterations = 100
				},
				{
					.epochs = 100,
					.iterations = 1000
				},
				{
					.epochs = 1,
					.iterations = 1000000
				}
			},

			.test_cases =
			{
				{
					.name = "sync",
					.callback = sync
				},
				{
					.name = "async_1",
					.callback = async_1
				},
				{
					.name = "async_2",
					.callback = async_2
				}
			}
		};

		execute_nanobenchmark(
			test_suite
		);

		bool exit_code;
		std::cin >> exit_code;
	}
}


namespace Experiment_12 // std::string f(const std::string&, ...)
{

	// Results:
	// - small const arguments -> std::string f(const std::string&, ...)
	// - large const arguments -> std::string f(const std::string&, ...)

	inline static std::shared_ptr<boost::asio::thread_pool> THREAD_POOL =
		std::make_shared<boost::asio::thread_pool>(
			std::thread::hardware_concurrency()
		);

	inline static std::string value = "0";

	inline static std::string static_output_value_1 = "";

	inline static std::string static_input_value_1 = "0";

	inline static std::string static_input_value_2 = "0";

	class InstanceObject
	{
	public:
		InstanceObject() = default;

		std::string instance_output_value_1 = "";


		void function_11(std::string x, std::string y)
		{
			instance_output_value_1 = x + y;
		}

		void function_12(const std::string x, const std::string y)
		{
			instance_output_value_1 = x + y;
		}

		void function_13(const std::string& x, const std::string& y)
		{
			instance_output_value_1 = x + y;
		}



		std::string function_14(std::string x, std::string y)
		{
			return x + y;
		}

		std::string function_15(const std::string x, const std::string y)
		{
			return x + y;
		}

		std::string function_16(const std::string& x, const std::string_view& y)
		{
			return x + y.data();
		}



		std::string function_1(std::string x, std::string y)
		{
			return x + y;
		}

		std::string function_2(const std::string x, const std::string y)
		{
			return x + y;
		}

		std::string function_3(const std::string& x, const std::string& y)
		{
			return x + y;
		}



		void function_4(std::string& z, std::string x, std::string y)
		{
			z = x + y;
		}

		void function_5(std::string& z, const std::string x, const std::string y)
		{
			z = x + y;
		}

		void function_6(std::string& z, const std::string& x, const std::string& y)
		{
			z = x + y;
		}

		void function_11(std::string& z, const std::string& x, const std::string& y)
		{
			z = x + y;
		}



		void function_7(std::string x, std::string y)
		{
			static_output_value_1 = x + y;
		}

		void function_8(const std::string x, const std::string y)
		{
			static_output_value_1 = x + y;
		}

		void function_9(const std::string& x, const std::string& y)
		{
			static_output_value_1 = x + y;
		}



		void function_10()
		{
			static_output_value_1 = static_input_value_1 + static_input_value_2;
		}

		static InstanceObject instance;
	};

	InstanceObject InstanceObject::instance;

	void execute()
	{
		NanobenchBenchmarkingTestSuite test_suite
		{
			.name = "Experiment_12",
			.epoch_iteration_pairs =
			{
				{
					.epochs = 1000000,
					.iterations = 1
				},
				{
					.epochs = 100000,
					.iterations = 10
				},
				{
					.epochs = 10000,
					.iterations = 100
				},
				{
					.epochs = 1000,
					.iterations = 1000
				},
				{
					.epochs = 1,
					.iterations = 1000000
				}
			},

			.test_cases =
			{
				{
					.name = "function_signature__constant_arguments__16",
					.callback = []() { std::string z = InstanceObject::instance.function_16("0", "0"); }
				},
				{
					.name = "function_signature__constant_arguments__3",
					.callback = []() { std::string z = InstanceObject::instance.function_3("0", "0"); }
				},
				{
					.name = "function_signature__constant_arguments__6",
					.callback = []() { InstanceObject::instance.function_6(static_output_value_1, "0", "0"); }
				},
				{
					.name = "function_signature__constant_arguments__9",
					.callback = []() { InstanceObject::instance.function_9("0", "0"); }
				},
				{
					.name = "function_signature__constant_arguments__13",
					.callback = []() { InstanceObject::instance.function_13("0", "0"); }
				},
				{
					.name = "function_signature__reference_arguments__16",
					.callback = []() { std::string z = InstanceObject::instance.function_16(static_input_value_1, static_input_value_2); }
				},
				{
					.name = "function_signature__reference_arguments__3",
					.callback = []() { std::string z = InstanceObject::instance.function_3(static_input_value_1, static_input_value_2); }
				},
				{
					.name = "function_signature__reference_arguments__6",
					.callback = []() { InstanceObject::instance.function_6(static_output_value_1, static_input_value_1, static_input_value_2); }
				},
				{
					.name = "function_signature__reference_arguments__9",
					.callback = []() { InstanceObject::instance.function_9(static_input_value_1, static_input_value_2); }
				},
				{
					.name = "function_signature__reference_arguments__13",
					.callback = []() { InstanceObject::instance.function_13(static_input_value_1, static_input_value_2); }
				},
			}
		};

		execute_nanobenchmark(
			test_suite
		);

		bool exit_code;
		std::cin >> exit_code;
	}

					{
						.name = "function_signature__reference_arguments__1",
						.callback = []() { std::string z = InstanceObject::instance.function_1(static_input_value_1, static_input_value_2); }
					},
					{
						.name = "function_signature__reference_arguments__2",
						.callback = []() { std::string z = InstanceObject::instance.function_2(static_input_value_1, static_input_value_2); }
					},
					{
						.name = "function_signature__reference_arguments__4",
						.callback = []() { InstanceObject::instance.function_4(static_output_value_1, static_input_value_1, static_input_value_2); }
					},
					{
						.name = "function_signature__reference_arguments__5",
						.callback = []() { InstanceObject::instance.function_5(static_output_value_1, static_input_value_1, static_input_value_2); }
					},
					{
						.name = "function_signature__reference_arguments__7",
						.callback = []() { InstanceObject::instance.function_7(static_input_value_1, static_input_value_2); }
					},
					{
						.name = "function_signature__reference_arguments__8",
						.callback = []() { InstanceObject::instance.function_8(static_input_value_1, static_input_value_2); }
					},
					{
						.name = "function_signature__reference_arguments__10",
						.callback = []() { InstanceObject::instance.function_10(); }
					},
					{
						.name = "function_signature__constant_arguments__1",
						.callback = []() { std::string z = InstanceObject::instance.function_1(value, value); }
					},
					{
						.name = "function_signature__constant_arguments__2",
						.callback = []() { std::string z = InstanceObject::instance.function_2(value, value); }
					},
					{
						.name = "function_signature__constant_arguments__4",
						.callback = []() { InstanceObject::instance.function_4(static_output_value_1, value, value); }
					},
					{
						.name = "function_signature__constant_arguments__5",
						.callback = []() { InstanceObject::instance.function_5(static_output_value_1, value, value); }
					},
					{
						.name = "function_signature__constant_arguments__7",
						.callback = []() { InstanceObject::instance.function_7(value, value); }
					},
					{
						.name = "function_signature__constant_arguments__8",
						.callback = []() { InstanceObject::instance.function_8(value, value); }
					},
					{
						.name = "function_signature__constant_arguments__10",
						.callback = []() { InstanceObject::instance.function_10(); }
					},
					{
						.name = "function_signature__constant_arguments__11",
						.callback = []() { InstanceObject::instance.function_11(value, value); }
					},
					{
						.name = "function_signature__constant_arguments__12",
						.callback = []() { InstanceObject::instance.function_12(value, value); }
					},
					{
						.name = "instance_string_1",
						.callback = instance_string_1
					},
					{
						.name = "instance_string_2",
						.callback = instance_string_2
					},
					{
						.name = "instance_lock_with_folly",
						.callback = instance_lock_with_folly
					},
					{
						.name = "static_lock_with_folly",
						.callback = static_lock_with_folly
					},
					{
						.name = "instance_lock_with_folly_2",
						.callback = instance_lock_with_folly_2
					},
					{
						.name = "static_lock_with_folly_2",
						.callback = static_lock_with_folly_2
					},
					{
						.name = "instance_lock_with_folly_map",
						.callback = instance_lock_with_folly_map
					},
					{
						.name = "static_lock_with_folly_map",
						.callback = static_lock_with_folly_map
					},
					{
						.name = "instance_lock_with_std_mutex",
						.callback = instance_lock_with_std_mutex
					},
					{
						.name = "static_lock_with_std_mutex",
						.callback = static_lock_with_std_mutex
					},
					{
						.name = "instance_lock_with_boost_mutex",
						.callback = instance_lock_with_boost_mutex
					},
					{
						.name = "static_lock_with_boost_mutex",
						.callback = static_lock_with_boost_mutex
					},
					{
						.name = "instance_lock_with_empty_boost_lock",
						.callback = instance_lock_with_empty_boost_lock
					},
					{
						.name = "static_lock_with_empty_boost_lock",
						.callback = static_lock_with_empty_boost_lock
					},
					{
						.name = "instance_lock_with_boost_mutex_disabled",
						.callback = instance_lock_with_boost_mutex_disabled
					},
					{
						.name = "static_lock_with_boost_mutex_disabled",
						.callback = static_lock_with_boost_mutex_disabled
					},
					{
						.name = "instance_lock_with_boost_mutex_disabled_scoped",
						.callback = instance_lock_with_boost_mutex_disabled_scoped
					},
					{
						.name = "static_lock_with_boost_mutex_disabled_scoped",
						.callback = static_lock_with_boost_mutex_disabled_scoped
					}

}


*/

