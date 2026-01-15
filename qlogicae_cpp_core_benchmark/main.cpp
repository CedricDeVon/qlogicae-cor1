#include "pch.hpp"

#include "main.hpp"



namespace WithOrWithoutMutexParallelismPerformance
{
	/*

	Conclusion
	- No concrete conclusion
	- For now:
		- option 1
			- benchmark is either sync or async is faster
			- if async
				- benchmark is either full or semi mutex is faster
			- else
				- use sync

	| relative |               ns/op |                op/s |    err% |     total | benchmark
	|---------:|--------------------:|--------------------:|--------:|----------:|:----------
	|   100.0% |       29,121,263.64 |               34.34 |    9.1% |      3.65 | :wavy_dash: `With Or Without Mutex Parallelism Performance | file_write_and_read__co_spawn__no_mutex__sync__n | 1` (Unstable with ~11.1 iters. Increase `minEpochIterations` to e.g. 111)
	|   108.0% |       26,957,827.27 |               37.09 |    1.8% |      3.36 | `With Or Without Mutex Parallelism Performance | file_write_and_read__co_spawn__no_mutex__async__n | 1`
	|   107.4% |       27,102,800.00 |               36.90 |    4.2% |      3.67 | `With Or Without Mutex Parallelism Performance | file_write_and_read__co_spawn__with_semi_mutex__n | 1`
	|   102.8% |       28,332,445.45 |               35.30 |    4.3% |      3.49 | `With Or Without Mutex Parallelism Performance | file_write_and_read__co_spawn__with_full_mutex__n | 1`
	|   114.7% |       25,380,550.00 |               39.40 |    4.2% |      3.42 | `With Or Without Mutex Parallelism Performance | file_write_and_read__post__no_mutex__async__n | 1`
	|   102.5% |       28,410,790.91 |               35.20 |   13.0% |      3.50 | :wavy_dash: `With Or Without Mutex Parallelism Performance | file_write_and_read__post__with_semi_mutex__n | 1` (Unstable with ~11.1 iters. Increase `minEpochIterations` to e.g. 111)
	|    83.4% |       34,929,100.00 |               28.63 |    4.9% |      4.20 | `With Or Without Mutex Parallelism Performance | file_write_and_read__post__with_full_mutex__n | 1`

	|   100.0% |      302,526,600.00 |                3.31 |    2.3% |      3.59 | `With Or Without Mutex Parallelism Performance | file_write_and_read__co_spawn__no_mutex__sync__n | 10`
	|   100.3% |      301,568,000.00 |                3.32 |    1.1% |      3.32 | `With Or Without Mutex Parallelism Performance | file_write_and_read__co_spawn__no_mutex__async__n | 10`
	|   100.9% |      299,789,600.00 |                3.34 |    2.4% |      3.50 | `With Or Without Mutex Parallelism Performance | file_write_and_read__co_spawn__with_semi_mutex__n | 10`
	|    97.8% |      309,206,300.00 |                3.23 |    0.7% |      3.40 | `With Or Without Mutex Parallelism Performance | file_write_and_read__co_spawn__with_full_mutex__n | 10`
	|   104.6% |      289,108,900.00 |                3.46 |    5.1% |      3.20 | :wavy_dash: `With Or Without Mutex Parallelism Performance | file_write_and_read__post__no_mutex__async__n | 10` (Unstable with ~1.0 iters. Increase `minEpochIterations` to e.g. 10)
	|   100.2% |      301,806,100.00 |                3.31 |    2.1% |      3.32 | `With Or Without Mutex Parallelism Performance | file_write_and_read__post__with_semi_mutex__n | 10`
	|    76.3% |      396,437,700.00 |                2.52 |    3.1% |      4.44 | `With Or Without Mutex Parallelism Performance | file_write_and_read__post__with_full_mutex__n | 10`

	About
	- Timestamp Start:      2026-01-15 12:33:46.227126000
	- Timestamp End:        2026-01-15 12:34:39.336563600
	*/

	inline static boost::asio::thread_pool THREAD_POOL_INSTANCE{ std::thread::hardware_concurrency() };

	inline static std::shared_ptr<boost::asio::thread_pool> THREAD_POOL_HEAP;

	inline static boost::asio::io_context IO;

