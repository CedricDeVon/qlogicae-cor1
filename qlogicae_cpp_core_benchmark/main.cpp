#include "pch.hpp"

// #include "main.hpp"

#include "qlogicae_cpp_core/includes/singleton_manager.hpp"
#include "qlogicae_cpp_core/includes/runtime_benchmarker.hpp"


namespace BoostMutexLockAndDefensiveProgrammingRuntimePerformance
{
	/*

	Conclusion:
	- do wrap methods within a callback function, if performance is not a major concern

	| relative |               ns/op |                op/s |    err% |     total | benchmark
	|---------:|--------------------:|--------------------:|--------:|----------:|:----------
	|   100.0% |                1.23 |      816,135,754.36 |    1.5% |      1.49 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__empty_method__1`
	|   101.3% |                1.21 |      826,553,059.19 |    0.7% |      1.47 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__all_conditions_false__1`
	|    72.7% |                1.69 |      593,302,437.43 |    0.4% |      2.04 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_false_and_all_conditions_false_pre_edge_case_checking__1`
	|    51.1% |                2.40 |      416,976,601.25 |    0.1% |      2.91 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_false_and_all_conditions_false_post_edge_case_checking__1`
	|    10.8% |               11.36 |       88,004,974.63 |    0.1% |     13.77 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_true_and_all_conditions_false__1`
	|    51.0% |                2.40 |      416,537,089.47 |    0.2% |      2.91 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_false_and_all_conditions_false__1`
	|    10.8% |               11.36 |       88,061,945.94 |    0.1% |     13.74 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_true_and_no_conditions__1`
	|    56.7% |                2.16 |      462,535,168.64 |    0.2% |      2.62 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_false_and_no_conditions__1`

	|   100.0% |              969.12 |        1,031,858.72 |    0.3% |      1.06 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__empty_method__1000`
	|   100.1% |              968.26 |        1,032,780.57 |    0.1% |      1.06 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__all_conditions_false__1000`
	|    66.9% |            1,448.87 |          690,190.78 |    0.1% |      1.75 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_false_and_all_conditions_false_pre_edge_case_checking__1000`
	|    44.6% |            2,171.10 |          460,595.98 |    0.2% |      2.63 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_false_and_all_conditions_false_post_edge_case_checking__1000`
	|     8.6% |           11,314.51 |           88,382.06 |    0.1% |     13.69 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_true_and_all_conditions_false__1000`
	|    44.7% |            2,166.94 |          461,480.64 |    0.1% |      2.64 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_false_and_all_conditions_false__1000`
	|     8.6% |           11,313.16 |           88,392.63 |    0.1% |     13.93 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_true_and_no_conditions__1000`
	|    48.1% |            2,016.07 |          496,013.86 |    3.5% |      2.70 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_false_and_no_conditions__1000`

	|   100.0% |      112,998,500.00 |                8.85 |    3.2% |      1.23 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__empty_method__100000000`
	|   116.3% |       97,156,100.00 |               10.29 |    1.2% |      1.08 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__all_conditions_false__100000000`
	|    76.5% |      147,661,400.00 |                6.77 |    0.5% |      1.62 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_false_and_all_conditions_false_pre_edge_case_checking__100000000`
	|    52.4% |      215,809,600.00 |                4.63 |    0.1% |      2.38 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_false_and_all_conditions_false_post_edge_case_checking__100000000`
	|    10.0% |    1,133,210,400.00 |                0.88 |    0.1% |     12.47 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_true_and_all_conditions_false__100000000`
	|    52.2% |      216,363,500.00 |                4.62 |    0.2% |      2.38 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_false_and_all_conditions_false__100000000`
	|    10.0% |    1,132,939,200.00 |                0.88 |    0.2% |     12.51 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_true_and_no_conditions__100000000`
	|    58.8% |      192,015,700.00 |                5.21 |    0.1% |      2.12 | `BoostMutexLockAndDefensiveProgrammingRuntimePerformance__mutex_false_and_no_conditions__100000000`
	
	About
	- Timestamp Created: 7:45 AM, January 31, 2026

	*/

	struct TestSubject2
	{
		bool
			condition_1 = true;

		bool
			condition_2 = false;

		bool
			condition_3 = false;

		bool
			condition_4 = false;

		bool get_conditions()
		{
			return
				condition_2 ||
				condition_3 ||
				condition_4;
		}

		bool get_conditions_false()
		{
			return
				!get_conditions();
		}
	};

	class TestSubject1
	{
	public:
		static TestSubject1
			singleton;

		boost::mutex
			mutex_1;

		TestSubject2
			configurations_1 =
				{ true, false, false, false };

		TestSubject2
			configurations_2 =
				{ false, false, false, false };

		void mutex_false_and_all_conditions_false_pre_edge_case_checking()
		{
			if (configurations_2.get_conditions_false())
			{
				return;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations_2.condition_1
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						mutex_1
					);
			}			
		}

