#include "pch.hpp"

#include "main.hpp"



namespace MutexOrNoneConcurrencyPerformance
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
	|   100.0% |       23,776,918.18 |               42.06 |    3.5% |      3.01 | `Namespace Layers | string_concatenation__no_mutex__sync__n | 1`
	|    96.5% |       24,639,350.00 |               40.59 |    3.8% |      3.22 | `Namespace Layers | string_concatenation__no_mutex__async__n | 1`
	|    96.9% |       24,536,620.00 |               40.76 |    5.2% |      3.06 | :wavy_dash: `Namespace Layers | string_concatenation__with_semi_mutex__n | 1` (Unstable with ~11.1 iters. Increase `minEpochIterations` to e.g. 111)
	|    99.6% |       23,881,309.09 |               41.87 |    3.1% |      3.10 | `Namespace Layers | string_concatenation__with_full_mutex__n | 1`

	|   100.0% |      239,994,500.00 |                4.17 |    3.4% |      2.70 | `Namespace Layers | string_concatenation__no_mutex__sync__n | 10`
	|    84.3% |      284,594,400.00 |                3.51 |    4.6% |      3.08 | `Namespace Layers | string_concatenation__no_mutex__async__n | 10`
	|    83.9% |      285,939,300.00 |                3.50 |    2.7% |      3.20 | `Namespace Layers | string_concatenation__with_semi_mutex__n | 10`
	|    83.2% |      288,292,800.00 |                3.47 |    3.2% |      3.46 | `Namespace Layers | string_concatenation__with_full_mutex__n | 10`

	About
	- Timestamp Start:      2026-01-15 10:42:41.697899100
	- Timestamp End:        2026-01-15 10:43:08.156973200

	*/

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

		std::string input_1 = std::string(1000000, '0');
		
		std::string output_1 = "";

		std::string output_2 = "";

		std::string output_3 = "";

		std::string output_4 = "";

		boost::mutex mutex;

		static Samples instance;

		std::future<void>
			string_concatenation__with_semi_mutex(
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

					fast_io::native_file_loader fast_io_read_file(
						file_output_path
					);

					{
						boost::unique_lock lock(mutex);
						
						fast_io::io::print(
							fast_io_write_file,
							input_1
						);
					}

					{
						boost::unique_lock lock(mutex);
						
						output_1 =
						{
							fast_io_read_file.begin(),
							fast_io_read_file.end()
						};
					}
						
					co_return;
				},
				boost::asio::use_future
			);

			return future;
		}

		std::future<void>
			string_concatenation__with_full_mutex(
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
					fast_io::native_file_loader fast_io_read_file(
						file_output_path
					);

					fast_io::io::print(
						fast_io_write_file,
						input_1
					);

					output_2 =
					{
						fast_io_read_file.begin(),
						fast_io_read_file.end()
					};

					co_return;
				},
				boost::asio::use_future
			);

			return future;
		}

		std::future<void>
			string_concatenation__no_mutex__async(
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
					fast_io::native_file_loader fast_io_read_file(
						file_output_path
					);

					fast_io::io::print(
						fast_io_write_file,
						input_1
					);

					output_3 =
					{
						fast_io_read_file.begin(),
						fast_io_read_file.end()
					};

					co_return;
				},
				boost::asio::use_future
			);

			return future;
		}

		void
			string_concatenation__no_mutex__sync(
				const std::string&
					file_output_path
			)
		{
			fast_io::native_file fast_io_write_file(
				file_output_path,
				fast_io::open_mode::out
			);
			fast_io::native_file_loader fast_io_read_file(
				file_output_path
			);

			fast_io::io::print(
				fast_io_write_file,
				input_1
			);

			output_4 =
			{
				fast_io_read_file.begin(),
				fast_io_read_file.end()
			};
		};
	};

	Samples Samples::instance;

	void execute()
	{
		NanobenchBenchmarkingTestSuite test_suite
		{
			.name = "Namespace Layers",
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
				/*
				{
					.name = "string_concatenation__no_mutex__sync__1",
					.callback = []()
					{
						Samples::instance.string_concatenation__no_mutex__sync();
					}
				},
				{
					.name = "string_concatenation__with_semi_mutex__1",
					.callback = []()
					{
						std::future<void> future_value = Samples::instance.string_concatenation__with_semi_mutex();
						future_value.get();
					}
				},
				{
					.name = "string_concatenation__with_full_mutex__1",
					.callback = []()
					{
						std::future<void> future_value = Samples::instance.string_concatenation__with_full_mutex();
						future_value.get();
					}
				},
				{
					.name = "string_concatenation__no_mutex__async__1",
					.callback = []()
					{
						std::future<void> future_value = Samples::instance.string_concatenation__no_mutex__async();
						future_value.get();
					}
				},
				,
				{
					.name = "string_concatenation__no_mutex__async__n",
					.callback = []()
					{
						std::vector<std::future<void>> futures;
						for (size_t i = 0; i < size_2; ++i)
						{
							futures.push_back(Samples::instance.string_concatenation__no_mutex__async());
						}

						for (auto& future : futures)
						{
							future.get();
						}
					}
				},
				*/ 
				{
					.name = "string_concatenation__no_mutex__sync__n",
					.callback = []()
					{
						for (int i = 0; i < size_2; ++i)
						{
							Samples::instance.string_concatenation__no_mutex__sync(
								std::string("temp/1_output_") + std::to_string(i) + ".txt"
							);
						}
					}
				},
				{
					.name = "string_concatenation__no_mutex__async__n",
					.callback = []()
					{
						std::vector<std::future<void>> futures;
						for (int i = 0; i < size_2; ++i)
						{
							futures.push_back(Samples::instance.string_concatenation__no_mutex__async(
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
					.name = "string_concatenation__with_semi_mutex__n",
					.callback = []()
					{
						std::vector<std::future<void>> futures;
						for (int i = 0; i < size_2; ++i)
						{
							futures.push_back(Samples::instance.string_concatenation__with_semi_mutex(
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
					.name = "string_concatenation__with_full_mutex__n",
					.callback = []()
					{
						std::vector<std::future<void>> futures;
						for (int i = 0; i < size_2; ++i)
						{
							futures.push_back(Samples::instance.string_concatenation__with_full_mutex(
								std::string("temp/4_output_") + std::to_string(i) + ".txt"
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
	MutexOrNoneConcurrencyPerformance::execute();

    return 0;
}

namespace QLogicaeCppCoreBenchmark
{

}