	inline static boost::asio::strand<decltype(IO.get_executor())> STRAND(IO.get_executor());

	inline static auto WORK = boost::asio::make_work_guard(IO);

	inline static std::vector<std::thread> WORKERS;

	inline static boost::asio::inline_executor exec;

	inline static size_t size_2 = 10;

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

	class Samples
	{
	public:
		// size_t size_1 = 128;

		std::string input_1 = std::string(2000000, '0');
		
		std::string output_1 = "";

		std::string output_2 = "";

		std::string output_3 = "";

		std::string output_4 = "";

		std::string output_5 = "";

		std::string output_6 = "";

		std::string output_7 = "";

		boost::mutex mutex;

		static Samples instance;

		std::future<void>
			file_write_and_read__co_spawn__with_semi_mutex(
				const std::string&
					file_output_path
			)
		{
			auto future = boost::asio::co_spawn(
				STRAND,
				[this, file_output_path]() -> boost::asio::awaitable<void>
				{
					fast_io::native_file fast_io_write_file(
						file_output_path,
						fast_io::open_mode::out
					);

					{
						boost::unique_lock lock(mutex);
						
						fast_io::io::print(
							fast_io_write_file,
							input_1
						);
					}

					co_return;
				},
				boost::asio::use_future
			);

			return future;
		}

		std::future<void>
			file_write_and_read__co_spawn__with_full_mutex(
				const std::string&
					file_output_path
			)
		{
			auto future = boost::asio::co_spawn(
				STRAND,
				[this, file_output_path]() -> boost::asio::awaitable<void>
				{
					boost::unique_lock lock(mutex);

					fast_io::native_file fast_io_write_file(
						file_output_path,
						fast_io::open_mode::out
					);

					fast_io::io::print(
						fast_io_write_file,
						input_1
					);

					co_return;
				},
				boost::asio::use_future
			);

			return future;
		}

		std::future<void>
			file_write_and_read__co_spawn__no_mutex__async(
				const std::string&
					file_output_path
			)
		{
			auto future = boost::asio::co_spawn(
				STRAND,
				[this, file_output_path]() -> boost::asio::awaitable<void>
				{
					fast_io::native_file fast_io_write_file(
						file_output_path,
						fast_io::open_mode::out
					);
					
					fast_io::io::print(
						fast_io_write_file,
						input_1
					);

					co_return;
				},
				boost::asio::use_future
			);

			return future;
		}

		void
			file_write_and_read__co_spawn__no_mutex__sync(
				const std::string&
					file_output_path
			)
		{
			fast_io::native_file fast_io_write_file(
				file_output_path,
				fast_io::open_mode::out
			);
			
			fast_io::io::print(
				fast_io_write_file,
				input_1
			);

		};

		std::future<void>
			file_write_and_read__post__with_semi_mutex(
				const std::string&
				file_output_path
			)
		{
			std::promise<void> promise;
			std::future<void> future = promise.get_future();

			boost::asio::post(
				THREAD_POOL_INSTANCE,
				[this, file_output_path, promise = std::move(promise)]() mutable
				{
					fast_io::native_file fast_io_write_file(
						file_output_path,
						fast_io::open_mode::out
					);
					
					{
						boost::unique_lock lock(mutex);

						fast_io::io::print(
							fast_io_write_file,
							input_1
						);
					}

					promise.set_value();
				}
			);

			return future;
		}

		std::future<void>
			file_write_and_read__post__with_full_mutex(
				const std::string&
				file_output_path
			)
		{
			std::promise<void> promise;
			std::future<void> future = promise.get_future();

			boost::asio::post(
				THREAD_POOL_INSTANCE,
				[this, file_output_path, promise = std::move(promise)]() mutable
				{
					boost::unique_lock lock(mutex);

					fast_io::native_file fast_io_write_file(
						file_output_path,
						fast_io::open_mode::out
					);

					fast_io::io::print(
						fast_io_write_file,
						input_1
					);
					
					promise.set_value();
				}
			);

			return future;
		}