		void mutex_false_and_all_conditions_false_post_edge_case_checking()
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations_2.condition_1
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						mutex_1
					);
			}

			if (configurations_2.get_conditions_false())
			{
				return;
			}
		}

		void mutex_true_and_all_conditions_false()
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations_1.condition_1
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						mutex_1
					);
			}

			if (configurations_1.get_conditions())
			{
				return;
			}
		}

		void mutex_false_and_all_conditions_false()
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations_2.condition_1
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						mutex_1
					);
			}

			if (configurations_2.get_conditions_false())
			{
				return;
			}
		}

		void mutex_true_and_no_conditions()
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations_1.condition_1
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						mutex_1
					);
			}
		}

		void mutex_false_and_no_conditions()
		{
			boost::unique_lock<boost::mutex>
				mutex_lock;
			if
			(
				configurations_2.condition_1
			)
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						mutex_1
					);
			}
		}

		void all_conditions_false()
		{		
			if (configurations_2.get_conditions_false())
			{
				return;
			}
		}

		void empty_method()
		{
			
		}
	};

	TestSubject1
		TestSubject1
			::singleton;

	void execute()
	{
		QLogicaeCppCore::RuntimeBenchmarkerTestSuite test_suite
		{
			.name = "BoostMutexLockAndDefensiveProgrammingRuntimePerformance",
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
					.epochs = 1,
					.iterations = 100000000
				},
			},
			.test_cases =
			{
				{
					.name = "empty_method",
					.callback = []() { TestSubject1::singleton.empty_method(); }
				},
				{
					.name = "all_conditions_false",
					.callback = []() { TestSubject1::singleton.all_conditions_false(); }
				},
				{
					.name = "mutex_false_and_all_conditions_false_pre_edge_case_checking",
					.callback = []() { TestSubject1::singleton.mutex_false_and_all_conditions_false_pre_edge_case_checking(); }
				},
				{
					.name = "mutex_false_and_all_conditions_false_post_edge_case_checking",
					.callback = []() { TestSubject1::singleton.mutex_false_and_all_conditions_false_post_edge_case_checking(); }
				},
				{
					.name = "mutex_true_and_all_conditions_false",
					.callback = []() { TestSubject1::singleton.mutex_true_and_all_conditions_false(); }
				},
				{
					.name = "mutex_false_and_all_conditions_false",
					.callback = []() { TestSubject1::singleton.mutex_false_and_all_conditions_false(); }
				},
				{
					.name = "mutex_true_and_no_conditions",
					.callback = []() { TestSubject1::singleton.mutex_true_and_no_conditions(); }
				},
				{
					.name = "mutex_false_and_no_conditions",
					.callback = []() { TestSubject1::singleton.mutex_false_and_no_conditions(); }
				},
			}
		};

		QLogicaeCppCore::RuntimeBenchmarker::singleton.execute(
			test_suite
		);

		bool exit_code;
		std::cin >> exit_code;
	}
}

int main(int argc, char** argv)
{
	BoostMutexLockAndDefensiveProgrammingRuntimePerformance::execute();

	return 0;
}

namespace QLogicaeCppCoreBenchmark
{

}

/*
ConfigurationsManager::singleton.setup<AbstractConfigurations>(
	AbstractConfigurations
	{
		.is_enabled = false
	}
);

std::cout << AbstractConfigurations::default_configurations.is_enabled << "\n";
*/

/*

AbstractConfigurations a;

	ImplementationConfigurations i;

	std::cout << a.is_enabled << " " << i.is_enabled << "\n";


class ConfigurationsManager
{
public:
	static ConfigurationsManager
		singleton;

	template <typename Type> void
		setup(
			const Type& configurations = {}
		);
};

ConfigurationsManager
	ConfigurationsManager::singleton;


template <typename Type>
void ConfigurationsManager::setup(
	const Type& configurations
)
{
	Type::default_configurations = configurations;
}



struct AbstractConfigurations
{
	bool is_enabled =
		default_configurations.is_enabled;

	static AbstractConfigurations
		default_configurations;
};

AbstractConfigurations
	AbstractConfigurations::default_configurations =
	{
		.is_enabled = true
	};


struct ImplementationConfigurations :
	AbstractConfigurations
{
	bool is_enabled =
		default_configurations.is_enabled;

	static ImplementationConfigurations
		default_configurations;
};

ImplementationConfigurations
	ImplementationConfigurations::default_configurations =
	{
		.is_enabled = false
	};

struct AbstractConfigurations
{
	bool is_enabled =
		default_configurations.is_enabled;

	static AbstractConfigurations
		default_configurations;
};

AbstractConfigurations
	AbstractConfigurations::default_configurations;


	AbstractConfigurations a;

	AbstractConfigurations::setup(a);

*/
