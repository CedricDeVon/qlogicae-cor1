#include "pch.hpp"

#include "main.hpp"

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

	inline static boost::asio::thread_pool THREAD_POOL_INSTANCE { std::thread::hardware_concurrency() };

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

		NanobenchBencchmarkingTestSuite test_suite
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

int main(int argc, char** argv)
{	
	AsynchronousBenchmarks::execute();		

    return 0;
}

namespace QLogicaeCppCoreBenchmark
{

}