		std::future<void>
			file_write_and_read__post__no_mutex__async(
				const std::string&
				file_output_path
			)
		{
			std::promise<void> promise;
			std::future<void> future = promise.get_future();

			boost::asio::post(
				THREAD_POOL_INSTANCE,
				[this, file_output_path, promise = std::move(promise)]() mutable
				{
					fast_io::native_file fast_io_write_file(
						file_output_path,
						fast_io::open_mode::out
					);

					fast_io::io::print(
						fast_io_write_file,
						input_1
					);
					
					promise.set_value();
				}
			);

			return future;
		}
	};

	Samples Samples::instance;

	void execute()
	{
		NanobenchBenchmarkingTestSuite test_suite
		{
			.name = "With Or Without Mutex Parallelism Performance",
			.epoch_iteration_pairs =
			{
				{
					.epochs = 10,
					.iterations = 1
				},
				{
					.epochs = 1,
					.iterations = 10
				},
			},
			.test_cases =
			{
				{
					.name = "file_write_and_read__co_spawn__no_mutex__sync__n",
					.callback = []()
					{
						for (int i = 0; i < size_2; ++i)
						{
							Samples::instance.file_write_and_read__co_spawn__no_mutex__sync(
								std::string("temp/1_output_") + std::to_string(i) + ".txt"
							);
						}
					}
				},
				{
					.name = "file_write_and_read__co_spawn__no_mutex__async__n",
					.callback = []()
					{
						std::vector<std::future<void>> futures;
						for (int i = 0; i < size_2; ++i)
						{
							futures.push_back(Samples::instance.file_write_and_read__co_spawn__no_mutex__async(
								std::string("temp/2_output_") + std::to_string(i) + ".txt"
							));
						}

						for (auto& future : futures)
						{
							future.get();
						}
					}
				},
				{
					.name = "file_write_and_read__co_spawn__with_semi_mutex__n",
					.callback = []()
					{
						std::vector<std::future<void>> futures;
						for (int i = 0; i < size_2; ++i)
						{
							futures.push_back(Samples::instance.file_write_and_read__co_spawn__with_semi_mutex(
								std::string("temp/3_output_") + std::to_string(i) + ".txt"
							));
						}

						for (auto& future : futures)
						{
							future.get();
						}
					}
				},
				{
					.name = "file_write_and_read__co_spawn__with_full_mutex__n",
					.callback = []()
					{
						std::vector<std::future<void>> futures;
						for (int i = 0; i < size_2; ++i)
						{
							futures.push_back(Samples::instance.file_write_and_read__co_spawn__with_full_mutex(
								std::string("temp/4_output_") + std::to_string(i) + ".txt"
							));
						}

						for (auto& future : futures)
						{
							future.get();
						}
					}
				},
				{
					.name = "file_write_and_read__post__no_mutex__async__n",
					.callback = []()
					{
						std::vector<std::future<void>> futures;
						for (int i = 0; i < size_2; ++i)
						{
							futures.push_back(Samples::instance.file_write_and_read__post__no_mutex__async(
								std::string("temp/5_output_") + std::to_string(i) + ".txt"
							));
						}

						for (auto& future : futures)
						{
							future.get();
						}
					}
				},
				{
					.name = "file_write_and_read__post__with_semi_mutex__n",
					.callback = []()
					{
						std::vector<std::future<void>> futures;
						for (int i = 0; i < size_2; ++i)
						{
							futures.push_back(Samples::instance.file_write_and_read__post__with_semi_mutex(
								std::string("temp/6_output_") + std::to_string(i) + ".txt"
							));
						}

						for (auto& future : futures)
						{
							future.get();
						}
					}
				},
				{
					.name = "file_write_and_read__post__with_full_mutex__n",
					.callback = []()
					{
						std::vector<std::future<void>> futures;
						for (int i = 0; i < size_2; ++i)
						{
							futures.push_back(Samples::instance.file_write_and_read__post__with_full_mutex(
								std::string("temp/7_output_") + std::to_string(i) + ".txt"
							));
						}

						for (auto& future : futures)
						{
							future.get();
						}
					}
				}
			}
		};

		start_io_workers();
		execute_nanobenchmark(
			test_suite
		);
		stop_io_workers();

		bool exit_code;
		std::cin >> exit_code;
	}
}


int main(int argc, char** argv)
{	
	WithOrWithoutMutexParallelismPerformance::execute();

    return 0;
}

namespace QLogicaeCppCoreBenchmark
{

}
